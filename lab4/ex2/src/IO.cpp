#include <stdio.h>
#include <string.h>
#include "define.h"
#include "timing.h"
#include "str.h"

FILE* infp, * outfp, * timefp, * dqfp;

void start(){
    infp = fopen(FILENAME_INPUT, "r");
    outfp = fopen(FILENAME_OUTPUT, "w");
    timefp = fopen(FILENAME_TIME, "w");
    dqfp  = fopen(FILENAME_DQ,"r");
    for(int i = 0 ; i < 4; ++i) fscanf(dqfp,"%d %d\n",i+d,i+q);
    fclose(dqfp);
}
int  next(){
    return !feof(infp);
}
void end() {
    fclose(infp);
    fclose(outfp);
    fclose(timefp);
}
void getFromFile() {
    fgets(P,PMAX,infp);P[strlen(P)-1] = '\0'; 
    fgets(T,TMAX,infp);T[strlen(T)-1] = '\0';
    startTiming();
}
void write2File(){
    endTiming();
    fprintf(timefp,"%d\n",timeCost());
    fprintf(outfp,"%d\n",opt.n);               // 匹配次数
    for(int i = 0 ; i < opt.i ; ++i) fprintf(outfp,"%d ",opt.f[i]-opt.n);fprintf(outfp,"\n"); // 伪命中次数
    for(int i = 0 ; i < opt.n ; ++i) fprintf(outfp,"%d ",opt.sta[i]);fprintf(outfp,"\n");    // start location
    fprintf(outfp,"\n");
}