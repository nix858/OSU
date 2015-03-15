#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include "menu.h"
#include "gameEntity.h"

using namespace std;

Menu::Menu(char* prompt, vector<GameEntity*> items) {
  this->items = items;
  this->prompt = prompt;
}

GameEntity* Menu::run() {
  return run(NULL);
} 

GameEntity* Menu::run(GameEntity* back) {
  cout << prompt << ":" << endl;
  uint i = 0;
  for (; i < items.size(); ++i) {
    cout << i + 1 << ": " << items[i]->getLabel() << endl;
  }
  
  if (back != NULL) {
    cout << i + 1 << ": back to " << back->getLabel() << endl; 
  }

  bool validSelection = true;
  uint selection;
  do {
    cin >> selection;
    //TODO: validate selection
  } while (!validSelection);
  if (back != NULL && selection == i + 1) {     //Go back
    return back;
  }
  
  return items[selection - 1];
}