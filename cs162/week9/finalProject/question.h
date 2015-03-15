#ifndef QUESTION
#define QUESTION
#include "gameEntity.h"
#include <string>
#include <vector>

class Question : public GameEntity {

  string question;
  string clueSegue;
  vector<string> answers;
  vector<string> clueSegues;

public:
  void addAnswer(string ans);
  string getAnswer();
  
  void addClueSegue(string seg);
  string getClueSegue();
  
  string getLabel();
  Question(string q);
};

#endif