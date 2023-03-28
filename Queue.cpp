#include "Queue.h"

#include "DataStructuresStudent.h"

#include "Node.h"

#include "Queue.h"

#include <iostream>

#include <string>

using namespace std;

typedef DataStructuresStudent type;
Queue::Queue() {
  front = back = NULL;
}
void Queue::setFront(Node < type * > * h) {
  front = h;
}
void Queue::setBack(Node < type * > * h) {
  back = h;
}
type * Queue::peek() {
  return front -> data;
}
type * Queue::Back() {
  return back -> data;
}
int Queue::count() {
  Node < type * > * temp = front;
  int c = 0;
  while (temp != NULL) {
    c++;
    temp = temp -> next;
  }
  return c;
}
bool Queue::isEmpty() {
  return ((front == NULL) && (back == NULL));
}
void Queue::enqueue(type * n) {
  Node < type * > * temp = new Node < type * > (n);
  if (isEmpty()) front = back = temp;
  else {
    back -> next = temp;
    back = temp;
  }
}
type * Queue::dequeue() {
  Node < type * > * result;
  result = front;
  type * data = front -> data;
  if (count() == 1) back = back -> next;
  front = front -> next;
  delete result;
  return data;
}
void Queue::traverse() {
  Node < type * > * temp = front;
  while (temp != NULL) {
    cout << * temp -> data << "\n";
    temp = temp -> next;
  }
}
ostream & operator << (ostream & o, Queue q) {
  q.traverse();
  return o;
}
