#ifndef __JOHNSON_H__
#define __JOHNSON_H__

extern int D[MAX_V_NUM][MAX_V_NUM];
extern Vertex* P[MAX_V_NUM][MAX_V_NUM];

void Johnson(Graph* G, int (*func)(Graph*, int, int));

#endif