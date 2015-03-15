#include "intqueue.h"
#include <iostream>
#include <stdexcept>

using namespace std;

IntQueueNode::IntQueueNode(int val) {
  value = val;
}

void IntQueue::addBack(int val) {
  IntQueueNode* node = new IntQueueNode(val);
  if (isEmpty()) {
    front = node;
  } else {
    back->next = node;
  }
  back = node;
  back->next = NULL;
}

int IntQueue::getFront() {
  if (!isEmpty())
  {
    return front->value;
  } else {
    throw runtime_error("getFront called on empty queue\n");
  }
  
}

void IntQueue::removeFront() {
  if (!isEmpty()) {
    IntQueueNode* tmp = front;
    front = front->next;
    delete tmp;
  } else {
    throw runtime_error("removeFront called on empty queue\n");
  }
}

bool IntQueue::isEmpty() {
  return front == NULL;
}

IntQueue::IntQueue() {
  front = NULL;
  back = NULL;
}
