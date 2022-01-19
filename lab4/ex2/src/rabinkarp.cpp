#include <string.h>
#include "define.h"
#include "math.h"
#include <stdio.h>
OPT opt;

void RabinKarp(char T[], char P[],int d, int q){
    int n = strlen(T);
    int m = strlen(P);
    int h = 1; for(int i = 0; i < m-1;++i) h = h*d%q;   // h = d^m-1 mod q
    int p = 0;
    int t = 0;
    for(int i = 0; i < m; ++i){
        p = (d*p+P[i])%q;
        t = (d*t+T[i])%q;
    }
    for(int s = opt.f[opt.i] = opt.n = 0; s <= n-m; ++s){
        if(p == t){
            opt.f[opt.i]++;//命中
            if(!strncmp(P+0,T+s,m))
                opt.sta[opt.n++] = s + 1;   // 真命中
        }
        if(s < n-m){
            t = (d*(t-T[s]*h)+T[s+m]) % q;
            t = (t+q)%q;        // 加上这一行，使得t的值变为非负数
        }
    }
}