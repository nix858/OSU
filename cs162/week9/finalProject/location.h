#ifndef LOCATION
#define LOCATION
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Location : public GameEntity {
  string name;
  string description;
  vector<Location*> locations;

  string[] level1Clues;
  string[] level2Clues;
  string[] level3Clues;

public:
  void getClue(int level);

  virtual void selectAction(GameState* gameState) = 0;
  void addLocation(Location* locations);
  void setName(string name);
  Location()
};

#endif;