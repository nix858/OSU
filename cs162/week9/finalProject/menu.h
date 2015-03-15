#ifndef MENU
#define MENU
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Menu {
  vector<GameEntity*> items;
  string prompt;
public:
  Menu(vector<GameEntity*> items);
  MenuItem* run();
};

#endif;