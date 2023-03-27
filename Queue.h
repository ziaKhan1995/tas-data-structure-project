#pragma once
#include "Node.h"
#include "DataStructuresStudent.h"

#include <iostream>
using namespace std;

typedef DataStructuresStudent type;
class Queue
{
    Node<type *>* front, * back;
public:
    Queue();
    void setFront(Node<type*>* h);
    void setBack(Node<type*>* h);
    type* peek();
    type* Back();
    int count();
    bool isEmpty();
    void enqueue(type* n);
    type* dequeue();
    void traverse();
    friend ostream& operator<<(ostream& o, Queue s);
};
