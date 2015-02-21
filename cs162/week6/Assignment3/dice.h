#ifndef DICE
#define DICE
#include <iostream>

using namespace std;

class Dice
{
protected:
    int numSides;
public:
    Dice();
    Dice(int numSides);
    int rollDice();
    static int rollTwoDice(Dice& die1, Dice& die2);
    static int rollThreeDice(Dice& die1, Dice& die2, Dice& die3);
};
#endif