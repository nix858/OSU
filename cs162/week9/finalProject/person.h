#ifndef PERSON
#define PERSON
#include <string>
#include <vector>
#include <iostream>
#include "question.h"
#include "location.h"
#include "gameState.h"
#include "gameEntity.h"
#include "random.h"

using namespace std;

class Person : public Location {
  vector<GameEntity*> questions;
  bool wonClue(int odds);
public:
  void addQuestion(Question* q);
  virtual void selectAction(GameState* gameState);
};

#endif