#ifndef GAMESTATE
#define GAMESTATE
#include "location.h"
#include "bounty.h"
#include <stack>
#include <vector>
#include <string>

using namespace std;

struct GameState {
  Bounty* bounty;
  Location* currentLocation;
  Location* bountyLocation;
  stack<GameEntity*>* locationHistory;
  vector<string> clues;
  vector<GameEntity*> inventory;
  int money;
  int clueLevel;
  bool bountyCaptured;
};

#endif

