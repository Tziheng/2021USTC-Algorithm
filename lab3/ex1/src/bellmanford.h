#ifndef __BELLMANFORD_H__
#define __BELLMANFORD_H__

extern int d[MAX_V_NUM];    
extern Vertex* p[MAX_V_NUM];  

int BellmanFord(Graph*G, int s,int (*w)(Graph *g,int u,int v));

#endif