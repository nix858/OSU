#ifndef GAME
#define GAME
#include <string>
#include <vector>
#include <iostream>
#include "gameState.h"
#include "location.h"
#include "bounty.h"
#include "gameEntity.h"

using namespace std;

class Game {
  Location* startLocation;
  GameState* gameState;
  vector<GameEntity*> allBounties;

  void loadBounties();
  void setBountyLocation();

  Location* buildSolarSystem();
  //Location* buildEarth();
  Location* buildMars();
  Location* buildBar(char* name);


public:
  void start();
};

#endif