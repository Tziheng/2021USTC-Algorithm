#include "graph.h"
#include "bellmanford.h"
#include "dijkstra.h"
#include <stdlib.h>

int d[MAX_V_NUM];
Vertex* p[MAX_V_NUM];
void relax(Vertex* Vu, int u, int v, int weight) {
    if (d[v] > d[u] + weight) {
        d[v] = d[u] + weight;
        p[v] = Vu;
    }
}
void initialize_single_source(int n, int s) {
    for (int i = 0; i < n;++i) {
        d[i] = SHRT_MAX;
        p[i] = NULL;
    }
    d[s] = 0;
}

Graph* g, * g1;

int D[MAX_V_NUM][MAX_V_NUM];
Vertex* P[MAX_V_NUM][MAX_V_NUM];

int h[MAX_V_NUM];
int w_(Graph* g, int u, int v) {
    return weight(g, u, v) + h[u] - h[v];
}
void __Johnson__(int (*w)(int, int)) {
    g1 = copyg(g);

    int s = g1->VN++;// 新加入一个点s
    g1->V[s].degree = 0;
    for (int i = 0; i < s; ++i)
        addEdge(g1, s, i, 0);
    if (!BellmanFord(g1, s, &weight)) 
        exit(0);
    

    BellmanFord(g1, s, &weight);
    for (int i = 0; i < g1->VN; ++i)
        h[i] = d[i];

    for (int u = 0; u < g->VN; ++u) {
        Dijkstra(g, u, &w_);
        for (int v = 0; v < g->VN; ++v)
            D[u][v] = d[v] + h[v] - h[u];
    }
}

void Johnson(Graph* G, int (*func)(Graph*, int, int)) {
    int w(int u, int v) {
        return (*func)(g, u, v);
    }
    g = G;
    __Johnson__(&w);
}
