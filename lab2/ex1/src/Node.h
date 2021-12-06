#ifndef __NODE_H__
#define __NODE_H__

#define NODEMAX 1024        // 结点最大值

typedef struct Node{
    int key;
    bool mark;
    int degree; // 孩子数
    struct Node* par,*child,*left,*right;
    //void* belonging;  // 被分配的地址
}Node;

Node * nodeinit(int key);

void nodefree(Node * x);

Node * node(int key);

#endif
