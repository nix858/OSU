#ifndef GAMESTATE
#define GAMESTATE
#include "area.h"
#include "location.h"

using namespace std;

struct GameState {
  Bounty* bounty;
  Location* currentLocation;
  Location* returnLocation;
  Area* bountyLocation;
  int money;
  int clueLevel;
  bool bountyCaptured;
};

#endif;

