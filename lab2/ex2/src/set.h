#ifndef __SET_H__
#define __SET_H__
#include "Node.h"
void MakeSet(Node *x);
void Union(Node * x , Node *y);
void Link(Node * x , Node * y);
Node* FindSet(Node * x);
#endif