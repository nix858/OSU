#ifndef GOBLIN
#define GOBLIN
#include "creature.h"
#include "dice.h"
#include <iostream>

using namespace std;

class Goblin: public Creature {
public:
    Goblin();
    Dice attack1;
    Dice attack2;
    Dice defense1;

    virtual void attack(Creature* opponent);
    virtual int rollAttackDice();
    virtual int rollDefenseDice();
};

#endif