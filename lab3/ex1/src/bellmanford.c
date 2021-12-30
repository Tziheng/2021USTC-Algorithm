#include "graph.h"
#include <limits.h>
#include <stddef.h>
#include <stdio.h>

int d[MAX_V_NUM];    

Vertex* p[MAX_V_NUM];  

Graph * g;

int __BellmanFord__(int s,int (*w)(int,int)){

    void relax(int u ,int v,int weight){
        if(d[v] > d[u] + weight){
            d[v] = d[u] + weight;
            p[v] = u + g->V;
        }
    }

    void initialize_single_source(int s){
        for(int i = 0; i < g->VN;++i){
            d[i] = SHRT_MAX;
            p[i] = NULL;
        }
        d[s] = 0;
    }

    initialize_single_source(s);
    for(int i = 0 ; i  < g->VN - 1 ; ++i )
        for(int j = 0; j < g->EN;++j)
            relax(g->E[j].h,g->E[j].t,(*w)(g->E[j].h,g->E[j].t));
    for(int j = 0; j < g->EN; ++j)
        if(d[ g->E[j].t ] > d[ g->E[j].h ] + g->E[j].w)
            return 0;
    return 1;
}

int BellmanFord(Graph*G, int s,int (*func)(Graph *g,int u,int v)){
    g = G;
    int w(int u, int v){
        return (*func)(g,u,v);
    }
    __BellmanFord__(s,&w);
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