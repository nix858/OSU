#ifndef MENU
#define MENU
#include <string>
#include <vector>
#include <iostream>
#include "gameEntity.h"

using namespace std;

class Menu {
  vector<GameEntity*> items;
  string prompt;
public:
  Menu(char* prompt, vector<GameEntity*> items);
  GameEntity* run();
};

#endif