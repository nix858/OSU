#ifndef GAMEENT
#define GAMEENT
#include <string>

using namespace std;
  
class GameEntity {
protected:
  int cost;
public:
  virtual string getLabel() = 0;
  void setCost(int cost);
  int getCost();
};

#endif