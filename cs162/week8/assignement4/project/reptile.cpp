#include "reptile.h"
#include "dice.h"
#include <iostream>

using namespace std;

Reptile::Reptile() : Creature() {
    type = "Reptile";
    strength = 18;
    maxStrength = 18;
    armor = 7;
    multiplier = 1;
    attack1 = Dice(6);
    attack2 = Dice(6);
    attack3 = Dice(6);
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
int Reptile::rollAttackDice() {
    return Dice::rollThreeDice(attack1, attack2, attack3);
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
int Reptile::rollDefenseDice() {
    return defense1.rollDice();
}



