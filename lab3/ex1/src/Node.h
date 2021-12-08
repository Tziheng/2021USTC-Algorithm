#ifndef __NODE_H__
#define __NODE_H__

#define NODEMAX 1024        // 结点最大值

typedef struct Node {
    int key;
    bool mark;
    int degree; // 度数(孩子数)
    struct Node* par, * child, * left, * right;
    //void* belonging;  // 该结点所在堆的指针
}Node;

Node* nodeinit(int key);
void nodefree(Node* x);
Node* node(int key);

#endif
