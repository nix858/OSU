#include "shadow.h"
#include "dice.h"
#include <iostream>

using namespace std;

Shadow::Shadow() {
    type = "Shadow";
    strength = 12;
    maxStrength = 12;
    armor = 0;
    multiplier = 1;
    attack1 = Dice(10);
    attack2 = Dice(10);
    defense1 = Dice(6);
}

/*****************************************************
** Function: rollAttackDice()
** Description: This is a virtual function that determines 
    the attack amount for a player. It returns the attack 
    as an int.
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: returns amount for attack as an int. 
*******************************************************/
int Shadow::rollAttackDice() {
    return Dice::rollTwoDice(attack1, attack2);
}

/*****************************************************
** Function: rollDefenseDice()
** Description: This is a virtual function that determines 
    the defense amount for a player. It returns the defense 
    as an int.
** Parameters: none
** Pre-Conditions: None
** Post-Conditions: returns amount for defense as an int. 
*******************************************************/
int Shadow::rollDefenseDice() {
    return defense1.rollDice();
}

/*****************************************************
** Function: applyDamage()
** Description: This is a virtual function that determines 
    the amount of damage for a player. It accounts for
    shadows special defense and only applies damage 50% of 
    the time. 
** Parameters: takes int damage
** Pre-Conditions: None
** Post-Conditions: Changes player strength after damage received. 
*******************************************************/
void Shadow::applyDamage(double damage, Creature* opponent) {
    Dice escapedDamage(2);
    int def = defense();
    double totalDamage = (damage - armor) - def;

    if (escapedDamage.rollDice() % 2 == 1) {
        cout << this->type << " takes no damage " << endl;
        return;
    }
    else {
        if (totalDamage < 0)
        {
            totalDamage = 0;
        }
        opponent->addPoints(totalDamage);
        cout << this->type << "defends " << " (" << def << ") " << endl;
        cout << this->type << "defends " << " (" << def << ") + armor ("  << armor << ")"<< endl;
        int newStrength = strength - totalDamage;
        strength = newStrength;
    }
}


