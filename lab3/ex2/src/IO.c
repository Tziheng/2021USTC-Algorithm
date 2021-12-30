#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "timing.h"
#include "graph.h"
#include "johnson.h"

char fileName[32];
void start() {
    infp = fopen(FILENAME_INPUT, "r");
    outfp = fopen(FILENAME_OUTPUT, "r");
    timefp = fopen(FILENAME_TIME, "w");
    fp = NULL;
}
int  next() {
    fclose(fp);
    return !feof(infp);
}
void end() {
    fclose(infp);
    fclose(outfp);
    fclose(timefp);
}
void getFromFile(Graph* g, int* n) {
    fscanf(infp, "%s %d\n", fileName, n);
    fp = fopen(fileName, "r");
    for (int i = 0, temp; i < *n; ++i)
        for (int j = 0; j < *n && fscanf(fp, "%d,", &temp); ++j)
            if (temp)
                addEdge(g, i, j, temp);
    fclose(fp);
    fscanf(outfp, "%s\n", fileName);
    fp = fopen(fileName, "w");
    startTiming();
}
void write2File(int n) {
    endTiming();
    fprintf(timefp, "%d\n", timeCost());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n;++j)
            if (D[i][j] > SHRT_MAX / 2)
                fprintf(fp, "X,");
            else
                fprintf(fp, "%d,", D[i][j]);
        fprintf(fp, "\n");
    }

}