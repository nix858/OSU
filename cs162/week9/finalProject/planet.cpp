#include "planet.h"
#include "gameState.h"
#include "location.h"

void Planet::selectAction(GameState* gameState) {
  gameState->currentLocation = ship;
}

void Planet::setShip(Location* ship) {
  this->ship = ship;
}