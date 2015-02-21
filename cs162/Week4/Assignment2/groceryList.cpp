#include "item.h"
#include "groceryList.h"
#include <string>
#include <iostream>
#include <vector>

using namespace std;

/****************************************************************** 
** Function: addItem()
** Description: This function will add an item to the vector items.
** Parameters: Takes an instance of Item.
** Pre-Conditions: Vector has been created
** Post-Conditions: Item added to vector items. 
*******************************************************************/
void GroceryList::addItem(Item item) {
    items.push_back(item);
}

/****************************************************************** 
** Function: removeItem()
** Description: This function removes an item from the vector items.
** Parameters: Takes an int selection which is input by the user.
** Pre-Conditions: Vector contains items.
** Post-Conditions: Item removed from vector items. 
*******************************************************************/
void GroceryList::removeItem(int selection) {
    items.erase(items.begin() + selection);
}

/****************************************************************** 
** Function: getTotal()
** Description: This function gets the total of the vector items.
** Parameters: None
** Pre-Conditions: Vector contains items.
** Post-Conditions: Total of the vector items is returned. 
*******************************************************************/
double GroceryList::getTotal() {
    double total = 0;

    for (uint i = 0; i < items.size(); ++i)
    {
        total += (items[i].getPrice() * items[i].getQuantity());
    }

    return  total;
}








