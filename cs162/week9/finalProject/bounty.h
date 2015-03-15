#ifndef BOUNTY
#define BOUNTY
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Bounty : public GameEntity {
  string name;
  int value;
public:
  int getValue();
  void setValue(int val);
  void setName(string name);
};

#endif;