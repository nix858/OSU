#include "battle.h"
#include <iostream>
#include <string>
#include <vector>      
#include <stack>       
#include <queue>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <locale>
#include "creature.h"
#include "goblin.h"
#include "barbarian.h"
#include "reptile.h"
#include "shadow.h"
#include "blueMen.h"
#include <algorithm>


using namespace std;

void Battle::makeTestTeams() {
  Creature* g1 = new Goblin();
  g1->setTeamName("team1");
  g1->setName("Oliver");
  this->teams[0].push(g1);

  Creature* g2 = new Goblin();
  g2->setTeamName("team2");
  g2->setName("Kitty");
  this->teams[1].push(g2);
}

/*****************************************************
** Function: getName()
** Description: This is the function to get creature name.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: returns name. 
*******************************************************/
void Battle::makeTeams() {
  string type;
  string name;
  string teamName;
  bool validType = true;

  int numContestants;
  cout << "Enter the number of contestants." << endl;
  cin >> numContestants;

  cin.ignore(10000,'\n');

  for (int p = 0; p < 2; ++p) {
    cout << "Player " << p + 1 << " enter your team name then press enter:" << endl;
    getline(cin, teamName);

    cout << teamName << " : Create your line up." << endl;

    for (int i = 0; i < numContestants; ++i) {

      do {
        validType = true;
        cout << "Enter a creature type for contestant " << i + 1 << " then press enter "
         << "(ex. Goblin, Barbarian, Blue Man, Reptile,"
         << " or Shadow): " << endl;
        getline(cin, type);

        for (uint j= 0; j < type.length(); ++j) {
          type[j] = toupper(type[j]);
        }
        
        if (type != "GOBLIN" && type != "BARBARIAN" && type != "BLUE MAN" && type != "REPTILE" && type != "SHADOW") {
          cout << "After Upper:" << type << endl;
          cout << "Invaid creature type." <<endl;
          validType = false;
        }
      } while (!validType);

        Creature* newChar;

        if(type == "GOBLIN") {
          newChar = new Goblin();
        } 
        else if(type == "BARBARIAN") {
          newChar = new Barbarian();
        }
        else if(type == "BLUE MAN") {
          newChar = new BlueMen();
        }
        else if(type == "REPTILE") {
          newChar = new Reptile(); 
        }
        else if(type == "SHADOW") {
          newChar = new Shadow();
        }
        
        cout << "Enter the name for " << type << " : " << endl; 
        getline(cin, name);
        newChar->setName(name);
        newChar->setTeamName(teamName);
        this->teams[p].push(newChar);
    }
  }

}

/*****************************************************
** Function: getName()
** Description: This is the function to get creature name.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: returns name. 
*******************************************************/
void Battle::fight(Creature* player1, Creature* player2) {
  cout << "-----------------------------------------------------------------" << endl;
  cout << "Team:" << player1->getTeamName() 
       << " Name:" << player1->getName() 
       << "(type:" << player1->getType() << ")"  
       << " VS. " 
       << " Team:" << player2->getTeamName() 
       << " Name:" << player2->getName()
       << "(type:" << player2->getType() << ")" << endl;
  cout << "-----------------------------------------------------------------" << endl;
  bool fightOver = false;
  while(!fightOver) {
    player1->attack(player2);
    player2->attack(player1);
    cout << endl << player1->getType() << " strength: " << player1->getStrength() << endl;
    cout << player2->getType() << " strength: " << player2->getStrength() << "\n\n\n";
    
    if (player1->isDead()) {
      cout << "Team:" << player1->getTeamName() 
           << " Name:" << player1->getName()
           << "(type:" << player1->getType() << ")" << " is dead!" << endl << endl;
      fightOver = true;
    }

    if (player2->isDead()) {
      cout << "Team:" << player2->getTeamName() 
           << " Name:" << player2->getName()
           << "(type:" << player2->getType() << ")" << " is dead!" << endl << endl;
      fightOver = true;
    }
  }
}

/*****************************************************
** Function: getName()
** Description: This is the function to get creature name.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: returns name. 
*******************************************************/
void Battle::doTournament() {
  while(!teams[0].empty() && !teams[1].empty()) {
    Creature* p1Char = teams[0].front();
    Creature* p2Char = teams[1].front();
    teams[0].pop();
    teams[1].pop();

    fight(p1Char, p2Char);
    if (!p1Char->isDead()) {
      p1Char->heal();
      teams[0].push(p1Char);
    }
    else {
      losers.push(p1Char);
    }
    if (!p2Char->isDead())
    {
      p2Char->heal();
      teams[1].push(p2Char);
    }
    else {
      losers.push(p2Char);
    }
  }
  if (teams[0].empty() && teams[1].empty())
  {
    cout << "Draw!" << endl;
  }
  else if(teams[0].empty()) {
    cout << "Team 2 wins!" << endl << endl;
  }
  else if(teams[1].empty()) {
    cout << "Team 1 wins!" << endl << endl;
  } 

  /*
  for (int i = 0; i < losers.size(); ++i) {
    cout << "Team:" << losers.getTeamName() << "Name" << losers.getName();
  }
  
  for (int k = 0; k < teams.size(); ++k) {
    teams[k];
    for (int j = 0; j < count; ++j) {
      cout << "Team:" << teams.getTeamName() << "Name" << teams.getName();
    }
  }
  */
}

/*****************************************************
** Function: getName()
** Description: This is the function to get creature name.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: returns name. 
*******************************************************/
void Battle::displayTopThree() {
  vector<Creature*> allPLayers;

  while(!losers.empty()) {
    allPLayers.push_back(losers.top());
    losers.pop();
  }
  while(!teams[0].empty()) {
    allPLayers.push_back(teams[0].front());
    teams[0].pop();
  }
  while(!teams[1].empty()) {
    allPLayers.push_back(teams[1].front());
    teams[1].pop();
  }

  cout << "pre-sort" << endl;

  sort(allPLayers.begin(), allPLayers.end(), creatureSort);

  cout << "Top Combatants: " << endl;

  int sizeCount = allPLayers.size();
  
  if (sizeCount > 3)
  {
    sizeCount = 3;
  }

  for (int i = 0; i < sizeCount; ++i)
  {
    Creature* plyr = allPLayers[i];
    cout << i + 1 << ": ";
    cout << plyr->getName(); 
    cout << " (" << plyr->getType() << ") ";
    cout << plyr->getPoints() << " ";
    cout << plyr->getTeamName() << endl;
  } 
}

bool Battle::creatureSort(Creature* x, Creature* y) {
  return (x->getPoints() > y->getPoints());
}
