#include "main.h"
int main(){
    Graph * g = NULL;
    start();
    while (next()){
        g = creatGraph(g);
        getFromFile(g,&g->VN);
        BellmanFord(g,0,&weight);
        printg(g);
        write2File(g->VN,&warFinding);
    }
    end();
    return 0;
}