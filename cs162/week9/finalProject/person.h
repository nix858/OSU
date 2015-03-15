#ifndef PERSON
#define PERSON
#include <string>
#include <vector>
#include <iostream>
#include "question.h"
#include "location.h"

using namespace std;

class Person : public Location {
  vector<Question*> questions;
  bool wonClue();
public:
  void addQuestion(Question* q);
  virtual string getLabel();
};

#endif