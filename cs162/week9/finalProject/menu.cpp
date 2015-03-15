#include <string>
#include <vector>
#include <iostream>
#include "menu.h"
#include "GameEntity.h"
i
using namespace std;


  
Menu::Menu(char* prompt, vector<GameEntity*> items) {
  this->items = items;
  this->prompt = prompt;
}

MenuItem* Menu::run() {
  cout << prompt << ":" << endls;
  for (uint i = 0; i < items.size(); ++i)
  {
    cout << i << ": " << items[i]->getLabel() << endl;
  }

  bool validSelection = true;
  int selection;
  do
  {
    // do selection
  } while (!validSelection);

  return items[selection];
}