#include "Node.h"
Node* NODE[NODEMAX];
Node* nodeinit(int key) {
    NODE[key] = new Node;
    NODE[key]->key = key;
    NODE[key]->child = 0;
    NODE[key]->degree = 0;
    return NODE[key];
}
Node* node(int key) {
    return NODE[key] ? NODE[key] : nodeinit(key);
}
void nodefree(Node* x) {
    NODE[x->key] = 0;
    delete x;
}
