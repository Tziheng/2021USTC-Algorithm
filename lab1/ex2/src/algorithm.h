#ifndef __ALGORITHN_H__
#define __ALGORITHN_H__
typedef struct OPT {
    int c[128][128]; 
    char b[128][128];
    int x, y;
    char* X, * Y;
}OPT;
OPT Dynamic(char* strX, int X_length, char* strY, int Y_length);
#endif