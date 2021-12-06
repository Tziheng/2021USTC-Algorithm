#include "main.h"
#include <stdio.h>
int main(){
    start();
    FibonacciHeap *H1 = new FibonacciHeap, * H2 = new FibonacciHeap;
    getFromFile(H1,5);
    getFromFile(H2,5);

    int key = H1->ExtractMin()->key;
    printf("\nmin = %d\n\n\n",key);

    H1->Print();

    key = H1->ExtractMin()->key;
    printf("min = %d\n",key);
    H1->Print();

    H1->Union(H2);
    H1->Print();

    key = H1->ExtractMin()->key;
    printf("min = %d\n",key);
    H1->Print();

    Node * x = nodeinit(1);
    H1->Insert(x);
    H1->Print();

    x = nodeinit(2);
    H1->Insert(x);
    H1->Print();

    key = H1->ExtractMin()->key;
    printf("min = %d\n",key);
    H1->Print();

    x->child->child->mark = true;
    H1->Delete(x->child->child->child);
    H1->Print();

    printf("end");
    while(2);
    return 0;
}