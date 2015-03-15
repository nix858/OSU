#include "question.h"
#include <string>

Question::Question(string q) {
  this->question = q;
  this->cost = 0; //default
}

Question::addAnswer(string ans) {
  answers.push_back(ans);
}

Question::addClueSegue(string seg) {
  clueSegues.push_back(seg);
}

Question::setCost(int cost) {
  this->cost = cost;
}

int Question::getCost() {
  return this->cost;
}

Question::getLabel() {
  string suffix = "";
  if (cost > 0)
  {
    suffix = " ($" + cost.str() + ")";
  }
  return question + suffix;
}

Question::getAnswer() {
  //TODO: random ans
  return answers[0];
}