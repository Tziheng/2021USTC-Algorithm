#include "set.h"
void MakeSet(Node *x){
    x->par = x;
    x->rank = 0;
}
void Union(Node * x , Node *y){
    Link(FindSet(x) , FindSet(y));
}
void Link(Node * x , Node * y){
    if(x->rank > y->rank)
        y->par = x;
    else{
        x->par = y;
        if(x->rank == y->rank)
            y->rank ++;
        }
}
Node* FindSet(Node * x){
    if(x != x->par)
        x->par = FindSet(x->par);
    return x->par;
}
