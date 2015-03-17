#ifndef PLANET
#define PLANET
#include <string>
#include <vector>
#include <iostream>
#include "location.h"

using namespace std;

class Planet : public Location {
  Location* ship;
public:
  virtual void selectAction(GameState* gameState);
  void setShip(Location* ship);
};

#endif