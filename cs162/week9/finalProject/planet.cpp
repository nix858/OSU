#include "planet.h"
#include "gameState.h"

using namespace std;

void Planet::selectAction(GameState* gameState) {
  cout << "Welcome to " << this->getLabel();
  Menu moveMenu("Where do you want to go?", this->nearbyLocations);
  GameEntity selected = moveMenu.run();
  gameState->returnLocation = gameState->currentLocation;       
  gameState->currentLocation = (Location)selected; //We know this is a location so safe to cast
}