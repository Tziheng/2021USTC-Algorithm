#include "main.h"
int main() {
    Graph* g = NULL;
    start();
    while (next()) {
        g = creatGraph(g);
        getFromFile(g, &g->VN);
        Johnson(g, &weight);
        write2File(g->VN);
    }
    end();
    return 0;
}