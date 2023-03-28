#include "Node.h"

#include "Stack.h"

#include <iostream>

#include <string>

using namespace std;

typedef int T;

Stack::Stack() {
  top = NULL;
}
void Stack::setTop(Node < T > * h) {
  top = h;
}
T Stack::Top() {
  return top -> data;
}
bool Stack::isEmpty() {
  return (top == NULL);
}
int Stack::count() {
  Node < T > * temp;
  temp = top;
  int c = 0;
  while (temp != NULL) {
    c++;
    temp = temp -> next;
  }
  return c;
}
void Stack::push(T n) {
  Node < T > * New = new Node < int > (n);
  if (top != NULL) New -> next = top;
  top = New;
}
T Stack::pop() {
  Node < T > * result;
  result = top;
  T data = top -> data;
  top = top -> next;
  delete result;
  return data;
}
void Stack::traverse() {
  Node < T > * temp = top;
  while (temp != NULL) {
    cout << temp -> data << " ";
    temp = temp -> next;
  }
}
ostream & operator << (ostream & o, Stack s) {
  s.traverse();
  return o;
}
