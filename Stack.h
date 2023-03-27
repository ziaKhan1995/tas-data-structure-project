#pragma once
#include "Node.h"

#include <iostream>
using namespace std;

typedef int T;
class Stack
{
    Node<T> *top;
  public:
    Stack();
    void setTop(Node<T> *h);
    T Top();
    int count();
    bool isEmpty();
    void push(T n);
    T pop();  
    void traverse();
   friend ostream& operator<<(ostream& o, Stack s);
};
