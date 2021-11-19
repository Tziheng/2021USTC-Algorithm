#include "file.h"

FILE *fp,*fpw;

FILE * FPW() {
    return fpw;
}

void start(){
    fp = fopen(FILENAMEDATA,"r");
    fpw = fopen(FILENAMEOPT,"w");
}
void end(){
    fclose(fp);
    fclose(fpw);
}
int next(){
    return !feof(fp);  
}
void getfromfile(char A[],char B[], int *n){
    fscanf(fp,"%d\n%s %s",n,A,B);
}
