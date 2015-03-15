#include "bounty.h"
#include <string>

virtual string Bounty::getLabel() {
  retun this->name;
}

void Bounty::setName(string name) {
  this->name = name;
}

void Bounty::setValue(int val) {
  this->value = val;
}

int Bounty::getValue() {
  return this->value;
}