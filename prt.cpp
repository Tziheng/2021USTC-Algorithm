#include "prt.h"


void prt2src_s(char s[]){
    printf("%s\n", s);
}

void prt2file_s(char s[]){
    fprintf(FPW(),"%s\n", s);
}

void prt2src_d(int d){
    printf("%d\n", d);
}

void prt2file_d(int d){
    fprintf(FPW(),"%d\n", d);
}