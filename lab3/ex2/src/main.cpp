#include "main.h"
int main() {
    start();
    int relative[MAXNUM][MAXNUM]; // if a is b's relative,relative[a][b] is true
    int n;
    while (next(relative,&n))
        prtToFile(Algorithm(relative,n),n);
    end();
    return 0;
}