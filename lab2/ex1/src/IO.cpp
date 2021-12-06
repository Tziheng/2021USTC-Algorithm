#include "IO.h"
#include <stdio.h>
#include "file.h"

FILE * fp ;
void start(){
    fp = fopen(FILENAME_INPUT_DATA , "r");
}

void getFromFile(FibonacciHeap *H,int n){
    for(int i = 0; i < n; ++i){
        int key;
        fscanf(fp,"%d\n", &key);
        H->Insert(nodeinit(key));
    }
}
