#ifndef __FILE_H__
#define __FILE_H__
#include <stdio.h>

#define FILENAMEDATA "in"
#define FILENAMEOPT  "out"


void start();
int  next();
void end();
FILE* FPW();

void getfromfile(char A[],char B[], int *n);

#endif