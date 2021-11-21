#include <stdio.h>
#include "file.h"
#include "algorithm.h"
#include "time.h"

FILE *fp,*ofp,*mfp,*sfp,*tfp;

void start(){
    fp  = fopen(FILENAME_INPUT_DATA,"r");
    ofp = fopen(FILENAME_RESULT,"w");
    mfp = fopen(FILENAME_TABLE_M,"w");
    sfp = fopen(FILENAME_TABLR_S,"w");
    tfp = fopen(FILENAME_TIME,"w");
}
void end(){
    fclose(fp);
    fclose(ofp);
    fclose(mfp);
    fclose(sfp);
    fclose(tfp);
}
int next(){
    startTiming();
    return !feof(fp);  
}
void getFromFile(int *n,int (*A)[1024]){

    fscanf(fp,"%d",n);
    for(int i = 0; i <= *n ; ++i)
        fscanf(fp,"%d",*A + i);

}
void printOPTparens(int i,int j){
    if(i == j)
        fprintf(ofp,"A");
    else{
        fprintf(ofp,"(");
        printOPTparens(i,*seq(i-1,j));
        printOPTparens(*seq(i-1,j) + 1,j);
        fprintf(ofp,")");
    }
}

void prtToFile(){
//输出时间
    endTiming();
    fprintf(tfp,"%d\n",timeCost());
    int N = num();
//输出最小次数
    fprintf(ofp,"%lld\n",*func(0,N-1));
//输出表达式
    printOPTparens(1,N-1);
    fprintf(ofp,"\n");
//输出m表
    for(int i = N-1; i ;--i)
        fprintf(mfp,",%d",i);
    fprintf(mfp,"\n");
    for(int i = 0; i < N -1 ;++i){
        fprintf(mfp,"%d",i+1);
        for(int j = N-1; j > i ; --j)
            fprintf(mfp,",%lld",*func(i,j));   
        fprintf(mfp,"\n");
    }
//输出s表
    for(int i = N-2; i ;--i)
        fprintf(sfp,",%d",i);
    fprintf(sfp,"\n");
    for(int i = 0; i < N -2 ;++i){
        fprintf(sfp,"%d",i+1);
        for(int j = N-1; j > i + 1 ; --j)
            fprintf(sfp,",%d",*seq(i,j));   
        fprintf(sfp,"\n");
    }

}