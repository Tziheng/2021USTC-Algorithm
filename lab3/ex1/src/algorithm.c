#include "graph.h"
#include <stdlib.h>
#include <stdio.h>

unsigned int d[MAX_V_NUM];      // 距离
Vertex* p[MAX_V_NUM];           // 前驱
Graph * g;

int weight(int u,int v){
    for(int i = 0 ; i < g->V[u].degree; ++i)
        if(g->V[u].E[i]->t == g->V + v)
            return g->V[u].E[i]->w;
    return INT_MAX;
}
void initialize_single_source(int s){
    for(int i = 0; i < g->VN;++i){
        d[i] = INT_MAX;
        p[i] = NULL;
    }
    d[s] = 0;
}
void relax(Vertex* Vu , Vertex* Vv){
    int u = Vu - g->V,v = Vv - g->V,w;
    if(d[v] > d[u] + (w = weight(u,v))){
        d[v] = d[u] + w;
        p[v] = Vu;
    }
}

// 边的权重可以是负值，但不存在负环
int BellmanFord(Graph *GRAPH,int s){
    g = GRAPH;
    initialize_single_source(s);
    for(int i = 0 ; i  < g->VN - 1 ; ++i )
        for(int j = 0; j < g->EN;++j)
            relax(g->E[j].h,g->E[j].t);
    for(int j = 0; j < g->EN; ++j)
        if(d[g->E[j].t - g->V] > d[g->E[j].h - g->V] + g->E[j].w)
            return 0;
    return 1;
}
int s[MAX_V_NUM];
int warFinding(int end){  // from 0 to end,显然，我们只有前驱
    int temp = end,i = 0;
    while(temp){
        s[i++] = temp;
        temp = p[temp] - g->V;
    }
    s[i++] = temp;
    return i;
}