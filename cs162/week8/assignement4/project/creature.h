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
    double maxStrength;
    int armor;
    double multiplier;
    double points;
    string teamName;
  
    virtual int rollAttackDice() = 0;
    virtual int rollDefenseDice() = 0;

public:
    void setMultiplier(double multiplier);
    string getType();
    void setName(string name);
    string getName();
    double getMultiplier();
    void setArmor(int Armor);
    int getArmor();
    void setStrength(double strength);
    double getStrength();
    void setMaxStrength(double strength);
    double getMaxStrength();
    void addPoints(double points);
    double getPoints();
    void setTeamName(string teamName);
    string getTeamName();
    Creature();
    virtual ~Creature(){};
    virtual void attack(Creature* opponent);
    virtual int defense();
    virtual void applyDamage(double damage, Creature* opponent);
    bool isDead();
    void heal();
};

#endif