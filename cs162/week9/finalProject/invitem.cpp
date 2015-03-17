#include "invitem.h"

int InventoryItem::getPointValue() {
  return pointValue;
}

void InventoryItem::setPointValue(int pointVal) {
  this->pointValue = pointVal;
}

string InventoryItem::getLabel() {
  return label;
}

void InventoryItem::setLabel(string label) {
  this->label = label;
}