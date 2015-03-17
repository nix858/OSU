#include <string>
#include <iostream>
#include "person.h"
#include "gameEntity.h"
#include "gameState.h"
#include "question.h"
#include "menu.h"


void Person::selectAction(GameState* gameState) {
  cout << "Talking to " << this->getLabel() << endl;
  Menu talkMenu((char*)"What do you want to say?", this->questions);
  GameEntity* back = gameState->locationHistory->top();
  GameEntity* sel = talkMenu.run(back);
  
  if (sel == back)
  {
    gameState->currentLocation = (Location*)sel;
    gameState->locationHistory->pop();
    return; 
  }
  
  Question* q = (Question*)sel;
  gameState->money -= q->getCost();
  cout << '\t' << '"' << q->getAnswer() << '"' << endl;

  if (q->saleItem) {
    gameState->inventory.push_back(q->saleItem);
  } else {
    if (wonClue(q->getOdds()))
    {
      string clue = gameState->bountyLocation->getClue(gameState->clueLevel);
      cout << '\t' << '"' << q->getClueSegue() << "... ";
      cout << clue << '"' << endl << endl;
      gameState->clueLevel += 1;
      gameState->clues.push_back(clue);
    }
  }
  
  cin.ignore(10000,'\n');
  cout << "press enter to continue.";
  cin.get();
}

bool Person::wonClue(int odds) {
  int res = rnd.between(1, odds);  
  return res == 1;
}

void Person::addQuestion(Question* q) {
  questions.push_back(q);
}