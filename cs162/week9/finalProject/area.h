#ifndef AREA
#define AREA
#include <string>
#include <vector>
#include <iostream>
#include "location.h"

using namespace std;

class Area : public Location {
public:
  virtual void selectAction(GameState* gameState);
  Area* north;
  Area* south;
  Area* east;
  Area* west;
};

#endif