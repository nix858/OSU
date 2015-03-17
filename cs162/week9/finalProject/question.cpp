#include "question.h"
#include <string>
#include <sstream>

Question::Question(string q) {
  this->question = q;
  this->cost = 0; //default
  this->odds = 5;
}

void Question::addAnswer(string ans) {
  this->answers.push_back(ans);
}

string Question::getAnswer() {
  int ansIndex = rnd.between(0, answers.size() - 1);
  return answers[ansIndex];
}

void Question::addClueSegue(string seg) {
  clueSegues.push_back(seg);
}

string Question::getClueSegue() {
  int clueSegIndex = rnd.between(0, clueSegues.size() - 1);
  return clueSegues[clueSegIndex];
}

void Question::setOdds(int odds) {
  this->odds = odds;
}

int Question::getOdds() {
  return this->odds;
}

string Question::getLabel() {
  stringstream suffix;
  if (cost > 0)
  {
    suffix << " ($" << cost << ")";
  }
  return question + suffix.str();
}