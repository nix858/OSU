#ifndef PLANET
#define PLANET

#include "gameState.h"

using namespace std;

class Planet : public Location {
public:
  virtual void selectAction(GameState* gameState);
};

#endif;



