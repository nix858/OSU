#ifndef GAME
#define GAME
#include <string>
#include <vector>
#include <iostream>
#include "gameState.h"
#include "location.h"
#include "bounty.h"
#include "gameEntity.h"
#include "area.h"
#include "person.h"

using namespace std;

class Game {
  Location* startLocation;
  GameState* gameState;
  vector<GameEntity*> allBounties;
  vector<GameEntity*> allAreas;

  void loadBounties();
  void setBountyLocation();
  void bountyChase();

  Location* pickBountyLocation();

  Location* buildSolarSystem();
  Location* buildMars(Location* space);
  Location* buildSaturn(Location* space);
  Location* buildEarth(Location* space);
  Location* buildMercury(Location* space);
  Location* buildVenus(Location* space);
  Location* buildPluto(Location* space);
  Location* buildUranus(Location* space);
  Location* buildJupiter(Location* space);
  Location* buildNeptune(Location* space);

  Area* buildBar(char* name);
  Area* buildCasino(char* name);
  Area* buildDiner(char* name);
  Area* buildStore(char* name);
  Area* buildStation(char* name);
  Area* buildMeteorField(char * name);

  Person* buildClerk(char* name);


public:
  void start();
};

#endif