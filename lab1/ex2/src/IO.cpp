#include <stdio.h>
#include "file.h"
#include "algorithm.h"
#include "timing.h"
FILE* fp, * ofp, * tfp;
void start() {
    fp = fopen(FILENAME_INPUT_DATA, "r");
    ofp = fopen(FILENAME_RESULT, "w");
    tfp = fopen(FILENAME_TIME, "w");
}
void end() {
    fclose(fp);
    fclose(ofp);
    fclose(tfp);
}
int next() {
    startTiming();
    return !feof(fp);
}
void getFromFile(char A[], char B[], int* n) {
    fscanf(fp, "%d\n%s\n%s", n, A, B);
}
char o[1024];
int sum;
void DFS(int m, int n, OPT opt) {
    if (opt.c[m][n] == 0) {
        fprintf(ofp, "%s\n", o + 1);
        sum++;
        return;
    }
    int t = opt.c[m][n];
    while (opt.c[m][n] == t && t > 0) {
        for (int i = n; opt.c[m][i] == t; --i)
            if (opt.b[m][i] == 0) {
                o[t] = opt.X[m];
                DFS(m - 1, i - 1, opt);
            }
        m--;
    }
}
void prtToFile(OPT opt) {
    endTiming();
    fprintf(tfp, "%d\n", timeCost());    //输出时间
    fprintf(ofp, "%d\n", opt.c[opt.x][opt.y]);    //输出最长子序列的序列长度
    sum = 0;
    int loc = ftell(ofp); 
    fprintf(ofp, "%-8d\n", 0);
    o[opt.c[opt.x][opt.y] + 1] = 0;
    DFS(opt.x, opt.y, opt);    // 输出所有子序列
    fseek(ofp, loc, SEEK_SET);
    fprintf(ofp, "%-8d", sum);    // 输出数目
    fseek(ofp, 0, SEEK_END);
}