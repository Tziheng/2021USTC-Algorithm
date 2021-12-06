#include "FibonacciHeap.h"
#include <stdio.h>
FibonacciHeap::FibonacciHeap(){
    min = NULL;
    n = rootsize = 0;
    printf("success!\n");
}
Node* FibonacciHeap::Link(Node* a, Node *b, Node *c){
     if(a && b)(a->right = b)->left  = a;  // link a&b
     if(c && b)(c->left  = b)->right = c;  // link b&c
else if(a && c)(a->right = c)->left  = a;  // link a&c
    return a?a:b?b:c?c:NULL;    // 返回 abc中最左边一个(非空)
}
int FibonacciHeap::Insert(Node* x){
    rootsize++;n++;
    if(!min)
        min = x->left = x->right = x;
    else{
        Link(min->left,x,min); // 维护left right
        x->key < min->key ? min = x : NULL; 
    }
    x->mark = false;
    n += x->degree;
    return n;
}
int FibonacciHeap::Delete(Node * x){
    DecreaseKey(x,0);
    ExtractMin();
    nodefree(x);
    return n;
}
int FibonacciHeap::Minimum(){
    return min->key;
}
int FibonacciHeap::Union(FibonacciHeap* H2){
    if(!H2 || !H2->n) return n;
    Link(min->left,H2->min->right,NULL);Link(NULL,H2->min,min);
    min = min->key < H2->min->key ? min : H2->min; 
    n += H2->n;
    rootsize += H2->rootsize;
    return n;
}
Node *FibonacciHeap::ExtractMin(){
    if(!n) return NULL;
    n--; rootsize--;
    Node * z = min; min = NULL; // 提取min
    if(!n) return z;
    if(z->child)
        rootsize ? Link(z->left,z->child->right,NULL),Link(NULL,z->child,z->right) : NULL; // 将孩子接在root
    else
        Link(z->left,NULL,z->right);
    min = z->child ? z->child : z->right; // min指向根链表上的一个结点(未必最小，将在Consolidte更新)
    rootsize += z->degree;
    Consolidte();
    z->child = z->par = z->left = z->right = NULL;z->degree = 0;
    return z;
}
void FibonacciHeap::HeapLink(Node* y, Node* x){
    Node * child = x->child;
    Link(y->left,NULL,y->right);   //维护root中的left right
    (x->child = y)->par = x;       //更新父子
    if(!child)
        y->left = y->right = y;    //维护y的left right
    else
        Link(child->left,y,child); //维护y的left right
    x->degree++;
    y->mark = false;
}
Node *A[NODEMAX];
void FibonacciHeap::Consolidte(){
    int degree = n, d;
    Node* j = min , *x,*y,*z;
    for(int i = 0 ; i < degree ; A[i++] = NULL);// 初始化A[i]
    for(int i = 0; i < rootsize ; ++i){
        x = j;
        j = j->left;
        while(y = A[d = x->degree]){
            x->key > y->key ? ( z = x,x = y,y = z) : NULL; // 确保 x < y
            HeapLink(y,x);
            A[d] = NULL;
        }
        A[d] = x;
    }
    min = NULL;//重构rootlink和min
    for(int i = rootsize = 0; i < degree ; ++i)
        if(A[i]){
            A[i]->par = NULL;
            rootsize++;
            if(!min)
                min->left = min->right = min = A[i];//维护left right,初始化min
            else{
                Link(min->left,A[i],min);//维护left right
                A[i]->key < min->key ? min = A[i] : NULL ; //更新最小值
            }
        }
}
void FibonacciHeap::cut(Node* x,Node *y){
    y->degree--;
    x->par = NULL;
    if(y->degree)//剔除孩子
        y->child = Link(x->left,NULL,x->right);
    else
        y->child = NULL;
    Link(min->left,x,min);
    rootsize++;
    x->mark = false;
}
void FibonacciHeap::cascadingCut(Node *y){
    Node * z = y->par;
    if(z)
        if(!y->mark) y->mark = true;
        else cut(y,z),cascadingCut(z);
}
int FibonacciHeap::DecreaseKey(Node * x, int key){
    if(x->key <= key) return min->key;// error
    x->key = key;
    Node* y = x->par;
    if(y && x->key < y->key){
        cut(x,y);
        cascadingCut(y);
    }
    x->key < min->key ? min = x:NULL;
    return min->key;
}



void FibonacciHeap::Print(){
    if(n < 1) return;
    printf("%d:\n",n);
    Node* T[NODEMAX],*child = min,*i;
    int level[NODEMAX];
    int T_size = 0;
    i = child->left;
    for(int j = 0; j < rootsize; ++j ){
        T[T_size] = i;
        level[T_size] = 0;
        T_size ++ ;
        i = i->left;
    }
    while( T_size ){
        T_size--;
        for(int j = 0; j <level[T_size] ; ++j)printf("-");
        printf("%d\t",T[T_size]->key);
        T[T_size]->mark?printf("true\n"):printf("false\n");
        if(child = T[T_size]->child){
            i = child->left;
            int degree = T[T_size]->degree;
            int t = level[T_size] + 1;
            for(int j = 0; j <degree;++j ){
                T[T_size] = i;
                level[T_size] = t;
                i = i->left;
                T_size++;
            }
        }
    }
}
