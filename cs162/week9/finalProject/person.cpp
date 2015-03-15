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
  cout << '\t' << q->getAnswer() << endl;

  if (wonClue())
  {
    cout << q->getClueSegue() << "... ";
    cout << gameState->bountyLocation->getClue(gameState->clueLevel) << endl;
  }

}

bool Person::wonClue() {
  //TODO: coin flip? roll dice?
  return true;
}

void Person::addQuestion(Question* q) {
  questions.push_back(q);
}

string Person::getLabel() {
  return "bar tender";
}