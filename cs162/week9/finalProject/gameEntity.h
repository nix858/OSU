#ifndef GAMEENT
#define GAMEENT
#include <string>

using namespace std;

class GameEntity {
public:
  virtual string getType() = 0;
  virtual string getLabel() = 0;
};

#endif;