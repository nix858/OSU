#include "blueMen.h"
#include "dice.h"
#include <iostream>

using namespace std;

BlueMen::BlueMen() : Creature() {
    type = "Blue Man";
    strength = 12;
    maxStrength = 12;
    armor = 3;
    multiplier = 1;
    attack1 = Dice(10);
    attack2 = Dice(10);
    defense1 = Dice(6);
    defense2 = Dice(6);
    defense3 = Dice(6);
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
int BlueMen::rollAttackDice(){
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
int BlueMen::rollDefenseDice(){
    return Dice::rollThreeDice(defense1, defense2, defense3);
}

