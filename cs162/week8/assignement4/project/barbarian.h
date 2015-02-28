#ifndef BARBARIAN
#define BARBARIAN
#include "creature.h"
#include "dice.h"
#include <iostream>

using namespace std;

class Barbarian : public Creature {
public:
    Barbarian();
    Dice attack1;
    Dice attack2;
    Dice defense1;
    Dice defense2;   
    virtual int rollAttackDice();
    virtual int rollDefenseDice();
};

#endif