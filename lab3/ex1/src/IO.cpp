#include <stdio.h>
#include "file.h"
#include "timing.h"
#include "FibonacciHeap.h"
FILE* fp, * ofp, * tfp;
int* o;
void start(int* key) {
    o = key;
    fp = fopen(FILENAME_INPUT_DATA, "r");
    ofp = fopen(FILENAME_RESULT, "w");
    tfp = fopen(FILENAME_TIME, "w");
    startTiming();
}
void next(bool outputTime, bool outputRst) {
    endTiming();
    if(outputRst){
        for (int i = 0 ; i < 10 ; ++i) 
            fprintf(ofp,"%d,",o[i]);
        fprintf(ofp,"\n");
    }
    if(outputTime) fprintf(tfp,"%d\n",timeCost());
    startTiming();
}
void end() {
    fclose(fp);
    fclose(ofp);
    fclose(tfp);
}
void getFromFile(void* H, int n) {
    for (int i = 0; i < n; ++i) {
        int key;
        fscanf(fp, "%d\n", &key);
        ((FibonacciHeap*)H)->Insert(nodeinit(key));
    }
}
