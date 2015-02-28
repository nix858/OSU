#ifndef REPTILE
#define REPTILE
#include "creature.h"
#include "dice.h"
#include <iostream>

using namespace std;

class Reptile : public Creature {
public:
    Reptile();
    Dice attack1;
    Dice attack2;
    Dice attack3;
    Dice defense1;
    virtual int rollAttackDice();
    virtual int rollDefenseDice();
};

#endif