#include "graph.h"
#include <stdlib.h>

Graph* creatGraph(Graph* g) {
    if (!g)
        g = (Graph*)malloc(sizeof(Graph));
    g->VN = g->EN = 0;
    for (int i = 0; i < MAX_V_NUM; ++i) g->V[i].degree = 0;
    return g;
}
void addEdge(Graph* g, int head, int tail, int weight) {// add an Edge that is not in graph
    Edge* e = g->E + g->EN;
    g->V[head].E[g->V[head].degree++] = g->EN++;
    e->h = head;
    e->t = tail;
    e->w = weight;
}

int weight(Graph* g, int u, int v) {
    for (int i = 0; i < g->V[u].degree; ++i)
        if (g->E[g->V[u].E[i]].t == v)
            return g->E[g->V[u].E[i]].w;
    return SHRT_MAX;
}
Graph* copyg(Graph* g) {
    Graph* temp = (Graph*)malloc(sizeof(Graph));
    *temp = *g;
    return temp;
}
/*
void printg(Graph* g) {
    printf("graph: V num:%d\tE num:%d\n", g->VN, g->EN);
    for (int i = 0; i < g->VN; ++i) {
        printf("V:%3d degree:%d:", i, g->V[i].degree);
        for (int j = 0; j < g->V[i].degree;++j)
            printf("%4d,w:%5d\t", g->E[g->V[i].E[j]].t, g->E[g->V[i].E[j]].w);
        printf("\n");
    }
}
*/