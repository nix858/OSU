#include "location.h"

string Location::getType() {
  return "location";
}

void Location::addLocation(Location * loc) {
  this->locations.push_back(loc);
}

void Location::setName(string name) {
  this->name = name;
}

virtual string Location::getLabel() {
  return this->name;
}

virtual void Location::selectAction(GameState* gameState) {
  cout << "Welcome to " << this->getLabel();
  Menu moveMenu("Where do you want to go?", this->nearbyLocations);
  GameEntity selected = moveMenu.run();
  gameState->returnLocation = gameState->currentLocation;       
  gameState->currentLocation = (Location)selected; //We know this is a location so safe to cast
}

string Location::getClue(int level) {
  if (level == 3)
  {
    //TODO: randomly select level 3 clue
    return "poopee";
  } else if (level == 2) {
    //TODO: randomly select level 3 clue
    return "poo";
  } else {
    //TODO: randomly select level 3 clue
    return "pee";
  }
}