#include <string>
#include <iostream>
#include "person.h"
#include "gameEntity.h"
#include "gameState.h"
#include "question.h"


void Person::selectAction(GameState* gameState) {
  cout << "Talking to " << this->getLabel();
  Menu talkMenu("What do you want to say?", this->questions); 
  Question q = (Question)talkMenu.run();
  gameState->money -= q.getCost();
  cout << '\t' << q.getAnswer() << endl;

  if (wonClue())
  {
    cout << q.getClueSegue(); << "... ";
    cout << gameState->bountyLocation->getClue(gameState.clueLevel);
  }

  gameState->currentLocation = gameState->returnLocation;
}

bool Person::wonClue() {
  //TODO: coin flip? roll dice?
  return true;
}

void Person::addQuestion(Question q) {
  questions.push_back(q);
}

string Person::getLabel() {
  return "bar tender";
}