#include "area.h"
#include "location.h"
#include "gameState.h"

void Area::selectAction(GameState* gameState) {
  cout << "Current location: " << this->getLabel() << endl;
  cout << "Select a direction (ie N for north): " << endl << endl;

  if (north) {
    cout << "N. " << north->getLabel() << endl; 
  }

  if (south) {
    cout << "S. " << south->getLabel() << endl; 
  }

  if (east) {
    cout << "E. " << east->getLabel() << endl; 
  }

  if (west) {
    cout << "W. " << west->getLabel() << endl; 
  }

  if (locations.size() > 0)
  {
    cout << "O. Options" << endl << endl; 
  }

  cout << "Enter your selection ";
  char sel;
  cin >> sel;

  switch(sel) {
    case 'N': gameState->locationHistory->push(gameState->currentLocation);
              gameState->currentLocation = north;
              break;
    case 'S': gameState->locationHistory->push(gameState->currentLocation);
              gameState->currentLocation = south;
              break;
    case 'E': gameState->locationHistory->push(gameState->currentLocation);
              gameState->currentLocation = east;
              break;
    case 'W': gameState->locationHistory->push(gameState->currentLocation);
              gameState->currentLocation = west;
              break;
    case 'O': system("clear"); 
              gameState->locationHistory->push(gameState->currentLocation);
              Location::selectAction(gameState);
    break;
  }
  
}