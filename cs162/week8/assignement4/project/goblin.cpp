#include "goblin.h"
#include "dice.h"
#include <iostream>

using namespace std;

Goblin::Goblin() : Creature() {
    type = "Goblin";
    strength = 8;
    maxStrength = 8;
    armor = 3;
    multiplier = 1;
    attack1 = Dice(6);
    attack2 = Dice(6);
    defense1 = Dice(6);
}

/*****************************************************
** Function: attack()
** Description: This vitual function the determines the 
    damage of an attack by calling rollAttackDice(). It 
    takes into account the Goblins, special "Achilles" 
    feature, where when fighting a non-goblin creature if
    a 12 is rolled then the opponents strength is halved
    for the remainder of the battle.
** Parameters:  takes a Creature &opponent
** Pre-Conditions: None
** Post-Conditions: applies damage to the opponent. 
*******************************************************/
void Goblin::attack(Creature* opponent) {
    double damage = rollAttackDice();
    cout << this->name << " attacks " << opponent->getName();
    cout << " (" << damage << ") " << endl;
    if (opponent->getType() != "Goblin" && damage == 12) {
        cout << this->name << " has stuck the Achilles!" << endl;
        double prevMultiplier = opponent->getMultiplier();
        opponent->setMultiplier(prevMultiplier/2);
    }
    opponent->applyDamage(damage, this);
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
int Goblin::rollAttackDice(){
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
int Goblin::rollDefenseDice(){
    return defense1.rollDice();
}



