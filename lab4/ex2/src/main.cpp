#include "main.h"
int main(){
    start();
    while(next()){
        getFromFile();
        for(opt.i = 0; opt.i < 4; ++opt.i)
            RabinKarp(T,P,d[opt.i],q[opt.i]);
        write2File();
    }
    end();
    return 0;
}