#ifndef CREATURE
#define CREATURE
#include "dice.h"
#include <iostream>
#include <string>

using namespace std;

class Creature {
protected:
    string type;
    string name;
    double strength;
    int armor;
    double multiplier;
    int points;
  
    virtual int rollAttackDice() = 0;
    virtual int rollDefenseDice() = 0;

public:
    void setMultiplier(double multiplier);
    string getType();
    void setName(string name)
    void getName();
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
    void getName();
};

#endif