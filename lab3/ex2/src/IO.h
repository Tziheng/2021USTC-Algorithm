#ifndef __IO_H__
#define __IO_H__
void start();
int next(int (*r)[MAXNUM], int *n);
void end();
void getFromFile(int (*r)[MAXNUM], int *n);
void prtToFile(int rst, int n);
#endif