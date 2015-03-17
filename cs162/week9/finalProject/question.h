#ifndef QUESTION
#define QUESTION
#include "gameEntity.h"
#include <string>
#include <vector>

class Question : public GameEntity {
  int odds;
  string question;
  string clueSegue;
  vector<string> answers;
  vector<string> clueSegues;
  
public:
  GameEntity* saleItem;

  void addAnswer(string ans);
  string getAnswer();
  
  void addClueSegue(string seg);
  string getClueSegue();
  
  void setOdds(int odds);
  int getOdds();

  string getLabel();
  
  Question(string q);
};

#endif