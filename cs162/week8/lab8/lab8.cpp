#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct ListNode {
  string label;
  ListNode* north;
  ListNode* south;
  ListNode* east;
  ListNode* west;
  bool exit;
};

ListNode* room1;
ListNode* room2;
ListNode* room3;
ListNode* room4;
ListNode* theEnd;
ListNode* currentRoom;

bool labels = true;
char getDirection();
bool getLabels();
void moveTo(char);
int roomCount = 0;


int main(){

  room1 = new ListNode();
  room1->label = "room1";

  room2 = new ListNode();
  room2->label = "room2";

  room3 = new ListNode();
  room3->label = "room3";

  room4 = new ListNode();
  room4->label = "room4";

  theEnd = new ListNode();
  theEnd->exit = true;

  room1->north = NULL;
  room1->east = room2;
  room1->south = room3;
  room1->west = NULL;


  room2->north = room1;
  room2->east = room4;
  room2->south = room3;
  room2->west = NULL;
  room2->exit = false;

  room3->north = room4;
  room3->south = NULL;
  room3->east = NULL;
  room3->west = NULL;
  room3->exit = false;
  
  room4->north = NULL;
  room4->east = NULL;
  room4->west = room3;
  room4->south = room1;
  room4->exit = false;

  currentRoom = room1;
  
  getLabels();
  
  while(true) {
    if (roomCount > 2)
    {
      room1->west = theEnd;
    }
    if (currentRoom->exit) {
      cout << "Congratulations! You have reached the exit. Good Bye!" << endl;
      return 0;
    }
    char dir = getDirection();
    moveTo(dir);
  }  

  delete[] room1;
  delete[] room2;
  delete[] room3;
  delete[] room4;
  delete[] theEnd;
  return 0;
}

void moveTo(char dir) {
  roomCount++;
  switch(dir) {
    case 'N':
      currentRoom = currentRoom->north;
      break;
    case 'S':
      currentRoom = currentRoom->south;
      break;
    case 'E':
      currentRoom = currentRoom->east;
      break;
    case 'W':
      currentRoom = currentRoom->west;
      break;
  }
}

char getDirection() {
  bool validDirection = false;
  char direction;
  vector<char> doors;

  if (labels) {
    cout << "You are in " << currentRoom->label << endl;
  }
  cout << "You can move ";
  do {
    validDirection = false;
    if (currentRoom->north) {
      cout << "\nnorth (N)";
      doors.push_back('N');
    }
    if (currentRoom->south) {
      cout << "\nsouth (S)";
      doors.push_back('S');
    }
    if (currentRoom->east) {
      cout << "\neast (E)";
      doors.push_back('E');
    }
    if (currentRoom->west) {
      cout << "\nwest (W)";
      doors.push_back('W');
    }
    cout << "\nEnter a direction to move. Enter a single character (ie N for north): ";
    cin >> direction;
    direction = toupper(direction);

    for (uint i = 0; i < doors.size(); ++i) {
      if (doors[i] == direction) {
        validDirection = true;
      } 
    }
    if(!validDirection) {
      cout << "You cannot go that way!" << endl;
    }
  } while (!validDirection);
  return direction;
}

bool getLabels() {
  bool isValid = true;
  do
  {
    labels = true;
    char input;
    cout << "Would you like labels on? Enter Y for yes and N for no: " <<endl;
    cin >> input;
    input = toupper(input);

    if (input != 'Y' && input != 'N')
    {
      cout << "Invalid input." << endl;
      isValid = false;
    }
    else if (input == 'N')
    {
      labels = false;
    }
    else  
      labels = true;
  } while (!isValid);

  return labels;   
}