/*********************************************************************  
** Program Filename: shoppingList.cpp
** Author: Nicole Parker    
** Date: 1/28/2015
** Description: This is a grocery list program. The program contains a 
   item class, listManager class and groceryList class. Item class contains
   item information such as name, price, quantity and unit. GroceryList class 
   contains a vector of items called items, and functions to add an item to 
   the vector, remove an item from the vector and get the total of the vector. 
   ListManager class contains an instance of GroceryList, and functions which 
   get user input for adding an item, removing an item, saving to file and 
   loading a file. The menu is also contained in listManger. 
**Input:The user is able to enter information for adding an item including 
   name, unit, quantity and price. The user can also select items to remove 
   from the list.
**Output: The output is the display of the shopping list. In addition the
   user is informed if input is invalid. User is also informed it a file
   did not open, if a file saved and if a file loaded. 
***********************************************************************/


#include "listManager.h"
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    ListManager listManager;
    listManager.runMenu();
    return 0;
}