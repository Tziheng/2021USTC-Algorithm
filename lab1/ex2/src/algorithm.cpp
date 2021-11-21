#include "algorithm.h"
OPT opt;
void Initialization(char* strX, int X_length, char* strY, int Y_length) {
    opt.x = X_length;
    opt.X = strX - 1;
    opt.y = Y_length;
    opt.Y = strY - 1;
    for (int i = 0; i <= opt.x; ++i) opt.c[i][0] = 0; 
    for (int j = 0; j <= opt.y; ++j) opt.c[0][j] = 0;
}
OPT Dynamic(char* strX, int X_length, char* strY, int Y_length) {
    Initialization(strX, X_length, strY, Y_length);
    for (int i = 1; i <= opt.x; ++i)
        for (int j = 1; j <= opt.y; ++j) 
            if (opt.X[i] == opt.Y[j]) {
                opt.c[i][j] = opt.c[i - 1][j - 1] + 1;
                opt.b[i][j] = 0;
            }
            else {
                opt.b[i][j] = 1;
                opt.c[i][j] = opt.c[i - 1][j] >= opt.c[i][j - 1] ? opt.c[i - 1][j] : opt.c[i][j - 1];
            }
    return opt;
}
