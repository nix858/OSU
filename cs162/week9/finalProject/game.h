#ifndef GAME
#define GAME
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Game {
  Location* startLocation;
  GameState* gameState;
  vector<Bounty> allBounties;

  void loadBounties();

  Location* buildSolarSystem();
  //Location* buildEarth();
  Location* buildMars();

public:
  void start();
};

#endif;