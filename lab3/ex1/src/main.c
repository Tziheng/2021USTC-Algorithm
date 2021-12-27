#include "main.h"

int main(){
    Graph *g = 0;
    start();
    while (next()){
        g = creatGraph(g);
        getFromFile(g,&g->VN,&addEdge);
        BellmanFord(g,0);
        write2File(g->VN,&warFinding);
    }
    end();
    return 0;
}