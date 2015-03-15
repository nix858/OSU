#include <iostream>
#include "intstack.h"
#include "intqueue.h"

using namespace std;


int main() {

  IntStack stack;

  stack.push(1);
  stack.push(2);
  stack.push(3);

  cout << "Top value of the stack:" << stack.peek() << endl;
  stack.pop();
  cout << "Top value of the stack:" << stack.peek() << endl;
  stack.pop();
  cout << "Top value of the stack:" << stack.peek() << endl;
  stack.pop();
  try {
    stack.pop(); 
  } catch (exception& e) {
    cout << "handled error: " << e.what() << endl;
  }
  try {
    stack.peek(); 
  } catch (exception& e) {
    cout << "handled error: " << e.what() << endl;
  }
  stack.push(100);
  cout << "Top value of the stack:" << stack.peek() << endl;


  IntQueue queue;
  queue.addBack(1);
  queue.addBack(2);
  queue.addBack(3);
  cout << "Front value of the queue:" << queue.getFront() << endl;
  queue.removeFront();
  cout << "Front value of the queue:" << queue.getFront() << endl;
  queue.removeFront();
  cout << "Front value of the queue:" << queue.getFront() << endl;
  queue.removeFront();  
  queue.addBack(5);
  queue.addBack(6);
  cout << "Front value of the queue:" << queue.getFront() << endl;
  queue.removeFront();
  cout << "Front value of the queue:" << queue.getFront() << endl;
  queue.removeFront();
  try {
    queue.removeFront(); 
  } catch (exception& e) {
    cout << "handled error: " << e.what() << endl;
  }
  try {
    queue.getFront(); 
  } catch (exception& e) {
    cout << "handled error: " << e.what() << endl;
  }

  return 0;
}