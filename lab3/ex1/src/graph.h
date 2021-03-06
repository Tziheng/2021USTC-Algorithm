#ifndef __GRAPH_H__
#define __GRAPH_H__

#define MAX_V_NUM 1024 // 顶点最大个数
#define MAX_DEGREE  5  // 顶点最大度数

typedef struct orientedEdge{
    int w;//weight
    int h;//head
    int t;//tail
}Edge;
typedef struct Vertex{
    int degree;//degree
    int E[MAX_DEGREE]; // 出边
}Vertex;
typedef struct sparseGraph{
    int VN;    // 总顶点个数
    int EN;    // 总边数
    Vertex V[MAX_V_NUM];
    Edge E[MAX_V_NUM * MAX_DEGREE];
}Graph;

Graph* creatGraph(Graph *g);
void addEdge(Graph *g,int head,int tail,int weight);
void printg(Graph *g);
int weight(Graph*g,int u,int v);
Graph * copyg(Graph *g);
#endif