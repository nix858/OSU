#include "location.h"
#include "gameEntity.h"
#include "gameState.h"
#include "menu.h"

void Location::addLocation(Location* loc) {
  this->locations.push_back(loc);
}

void Location::setName(string name) {
  this->name = name;
}

string Location::getLabel() {
  return this->name;
}

void Location::selectAction(GameState* gameState) {
  cout << "Current location: " << this->getLabel() << endl;
  Menu moveMenu((char*)"Where do you want to go?", this->locations);
  
  GameEntity* back = (gameState->locationHistory->empty()) ?
                      NULL : gameState->locationHistory->top();
  
  Location* selected = (Location*)moveMenu.run(back);
  if (selected == back) {
    gameState->locationHistory->pop();
  } else {
    gameState->money -= selected->getCost();
    gameState->locationHistory->push(gameState->currentLocation);
  }
  gameState->currentLocation = selected;
}

void Location::addClue(int level, string clue) {
  level = level > 3 ? 3 : level;
  if (level == 3)
  {
    level3Clues.push_back(clue);
  } else if (level == 2) {
    level2Clues.push_back(clue);
  } else {
    level1Clues.push_back(clue);
  }
}

string Location::getClue(int level) {
  level = level > 3 ? 3 : level;
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

Location::Location(){
  this->cost = 100; //default
}