#include "main.h"
int main(){
    start();
    while(next()){
        getFromFile();
        kmpMatcher(T,P);
        write2File();
    }
    end();
    return 0;
}