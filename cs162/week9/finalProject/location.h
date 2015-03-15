#ifndef LOCATION
#define LOCATION
#include <string>
#include <vector>
#include <iostream>
#include "gameEntity.h"
using namespace std;
struct GameState;

class Location : public GameEntity {
  string name;
  string description;
  
  vector<string> level1Clues;
  vector<string> level2Clues;
  vector<string> level3Clues;

public:
  vector<GameEntity*> locations;
  string getClue(int level);
  void addLocation(Location* locations);
  void setName(string name);
  Location();
  virtual string getLabel();
  virtual void selectAction(GameState* gameState);
};

#endif