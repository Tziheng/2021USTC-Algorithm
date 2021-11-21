#ifndef __ALGORITHN_H__
#define __ALGORITHN_H__
typedef struct OPT{
    long long m[16384];
    int s[16384];
    int N;
}OPT;
OPT Dynamic(int* A , int n );
long long *minc(int i,int j);
int * seq(int i,int j);
#endif