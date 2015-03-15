#ifndef GAMESTATE
#define GAMESTATE
#include "location.h"
#include "bounty.h"

using namespace std;

struct GameState {
  Bounty* bounty;
  Location* currentLocation;
  Location* returnLocation;
  Location* bountyLocation;
  int money;
  int clueLevel;
  bool bountyCaptured;
};

#endif

