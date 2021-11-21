#include "main.h"
int main(){
    int n;
    int A[1024];
    start();
    while(next()){
    getFromFile(&n,&A);
    Dynamic(A,n);
    prtToFile();
    }
    end();
    return 0;

}