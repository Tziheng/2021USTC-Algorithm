#include "algorithm.h"

#include <stdlib.h>

long long value[65536];
int key[65536];
int value_max;
int N;
int d = 2;
long long min; 
/*
输入数据的总数
*/
int num(){
    return N;
}
/*
input:  i,j  (0 <= i < j <= n)
return: min cost of ( from A[i] to A[j] )
*/
long long *func(int i,int j){ 
    // visit value
    return value + (2*N-1-i)*i/2+j;
}
/*
input:  i,j  (0 <= i < j <= n)
return: 从A[i]到A[j],最后一次分割
*/
int * seq(int i,int j){
    return key + (2*N-1-i)*i/2+j;
}
/*
初始化
*/
void Initialization(int* A , int n){
    value_max = (n+1)*(n+2)/2 ;
    N = n+1;
    d = 2;
    for(int i = 0; i < value_max ; ++i )
        value[i] = key[i] = 0;
    for(int i = 0; i < N; ++i )
        *func(i,i) = A[i];
}

void Dynamic(int* A , int n){
    Initialization(A,n);
    while(d < N){
        for(int i = 0; i < N - d; ++i ){
            min = LLONG_MAX;
            for(int j = i + 1; j < i + d ; ++j){
                *func(i,i+d) = *func(i,j) + *func(j,i+d) + *func(i,i)* *func(j,j)* *func(i+d,i+d);
                if(*func(i,i+d) < min){
                    min = *func(i,i+d);
                    *seq(i,i+d) = j;
                }
            }
            *func(i,i+d) = min;
        }
        d++;
    }
}