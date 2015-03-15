#ifndef INTSTACK
#define INTSTACK
#include <iostream>


using namespace std;

struct IntStackNode {
  int value;
  IntStackNode* previous;
  IntStackNode(int val, IntStackNode* prev);
};

class IntStack {
  IntStackNode* top;
public:
  void push(int);
  int peek();
  void pop();
  bool isEmpty();
  IntStack();
};

#endif

