#include<string.h>
#include "define.h"


OPT opt;

int *pi = opt.pi ;


int *computePrefixFunction(char p[]){
    int m = strlen(p);
    pi[0] = 0;
    int k = 0;
    for(int q = 1; q < m; q++){
        while (k > 0 && p[k] != p[q])
            k = pi[k-1];
        if(p[k] == p[q])
            k++;
        pi[q] = k;
    }
    return pi;
}

void kmpMatcher(char t[], char p[]){
    int n = strlen(t);
    int m = strlen(p);
    computePrefixFunction(p);
    int q = 0;
    for(int i = opt.n = 0; i < n; ++i){
        while (q > 0 && p[q] != t[i])
            q = pi[q-1];
        if(p[q] == t[i])
            q++;
        if(q == m) {
            opt.sta[opt.n++] = i - m + 2;   // 记录第n个匹配成功的位置
            q = pi[q-1];
        }
    }
}