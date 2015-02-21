#include "dice.h"
#include <iostream>

using namespace std;

/*****************************************************
** Function: dice()
** Description: This is the dice constructor.
** Parameters:  none
** Pre-Conditions: None
** Post-Conditions: none 
*******************************************************/
Dice::Dice() {
    numSides = 6;
    srand(time(NULL)); // Seeds random number generator
}

/*****************************************************
** Function: dice()
** Description: This is the dice constructor, with a 
    parameter for the number of sides.
** Parameters:  takes an int numSides
** Pre-Conditions: None
** Post-Conditions: none
*******************************************************/
Dice::Dice(int numSides) {
    this->numSides = numSides;
    srand(time(NULL)); // Seeds random number generator
}

/*****************************************************
** Function: rollDice()
** Description: This function will roll a single dice.
** Parameters: none
** Pre-Conditions: None
** Post-Conditions:returns and int, result of one dice roll
*******************************************************/
int Dice::rollDice() {
    return (rand() % numSides) + 1;
}

/*****************************************************
** Function: rollTwoDice()
** Description: This function will roll two dice and 
    return the sum.
** Parameters: takes two dice objects
** Pre-Conditions: None
** Post-Conditions:returns sum of two dice rolls
*******************************************************/
int Dice::rollTwoDice(Dice& die1, Dice& die2) {
    return die1.rollDice() + die2.rollDice();
}

/*****************************************************
** Function: rollThreeDice()
** Description: This function will roll three dice and 
    return the sum.
** Parameters: takes three dice objects
** Pre-Conditions: None
** Post-Conditions:returns sum of three dice rolls
*******************************************************/
int Dice::rollThreeDice(Dice& die1, Dice& die2, Dice& die3) {
    return die1.rollDice() + die2.rollDice() + die3.rollDice();
}




    