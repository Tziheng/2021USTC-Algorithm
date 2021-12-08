#include "Node.h"
#include "file.h"
Node* NODE[MAXNUM];
Node* nodeinit(int key) {
    NODE[key] = new Node;
    NODE[key]->key = key;
    return NODE[key];
}
Node* node(int key) {
    return NODE[key] ? NODE[key] : nodeinit(key);
}
void nodefree(Node* x) {
    NODE[x->key] = 0;
    delete x;
}
