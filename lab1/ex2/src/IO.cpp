#include "file.h"
#include "time.h"
#include "algorithm.h"
#include <stdio.h>

FILE *fp,*ofp,*tfp;

int (*ct)[1024],xt,yt; 
char (*bt)[1024],*Xt,*Yt;

void start(){
    fp = fopen(FILENAME_INPUT_DATA,"r");
    ofp = fopen(FILENAME_RESULT,"w");
    tfp = fopen(FILENAME_TIME,"w");
}
void end(){
    fclose(fp);
    fclose(ofp);
    fclose(tfp);
}
int next(){
    startTiming();
    return !feof(fp);  
}
void getfromfile(char A[],char B[], int *n){
    fscanf(fp,"%d\n%s\n%s",n,A,B);
}
char o[1024];
int sum;
void DFS(int m,int n){
    if(ct[m][n] == 0){
        fprintf(ofp,"%s\n",o+1);
        sum ++;
        return;
    }
    int t = ct[m][n];
    while(ct[m][n] == t && t > 0){
        for(int i = n; ct[m][i] == t ; --i){
            if(bt[m][i] == 0){
                o[t] = Xt[m];
                DFS(m-1,i-1);
            }
        }
        m--;
    }
}
void prtToFile(){
//输出时间
    endTiming();
    fprintf(tfp,"%d\n",timeCost());

    deliver(&xt,&yt,&ct,&bt,&Xt,&Yt);

//输出最长子序列的序列长度
    fprintf(ofp,"%d\n",ct[xt][yt]);
//输入最长子序列数目
    sum = 0;
    int loc = ftell(ofp);
    fprintf(ofp,"%-8d\n",0);
    DFS(xt,yt); // 输出所有子序列
    fseek(ofp,loc,SEEK_SET);
    fprintf(ofp,"%-8d",sum);
    fseek(ofp,0,SEEK_END);


} 
