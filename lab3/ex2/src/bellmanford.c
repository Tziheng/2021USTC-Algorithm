#include "graph.h"
#include <stdlib.h>


extern int d[MAX_V_NUM];    

extern Vertex* p[MAX_V_NUM];  

Graph * g;


extern  void relax(Vertex* Vu ,int u ,int v,int weight);
extern  void initialize_single_source(int n,int s);

int __BellmanFord__(int s,int (*w)(int,int)){
    initialize_single_source(g->VN,s);
    for(int i = 0 ; i  < g->VN - 1 ; ++i )
        for(int j = 0; j < g->EN;++j)
            relax(g->V + g->E[j].h,g->E[j].h,g->E[j].t,(*w)(g->E[j].h,g->E[j].t));
    for(int j = 0; j < g->EN; ++j)
        if(d[ g->E[j].t ] > d[ g->E[j].h ] + g->E[j].w)
            return 0;
    return 1;
}

int BellmanFord(Graph*G, int s,int (*func)(Graph *,int ,int )){
    int w(int u, int v){
        return (*func)(g,u,v);
    }
    g = G;
    __BellmanFord__(s,&w);
}
