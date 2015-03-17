#ifndef INVITEM
#define INVITEM
#include <string>
#include "gameEntity.h"

using namespace std;
  
class InventoryItem {
  int pointValue;
  string label;
public:
  int getPointValue();
  void setPointValue(int pointVal);
  virtual string getLabel();
  void setLabel(string label);
};

#endif