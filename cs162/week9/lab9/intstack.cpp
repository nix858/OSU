#include "intstack.h"
#include <iostream>
#include <stdexcept>

using namespace std;

IntStackNode::IntStackNode(int val, IntStackNode* prev) {
  value = val;
  previous = prev;
}

IntStack::IntStack() {
  top = NULL;
}

void IntStack::push(int val) {
  IntStackNode* node = new IntStackNode(val, top);
  top = node;
}

int IntStack::peek() {
  if (!isEmpty()) {
    return top->value;
  } else {
    throw runtime_error("peek called on empty stack\n");
  }
}

void IntStack::pop() {
  if (!isEmpty())
  {
    IntStackNode* tmp = top;
    top = top->previous;
    delete tmp;
  } else {
    throw runtime_error("pop called on empty stack\n");
  }
}

bool IntStack::isEmpty() {
  return top == NULL;
} 
