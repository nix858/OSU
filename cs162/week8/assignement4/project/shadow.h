#ifndef SHADOW
#define SHADOW
#include "creature.h"
#include "dice.h"
#include <iostream>

using namespace std;

class Shadow : public Creature {
public:
    Shadow();
    Dice attack1;
    Dice attack2;
    Dice defense1;
    virtual int rollAttackDice();
    virtual int rollDefenseDice();
    virtual void applyDamage(double damage, Creature* opponent);
};

#endif