#include "location.h"
#include "gameEntity.h"
#include "gameState.h"
#include "menu.h"

void Location::addLocation(Location * loc) {
  this->locations.push_back(loc);
}

void Location::setName(string name) {
  this->name = name;
}

string Location::getLabel() {
  return this->name;
}

void Location::selectAction(GameState* gameState) {
  cout << "Welcome to " << this->getLabel();
  Menu moveMenu((char*)"Where do you want to go?", this->locations);
  gameState->returnLocation = gameState->currentLocation;
  Location selected = (Location)(moveMenu.run());      
  gameState->currentLocation = selected; //We know this is a location so safe to cast
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