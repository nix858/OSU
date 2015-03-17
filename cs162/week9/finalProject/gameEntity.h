#ifndef GAMEENT
#define GAMEENT
#include <string>
#include "random.h"

using namespace std;
  
class GameEntity {
protected:
  int cost;
  Random rnd;
public:
  virtual string getLabel() = 0;
  void setCost(int cost);
  int getCost();
};

#endif