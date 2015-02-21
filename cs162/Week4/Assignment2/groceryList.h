#ifndef GROCERYLIST
#define GROCERYLIST
#include "item.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class GroceryList {

public:
    vector<Item> items;
    
    void addItem(Item item);
    void removeItem(int selection);
    double getTotal();
};

#endif