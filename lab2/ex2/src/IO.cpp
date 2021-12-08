#include <stdio.h>
#include "file.h"
#include "timing.h"
FILE* fp, * ofp, * tfp, *fp2;
void getFromFile(int (*r)[MAXNUM], int *n) {
    fscanf(fp2,"%d\n",n);
    for(int i = 0; i < *n ; ++i)
        for(int j = 0; j < *n ;++j)
            fscanf(fp,"%d",r[i]+j);
}
void start() {
    fp = fopen(FILENAME_INPUT_DATA, "r");
    fp2 = fopen(FILENAME_INPUT_N, "r");
    ofp = fopen(FILENAME_RESULT, "w");
    tfp = fopen(FILENAME_TIME, "w");
    startTiming();
}
int next(int (*r)[MAXNUM], int *n){
    if(feof(fp)) return 0;
    getFromFile(r,n);
    startTiming();
    return 1;
}
void end() {
    fclose(fp);
    fclose(fp2);
    fclose(ofp);
    fclose(tfp);
}
void prtToFile(int rst, int n) {
    endTiming();
    fprintf(tfp,"n=%d %d\n",n,timeCost());
    fprintf(ofp,"n=%d %d\n",n,rst);
}
