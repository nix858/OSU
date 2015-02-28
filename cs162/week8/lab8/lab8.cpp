#include <iostream>

using namespace std;


int main(){


  ListNode* head = NULL;
  //Create first node
  head = new
  head->north = true;
  head->south = true;
  head->east = false;
  head->west = false;
  head-> exit= true;
  head->next->secondPtr; 

  //create second node
  ListNode* secondPtr = new ListNode;
  secondPtr->north = true;
  secondPtr->south = false;
  secondPtr->east = false;
  secondPtr->west = true;
  secondPtr->exit = false;
  head->next->secondPtr;

  //create second node
  ListNode* thidPtr = new ListNode;
  thidPtr->north = true;
  thidPtr->south = false;
  thidPtr->east = false;
  thidPtr->west = true;
  thidPtr->exit = false;
  head->secondPtr->thidPtr;

  ListNode* thirdPtr = new ListNode;
  thirdPtr->north = true;
  thirdPtr->south = false;
  thirdPtr->east = false;
  thirdPtr->west = true;
  thirdPtr->exit = false;
  head->secondPtr->thirdPtr;


  ListNode* fouthPtr = new ListNode;
  fouthPtr->north = true;
  fouthPtr->south = false;
  fouthPtr->east = false;
  fouthPtr->west = true;
  fouthPtr->exit = false;
  head->thirdPtr->fouthPtr;

  struct ListNode {
    bool north;
    bool south;
    bool east;
    bool west;
    bool exit;
    ListNode* next;
  }
  



  return 0;
}