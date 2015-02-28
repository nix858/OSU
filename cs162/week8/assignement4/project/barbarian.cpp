#include "barbarian.h"
#include "creature.h"
#include "dice.h"
#include <iostream>

using namespace std;

Barbarian::Barbarian() {
    type = "Barbarian";
    strength = 12;
    maxStrength = 12;
    armor = 0;
    multiplier = 1;
    attack1 = Dice(6);
    attack2 = Dice(6);
    defense1 = Dice(6);
    defense2 = Dice(6);
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
int Barbarian::rollAttackDice(){
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
int Barbarian::rollDefenseDice(){
    return Dice::rollTwoDice(defense1, defense2);
}
