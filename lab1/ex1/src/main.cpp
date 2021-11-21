#include "main.h"
int main(){
    int n, A[65536];
    start(); 
    while(next()){
        getFromFile(&n,&A);
//		for(int i = 0; i < 100000; i++)Dynamic(A,n);// 运行100000次
        prtToFile(Dynamic(A,n));
    }
    end();
    return 0;
}