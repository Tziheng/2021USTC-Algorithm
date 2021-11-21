#include <stdio.h>
#include "file.h"
#include "algorithm.h"
#include "timing.h"
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
void getFromFile(int *n,int (*A)[65536]){
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
void prtToFile(OPT opt){
//输出时间
    endTiming();
    fprintf(tfp,"%d\n",timeCost());
//输出最小次数
    fprintf(ofp,"%lld\n",*minc(0,opt.N-1));
//输出表达式
    printOPTparens(1,opt.N-1);
    fprintf(ofp,"\n");
//输出m表
    for(int i = opt.N-1; i ;--i)
        fprintf(mfp,",%d",i);
    fprintf(mfp,"\n");
    for(int i = 0; i < opt.N -1 ;++i){
        fprintf(mfp,"%d",i+1);
        for(int j = opt.N-1; j > i ; --j)
            fprintf(mfp,",%lld",*minc(i,j));   
        fprintf(mfp,"\n");
    }
//输出s表
    for(int i = opt.N-1; i>1 ;--i)
        fprintf(sfp,",%d",i);
    fprintf(sfp,"\n");
    for(int i = 0; i < opt.N -2 ;++i){
        fprintf(sfp,"%d",i+1);
        for(int j = opt.N-1; j > i + 1 ; --j)
            fprintf(sfp,",%d",*seq(i,j));   
        fprintf(sfp,"\n");
    }
}