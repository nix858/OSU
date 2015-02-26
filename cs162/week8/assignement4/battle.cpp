#include <iostream>
#include <string>
#include <deque>      
#include <list>       
#include <queue>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <locale>

using namespace std;
/*
 int numContestants;

  cout<< "User" << user << "enter the number of contestants." << endl;
  cin >> numContestants;*/

void Battle::makeLineup(int user) {

   
  queue<Creature*> ("userlineup" + user) (numContestants);

  cout<< "User" << user << ": Create your line up." << endl;
  cout << "Enter the type of creature and the creature's name." << endl;

  for (int i = 0; i < numContestants; ++i)
  {
    string type;
    string name;

    cout << "Enter a creature type of:"
       << "Goblin, Barbarian, Blue Man, Reptile,"
       << "or Shadow." << endl;
      getine(cin, type);

    locale loc;
    for (int j= 0; j < type.length(); ++j) {
      toupper(type[j],loc);
    }
    do {
      bool validType = true;
      
      if (type != "GOBLIN" || type != "BARBARIAN" ||
        type != "BLUE MAN" || type != "REPTILE" ||
        type != "SHADOW")
        {
          cout << "Invaid creature type." <<endl;
          validType = false
      }
      else { 

        ("userlineup" + user).push_back(Creature.setType(type));
        
        cout << "Enter the name for " << type << " : " << endl; 
        getine(cin, name);

        ("userlineup" + user)[i].push_back(setName(name));
      }
      
    } while (!validType);
  }
}

void Battle::fight(Creature* player1, Creature* player2) {
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
    player1->addLoser();
  }
  else {
    player1->addWinner();
    player1->addPoints();
  }
  if (player2->isDead()) {
    cout << player2->getType() << " is dead! " << endl;
    gameOver = true;
    player2->addloser();
  else {
    player2->addWinner();
    playe2->addPoints();
  }
  }
}


void Battle::addLoser() {

}

void Batte::addWinner() {

}

void Battle::addPoints() {

  if (/* condition */)
  {
    /* code */
  }

}