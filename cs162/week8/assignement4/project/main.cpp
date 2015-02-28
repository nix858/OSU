#include "battle.h"
#include <iostream>

using namespace std;

int main() {
  Battle battle;
  battle.makeTeams();
  //battle.makeTestTeams();
  battle.doTournament();
  battle.displayTopThree();
  
  return 0;
}