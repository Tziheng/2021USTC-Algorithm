#include "main.h"
#include <stdio.h>

int main(){
    int n;
    char A[100];
    char B[100];
    start();
    while(next()){
        getfromfile(A,B,&n);
        printf("\nstart\n");
        Dynamic(A,n,B,n);
        printf("dynamic end\n");
        prtToFile();
    }
    end();
    while(1);
    return 0;
    
}