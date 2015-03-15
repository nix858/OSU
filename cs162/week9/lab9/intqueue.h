#ifndef INTQUEUE
#define INTQUEUE
#include <iostream>

using namespace std;

struct IntQueueNode {
  int value;
  IntQueueNode* next;
  IntQueueNode(int val);
};

class IntQueue {
  int value;
  IntQueueNode* front;
  IntQueueNode* back;
public:
  void addBack(int val);
  int getFront();
  void removeFront();
  bool isEmpty();
  IntQueue();
};
#endif