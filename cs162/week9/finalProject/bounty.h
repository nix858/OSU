#ifndef BOUNTY
#define BOUNTY
#include <string>
#include "gameEntity.h"

using namespace std;

class Bounty : public GameEntity {
  string name;
  int value;
public:
  int getValue();
  void setValue(int val);
  void setName(string name);
  virtual string getLabel();
};

#endif