#include "question.h"
#include <string>
#include <sstream>

Question::Question(string q) {
  this->question = q;
  this->cost = 0; //default
}

void Question::addAnswer(string ans) {
  this->answers.push_back(ans);
}

void Question::addClueSegue(string seg) {
  clueSegues.push_back(seg);
}

string Question::getClueSegue() {
  //TODO: random selection
  return clueSegues[0];
}

string Question::getLabel() {
  stringstream suffix;
  if (cost > 0)
  {
    suffix << " ($" << cost << ")";
  }
  return question + suffix.str();
}

string Question::getAnswer() {
  //TODO: random ans
  return answers[0];
}