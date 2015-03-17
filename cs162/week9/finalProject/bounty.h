#ifndef BOUNTY
#define BOUNTY
#include <string>
#include "gameEntity.h"

using namespace std;

class Bounty : public GameEntity {
  string name;
  int value;
  string crime;
public:
  int getValue();
  void setValue(int val);
  void setName(string name);
  void setCrime(string crime);
  virtual string getLabel();
};

#endif