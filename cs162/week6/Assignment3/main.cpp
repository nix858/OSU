#include "creature.h"
#include "goblin.h"
#include "barbarian.h"
#include "reptile.h"
#include "shadow.h"
#include "blueMen.h"
#include "dice.h"
#include <iostream>
#include <string>

using namespace std;


/*********************************************************************  
** Program Filename: assignment3.cpp
** Author: Nicole Parker
** Date: 2/13/2015
** Description: This program is a fantasy combat game with a simple class
   hierarchy. There is a base class creature and subclasses for Goblins, 
   Barbarians, Reptile People, Blue Men and Shadow. Each subclass inherits
   from the creature class, and each subclass has their unique characteristics
   for attack, defense, armor, and strength points. Battles are between two
   players, and the battle continues until a player dies. 
** Input: There is no input. 
** Output: Output is the information for attack points, total damage, and
    if a player has died. 
*********************************************************************/

void fight(Creature* player1, Creature* player2) {
  cout << "----------------------------------------------" << endl;
  cout << player1->getType() << " VS. " << player2->getType() << "!!!!" << endl;
  cout << "----------------------------------------------" << endl;
  bool gameOver = false;
  while(!gameOver) {
    player1->attack(player2);
    player2->attack(player1);
    cout << endl << player1->getType() << " strength: " << player1->getStrength() << endl;
    cout << player2->getType() << " strength: " << player2->getStrength() << "\n\n\n";
    
    if (player1->isDead()) {
      cout << player1->getType() << " is dead! " << endl;
      gameOver = true;
    }
    if (player2->isDead()) {
      cout << player2->getType() << " is dead! " << endl;
      gameOver = true;
    }

  }
  cout << "\n\n\n";
  delete player1;
  delete player2;
}


int main() {
  fight(new Barbarian, new Barbarian);
  fight(new Barbarian, new Shadow);
  fight(new Barbarian, new Goblin);
  fight(new Barbarian, new BlueMen);
  fight(new Barbarian, new Reptile);

  fight(new Shadow, new Shadow);
  fight(new Shadow, new Goblin);
  fight(new Shadow, new BlueMen);
  fight(new Shadow, new Reptile);

  fight(new Goblin, new Goblin);
  fight(new Goblin, new BlueMen);
  fight(new Goblin, new Reptile);

  fight(new BlueMen, new BlueMen);
  fight(new BlueMen, new Reptile);

  fight(new Reptile, new Reptile);

  
  return 0;
}