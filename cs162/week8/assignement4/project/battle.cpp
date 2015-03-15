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

/*****************************************************
** Function: makeTestTeams()
** Description: This is the function I used to test the 
** makeTeams() It made testing multiple combinations easier.
** Parameters:  none
** Pre-Conditions: None
** Post-Conditions: none. 
*******************************************************/
/*void Battle::makeTestTeams() {
  Creature* g1 = new Barbarian();
  g1->setTeamName("team1");
  g1->setName("Oliver");
  this->teams[0].push(g1);

  Creature* g2 = new Goblin();
  g2->setTeamName("team2");
  g2->setName("Kitty");
  this->teams[1].push(g2);

  Creature* g3 = new Shadow();
  g3->setTeamName("team1");
  g3->setName("Black");
  this->teams[0].push(g3);

  Creature* g4 = new Reptile();
  g4->setTeamName("team2");
  g4->setName("Lizzy");
  this->teams[1].push(g4);

  Creature* g5 = new BlueMen();
  g5->setTeamName("team1");
  g5->setName("Blue");
  this->teams[0].push(g5);

  Creature* g6 = new BlueMen();
  g6->setTeamName("team2");
  g6->setName("Tobias");
  this->teams[1].push(g6);
}
*/

/*****************************************************
** Function: makeTeams()
** Description: This is the function to make the two teams. 
** It contains all input output from user, and adds new 
** players to their respective teams appropriatly.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: creates teams. 
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
** Function: fight()
** Description: This function will run a fight between two
** players, buy calling attack() for each player and checking
** to see if a player has died. It will also display if a player
** has died.
** Parameters: A Creature pointer for player1, and a Creature
** pointer for player2.
** Pre-Conditions: None
** Post-Conditions: 
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
    cout << endl << player1->getName() << " strength: " << player1->getStrength() << endl;
    cout << player2->getName() << " strength: " << player2->getStrength() << "\n\n\n";
    
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
** Function: doTournament()
** Description: This function runs a tournament with team
** one and team two, by calling the fight function. It also
** adds players to the loser stack, and displays which team
** has won the tournament.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Will add losers to the loser stack and 
** Cout which team has won the tournament. 
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
}

/*****************************************************
** Function: displayTopThree()
** Description: This is the function determines the top
** three players from the tournament based on their earned
** points, and then displays their info.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Displays top three players. 
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

/*****************************************************
** Function: creatureSort()
** Description: This is compares the points total for two
** players and returns which player has more points.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: returns the player with more points. 
*******************************************************/
bool Battle::creatureSort(Creature* x, Creature* y) {
  return (x->getPoints() > y->getPoints());
}
