#include "creature.h"
#include "dice.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;



/*****************************************************
** Function: setMultiplier()
** Description: This is the setter function for multiplier.
** Parameters:  takes a foat multiplier
** Pre-Conditions: None
** Post-Conditions: sets name. 
*******************************************************/
void Creature::setMultiplier(double multiplier) {
    this->multiplier = multiplier;
}

/*****************************************************
** Function: getMultiplier()
** Description: This is the getter function for multiplier.
** Parameters:  none
** Pre-Conditions: None
** Post-Conditions: returns name. 
*******************************************************/
double Creature::getMultiplier() {
    return multiplier;
}


/*****************************************************
** Function: setArmor()
** Description: This is the setter function for armor.
** Parameters:  takes an int armor
** Pre-Conditions: None
** Post-Conditions: sets armor. 
*******************************************************/
void Creature::setArmor(int armor) {
    this->armor = armor;
}

/*****************************************************
** Function: getArmor()
** Description: This is the getter function for armor.
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: returns name. 
*******************************************************/
int Creature::getArmor() {
    return armor;
}

/*****************************************************
** Function: setStrength()
** Description: This is the setter function for strength.
** Parameters:  takes an int strength
** Pre-Conditions: None
** Post-Conditions: sets strength. 
*******************************************************/
void Creature::setStrength(double strength) {
    this->strength = strength;
}

/*****************************************************
** Function: getStrength()
** Description: This is the getter function for strength.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: retuns strength. 
*******************************************************/
double Creature::getStrength() {
    return strength;
}

/*****************************************************
** Function: getType()
** Description: This is the getter function for type.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: returns name. 
*******************************************************/
string Creature::getType() {
    return type;
}

/*****************************************************
** Function: attack()
** Description: This function determines the damage of an 
    attack by calling rollAttackDice(). It then applies 
    the damage to the opponent by calling applyDamage().
** Parameters:  takes a Creature &opponent
** Pre-Conditions: None
** Post-Conditions: damage has been applied to the opponent. 
*******************************************************/
void Creature::attack(Creature* opponent) {
    string multMsg = "";
    int damage = rollAttackDice();
    double totalDamage = damage * multiplier;
    if (multiplier < 1)
    {
        stringstream ss;
        ss << totalDamage;
        multMsg = "/2 = " + ss.str();
    }
    cout << this->type << " attacks " << opponent->type;
    cout << " (" << damage << multMsg << ") " << endl;
    
    opponent->applyDamage(totalDamage);
}

/*****************************************************
** Function: defense()
** Description: This function determines the defense of a  
    player by calling rollDefenseDice().
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: returns the defense for a player. 
*******************************************************/
int Creature::defense() {
    return rollDefenseDice();
}

/*****************************************************
** Function: applyDamage()
** Description: This function takes in int damage as a
   parameter and determines the amount of damage to apply
   to the player. It then updates the strength in accordance
   with the damage received.
** Parameters:  takes int damage
** Pre-Conditions: None
** Post-Conditions: Changes player strength after damage received. 
*******************************************************/
void Creature::applyDamage(double damage) {
    int def = defense();
    double totalDamage = (damage - armor) - def;
    if (totalDamage < 0)
    {
        totalDamage = 0;
    }
    double newStrength = strength - totalDamage;
    strength = newStrength;

    cout << this->type << " defends " << " (" << def << ") + armor ("  << armor << ")"<< endl;
    cout << this->type << " takes damage " << " (" << totalDamage << ") " << endl;

}

/*****************************************************
** Function: isDead()
** Description: This function will check if a player is
    dead and retun a bool accordingly.
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: returns bool isDead 
*******************************************************/
bool Creature::isDead() {
    bool dead = this->strength <= 0;
    return dead;
}





 