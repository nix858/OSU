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

GameEntity* Menu::run(stack<GameEntity*>* history) {
  cout << prompt << ":" << endl;
  uint i = 0;
  for (; i < items.size(); ++i) {
    cout << i + 1 << ": " << items[i]->getLabel() << endl;
  }
  
  if (history != NULL) {
    cout << i + 1 << ": back to " << history->top()->getLabel(); 
  }
  
  bool validSelection = true;
  uint selection;
  do {
    cin >> selection;
  } while (!validSelection);

  if (selection == i + 1) {     //Go back
    GameEntity* tmp = history->top();
    history->pop();
    return tmp;
  } else {
    if (history != NULL)
    {
      history->push(items[selection - 1]);
    }
  }
  return items[selection - 1];
}