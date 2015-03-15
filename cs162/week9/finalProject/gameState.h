#ifndef GAMESTATE
#define GAMESTATE
#include "location.h"
#include "bounty.h"
#include <stack>

using namespace std;

struct GameState {
  Bounty* bounty;
  Location* currentLocation;
  Location* bountyLocation;
  stack<GameEntity*>* locationHistory;
  int money;
  int clueLevel;
  bool bountyCaptured;
};

#endif

