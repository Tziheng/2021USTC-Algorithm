#include "file.h"
#include "algorithm.h"
#include "string.h"

int main(){
    int n;
    char A[100];
    char B[100];
    start();
    while(next()){
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        getfromfile(A,B,&n);
        printf("\nstart\n");
        Dynamic(A,n,B,n);
        printf("dynamic end\n");
    }
    end();
    while(1);
    return 0;
    
}