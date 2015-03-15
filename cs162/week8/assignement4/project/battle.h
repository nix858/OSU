#ifndef BATTLE
#define BATTLE

#include <iostream>
#include <string>    
#include <stack>       
#include <queue>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <locale>
#include "creature.h"


class Battle{
  queue<Creature*> teams[2];
  stack<Creature*> losers;
  void fight(Creature*, Creature*);
  static bool creatureSort(Creature* x, Creature* y);

public:
  void doTournament();
  void makeTeams();
  void displayTopThree();
  void makeTestTeams();
};

#endif
