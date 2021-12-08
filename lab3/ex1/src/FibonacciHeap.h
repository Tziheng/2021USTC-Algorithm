#ifndef __FIBONACCIHEAP_H__
#define __FIBONACCIHEAP_H__
#include "Node.h"
class FibonacciHeap {
private:
//内部参数
    int n;          // 总结点数
    int rootsize;   // 森林数(根结点数)
    Node* min;      // 最小值，一定在根上
//内部方法
    void Consolidte();
    void HeapLink(Node* y, Node* x);       // 将结点y作为x的子孩子(x.key <= y.key)
    Node* Link(Node* a, Node* b, Node* c); // 完成 b插入a,c中间，即 a.right = b = c.left 
    void cut(Node* x, Node* y);
    void cascadingCut(Node* y);
public:
    FibonacciHeap();// 构造函数，创建类时执行，用于初始化

/***** ADT操作 *****/

    /**
    *作用：插入一个结点
    *输入：插入结点地址
    *输出：结点个数
    *O(1)
    **/
    int Insert(Node* x);


    /**
    *作用：删除一个结点
    *输入：删除结点地址
    *输出：结点个数
    *O(1)
    **/
    int Delete(Node* x);


    /**
    *作用：输出最小值
    *输入：NULL
    *输出：最小值
    *O(1)
    **/
    int Minimum();


    /**
    *作用：提取最小值
    *输入：NULL
    *输出：最小值结点的地址
    *O(lgn)
    **/
    Node* ExtractMin();


    /**
    *作用：连接两个斐波那契堆
    *输入：另一个斐波那契堆H
    *输出：连接后的结点个数
    *O(1)
    *PS：采用Insert的时间复杂度为O(H.n)，直接连接为O(1)
    **/
    int Union(FibonacciHeap* H);


    /**
    *作用：关键字减值
    *输入：减值的结点，新值
    *输出：最小值
    *O(1)
    **/
    int DecreaseKey(Node* x, int key);
};



#endif