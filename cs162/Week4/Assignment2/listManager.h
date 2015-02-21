#ifndef LISTMANAGER
#define LISTMANAGER
#include "item.h"
#include "groceryList.h"
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>


using namespace std;

class ListManager { 

public:
    GroceryList groceryList;

    void addItem();
    void removeItem();
    void displayList();
    void saveFile();
    void loadFile();
    void runMenu();
};

#endif