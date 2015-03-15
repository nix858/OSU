#ifndef MENU
#define MENU
#include <string>
#include <vector>
#include <iostream>
#include <stack>
#include "gameEntity.h"

using namespace std;

class Menu {
  vector<GameEntity*> items;
  string prompt;
public:
  Menu(char* prompt, vector<GameEntity*> items);
  GameEntity* run();
  GameEntity* run(stack<GameEntity*>* history);
};

#endif