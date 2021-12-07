#include "FibonacciHeap.h"
FibonacciHeap::FibonacciHeap() {
    min = 0;
    n = rootsize = 0;
}
Node* FibonacciHeap::Link(Node* a, Node* b, Node* c) {
    if (a && b)(a->right = b)->left = a;  // link a&b
    if (c && b)(c->left = b)->right = c;  // link b&c
    else if (a && c)(a->right = c)->left = a;  // link a&c
    return c ? c : b ? b : a ? a : 0;    // 返回 abc中最右边一个(非空)
}
int FibonacciHeap::Insert(Node* x) {
    rootsize++;n++;
    if (!min)
        min = x->left = x->right = x;
    else {
        Link(min->left, x, min);
        x->key < min->key ? min = x : 0;
    }
    x->par = 0;
    x->mark = false;
    n += x->degree;
    return n;
}
int FibonacciHeap::Delete(Node* x) {
    DecreaseKey(x, 0);
    ExtractMin();
    nodefree(x);
    return n;
}
int FibonacciHeap::Minimum() {
    return min->key;
}
int FibonacciHeap::Union(FibonacciHeap* H2) {
    if (!H2 || !H2->n) return n;
    Link(min->left, H2->min->right, 0);
    Link(H2->min, min, 0);
    min = min->key < H2->min->key ? min : H2->min;
    n += H2->n;
    rootsize += H2->rootsize;
    delete H2;
    return n;
}
Node* FibonacciHeap::ExtractMin() {
    if (!n) return 0;
    n--; rootsize--;
    Node* z = min; min = 0; // 提取min
    if (!n) return z;
    z->child ? rootsize ? Link(z->left, z->child->right, 0), Link(0, z->child, z->right) : 0 : Link(z->left, z->right, 0);
    min = z->child ? z->child : z->right; // min指向根链表上的一个结点(未必最小，将在Consolidte更新)
    rootsize += z->degree;
    Consolidte();
    z->child = z->par = z->left = z->right = 0;
    z->degree = 0;
    return z;
}
void FibonacciHeap::HeapLink(Node* y, Node* x) {
    Node* child = x->child;
    Link(y->left, y->right, 0);   //维护root中的left right
    (x->child = y)->par = x;       //更新父子
    child ? Link(child->left, y, child) : Link(y, y, 0);
    x->degree++;
    y->mark = false;
}
Node* A[NODEMAX];
void FibonacciHeap::Consolidte() {
    int degree = n, d;
    Node* j = min, * x, * y, * z;
    for (int i = 0; i < degree; A[i++] = 0);// 初始化A[i]
    for (int i = 0; i < rootsize; ++i) {
        x = j;
        j = j->left;
        while (y = A[d = x->degree]) {
            x->key > y->key ? (z = x, x = y, y = z) : 0; // 确保 x < y
            HeapLink(y, x);
            A[d] = 0;
        }
        A[d] = x;
    }
    min = 0;//重构rootlink和min
    for (int i = rootsize = 0; i < degree; ++i)
        if (A[i]) {
            A[i]->par = 0;
            rootsize++;
            if (!min)
                min->left = min->right = min = A[i];//维护left right,初始化min
            else {
                Link(min->left, A[i], min);//维护left right
                A[i]->key < min->key ? min = A[i] : 0; //更新最小值
            }
        }
}
void FibonacciHeap::cut(Node* x, Node* y) {
    y->degree--;
    x->par = 0;
    y->child = y->degree ? Link(x->left, 0, x->right) : 0;
    Link(min->left, x, min);
    rootsize++;
    x->mark = false;
}
void FibonacciHeap::cascadingCut(Node* y) {
    if (Node* z = y->par)
        y->mark ? cut(y, z), cascadingCut(z) : void(y->mark = true);
}
int FibonacciHeap::DecreaseKey(Node* x, int key) {
    if (x->key <= key)
        return min->key;// error
    x->key = key;
    Node* y = x->par;
    y&& x->key < y->key ? cut(x, y), cascadingCut(y) : (void)0;
    x->key < min->key ? min = x : 0;
    return min->key;
}


/*
void FibonacciHeap::Print() {
    if (n < 1) return;
    printf("%d:\n", n);
    Node* T[NODEMAX], * child = min, * i;
    int level[NODEMAX];
    int T_size = 0;
    i = child->left;
    for (int j = 0; j < rootsize; ++j) {
        T[T_size] = i;
        level[T_size] = 0;
        T_size++;
        i = i->left;
    }
    while (T_size) {
        T_size--;
        for (int j = 0; j < level[T_size]; printf("-"), ++j);
        printf("%d\t", T[T_size]->key);
        T[T_size]->mark ? printf("true\n") : printf("false\n");
        if (child = T[T_size]->child) {
            i = child->left;
            int degree = T[T_size]->degree;
            int t = level[T_size] + 1;
            for (int j = 0; j < degree;++j) {
                T[T_size] = i;
                level[T_size] = t;
                i = i->left;
                T_size++;
            }
        }
    }
}
*/