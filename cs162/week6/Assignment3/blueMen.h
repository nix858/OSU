#ifndef BlUEMEN
#define BlUEMEN
#include <iostream>
#include "creature.h"
#include "dice.h"


using namespace std;

class BlueMen : public Creature {
public:
    Dice attack1;
    Dice attack2;
    Dice defense1;
    Dice defense2;
    Dice defense3;
    BlueMen();
    virtual int rollAttackDice();
    virtual int rollDefenseDice();
};

#endif