#ifndef __NODE_H__
#define __NODE_H__
typedef struct Node{
    Node * par;
    int rank;
    int key;
}Node;
Node* nodeinit(int key);
void nodefree(Node* x);
Node* node(int key);

#endif
