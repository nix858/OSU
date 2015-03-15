#ifndef PERSON
#define PERSON
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Person : public Location {
  vector<Question> questions;
  void addQuestion(Question q);
  bool wonClue();
};

#endif;