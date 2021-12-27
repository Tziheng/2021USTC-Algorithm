#ifndef __IO_H__
#define __IO_H__
void start();
int  next();
void end();
void getFromFile(void* g, int * num,void (* opt)(void*,int,int,int));
void write2File(int n,int (*opt)(int end));
#endif