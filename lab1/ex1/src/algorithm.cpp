#include "algorithm.h"
#include <stdlib.h>
OPT opt;
long long *minc(int i,int j){ 
    return opt.m + (2*opt.N-1-i)*i/2+j;
}
int * seq(int i,int j){
    return opt.s + (2*opt.N-1-i)*i/2+j;
}
void Initialization(int* A , int n){
    int value_max = (n+1)*(n+2)/2 ;
    opt.N = n+1;
    for(int i = 0; i < value_max ; ++i )
        opt.m[i] = opt.s[i] = 0;
    for(int i = 0; i < opt.N; ++i )
        *minc(i,i) = A[i];
}
OPT Dynamic(int* A , int n){
    Initialization(A,n);
    int d = 2;
    while(d < opt.N){
        for(int i = 0; i < opt.N - d; ++i ){
            long long min = LLONG_MAX;
            for(int j = i + 1; j < i + d ; ++j){
                *minc(i,i+d) = *minc(i,j) + *minc(j,i+d) + *minc(i,i)* *minc(j,j)* *minc(i+d,i+d);
                if(*minc(i,i+d) < min){
                    min = *minc(i,i+d);
                    *seq(i,i+d) = j;
                }
            }
            *minc(i,i+d) = min;
        }
        d++;
    }
    return opt;
}