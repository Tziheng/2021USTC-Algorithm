#ifndef __IO_H__
#define __IO_H__
void start(int* key);
void next(bool outputTime, bool outputRst);
void end();
void getFromFile(void* H, int n);
#endif