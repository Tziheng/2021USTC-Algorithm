#include "graph.h"
#include <stdlib.h>

extern int d[MAX_V_NUM];
extern Vertex* p[MAX_V_NUM];

Graph* g;


int comp(const void* arg1, const void* arg2) {
    return d[*((int*)arg2)] - d[*((int*)arg1)];
}

int Q[MAX_V_NUM];

extern  void relax(Vertex* Vu, int u, int v, int weight);
extern  void initialize_single_source(int n, int s);

void __Dijkstra__(int s, int (*w)(int, int)) {

    initialize_single_source(g->VN, s);

    int Sn = 0, Qn = g->VN;

    for (int i = 0; i < Qn; ++i)
        Q[i] = i;

    while (Qn) {
        qsort(Q, Qn, sizeof(int), comp);
        int u = Q[--Qn];
        for (int i = 0; i < g->V[u].degree; ++i) {
            int v = g->E[g->V[u].E[i]].t;
            relax(g->V + u, u, v, (*w)(u, v));
        }
    }
}

int Dijkstra(Graph* G, int s, int (*func)(Graph*, int, int)) {
    int w(int u, int v) {
        return (*func)(g, u, v);
    }
    g = G;
    __Dijkstra__(s, &w);
}
