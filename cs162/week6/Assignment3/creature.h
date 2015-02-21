#ifndef CREATURE
#define CREATURE
#include "dice.h"
#include <iostream>
#include <string>

using namespace std;

class Creature {
protected:
    string type;
    double strength;
    int armor;
    double multiplier;
  
    virtual int rollAttackDice() = 0;
    virtual int rollDefenseDice() = 0;

public:
    void setMultiplier(double multiplier);
    string getType();
    double getMultiplier();
    void setArmor(int Armor);
    int getArmor();
    void setStrength(double strength);
    double getStrength();
    
    virtual ~Creature(){};
    virtual void attack(Creature* opponent);
    virtual int defense();
    virtual void applyDamage(double damage);
    bool isDead();
};

#endif