#ifndef QUESTION
#define QUESTION
#include "gameEntity.h"
#include <string>

class Question : public GameEntity {
  int cost;
  string question;
  string clueSegue;
  vector<string> answers;
  vector<string> clueSegues;

public:
  void addAnswer(string ans);
  void addClueSegue(string seg);
  void setCost(int cost);
  int getCost();
  string getAnswer();
  string getLabel();
  Question(string q);
};

#endif