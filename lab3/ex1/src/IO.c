#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "timing.h"
#include <limits.h>
#include "graph.h"
char fileName[32]; 
void start(){
    infp = fopen(FILENAME_INPUT, "r");
    outfp = fopen(FILENAME_OUTPUT, "r");
    timefp = fopen(FILENAME_TIME, "w");
    fp  = NULL;
}
int  next(){
    endTiming();
    fclose(fp);
    return !feof(infp);
}
void end() {
    fclose(infp);
    fclose(outfp);
    fclose(timefp);
}
void getFromFile(Graph* g,int *n) {
    fscanf(infp,"%s %d\n",fileName,n);
    fp = fopen(fileName,"r");
    for (int i = 0, temp; i < *n; ++i) 
        for(int j = 0 ; j < *n && fscanf(fp,"%d,",&temp) ; ++j)
            if(temp)
                addEdge(g,i,j,temp);
    fclose(fp);
    fscanf(outfp,"%s\n",fileName);
    fp = fopen(fileName,"w");
    startTiming();
}
void write2File(int n,int (*opt)(int end)){
    endTiming();
    fprintf(timefp,"%d\n",timeCost());
    
    extern int s[];
    extern int d[];
    for(int i = 1; i < n; ++i){
        if(d[i] > SHRT_MAX / 2) continue;
        fprintf(fp,"0,%d,%d;",i,d[i]);
        printf("0,%d,%d;",i,d[i]);
        int len = opt(i);
        while (len){
            fprintf(fp,"%d,",s[--len]);
            printf("%d,",s[len]);
        }
        fprintf(fp,"\n");
        printf("\n");
    }
    
}