#include "main.h"
int main() {
    int n;
    char A[65536], B[65536];
    start();
    while (next()) {
        getFromFile(A, B, &n);
//        for(int i = 0; i < 100000; i++)Dynamic(A, n, B, n); // 运行100,000次
        prtToFile(Dynamic(A, n, B, n));
    }
    end();
    return 0;
}