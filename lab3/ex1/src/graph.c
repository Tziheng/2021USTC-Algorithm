#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
Graph* creatGraph(Graph *g){
    if(!g)
        g = (Graph * )malloc(sizeof(Graph));
    g->VN = 0;
    g->EN = 0;
    for(int i = 0 ; i < MAX_V_NUM ; ++i) g->V[i].degree = 0;
    return g;
}
void addEdge(void * vg,int head,int tail,int weight){// add an Edge that is not in graph
    Graph * g = (Graph*)vg;
    Edge * e = g->E + g->EN++;
    g->V[head].E[g->V[head].degree++] = e;
    e->h = g->V + head;
    e->t = g->V + tail;
    e->w = weight;
}
void printg(Graph *g){
    printf("graph: V num:%d\tE num:%d\n",g->VN,g->EN);
    for(int i = 0; i <g->VN ; ++i){
        printf("V:%3d degree:%d:",i,g->V[i].degree);
        for(int j = 0; j < g->V[i].degree;++j)
            printf("%4d,w:%5d\t",g->V[i].E[j]->t - g->V,g->V[i].E[j]->w);
        printf("\n");
    }
}
