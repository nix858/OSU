#include <string>
#include <iostream>
#include <vector>
#include "item.h"

using namespace std;

/*********************************************************************  
** Function: getName()
** Description: This is the getter function for name.
** Parameters:  None
** Pre-Conditions: None
** Post-Conditions: Return the value of name. 
**************************************************/
string Item::getName() {
    return name;
}

/*********************************************************************  
** Function: getUnit()
** Description: This is the getter function for unit.
** Parameters:  None
** Pre-Conditions: None
** Post-Conditions: Return the value of unit. 
**************************************************/
string Item::getUnit() {
    return unit;
}

/*********************************************************************  
** Function: getPrice()
** Description: This is the getter function for price.
** Parameters:  None
** Pre-Conditions: None
** Post-Conditions: Return the value of price. 
**************************************************/
double Item::getPrice() {
    return price;
}

/*********************************************************************  
** Function: getQuantity()
** Description: This is the getter function for quantity.
** Parameters:  None
** Pre-Conditions: None
** Post-Conditions: Return the value of quantity. 
**************************************************/
double Item::getQuantity() {
    return quantity;
}

/*******************************************************  
** Function: setName()
** Description: This is the setter function for name.
** Parameters:  Takes a string name.
** Pre-Conditions: None
** Post-Conditions: Sets the value of name. 
*******************************************************/
void Item::setName(string name) {
    this->name = name;
}

/******************************************************* 
** Function: setUnit()
** Description: This is the setter function for unit.
** Parameters:  Takes a string unit.
** Pre-Conditions: None
** Post-Conditions: Sets the value of unit. 
*******************************************************/
void Item::setUnit(string unit) {
    this->unit = unit;
}

/******************************************************* 
** Function: setPrice()
** Description: This is the setter function for price.
** Parameters:  Takes a double price.
** Pre-Conditions: None
** Post-Conditions: Sets the value of price. 
*******************************************************/
void Item::setPrice(double price) {
    this->price = price;
}

/******************************************************* 
** Function: setQuantity()
** Description: This is the setter function for quantity.
** Parameters:  Takes a double quantty.
** Pre-Conditions: None
** Post-Conditions: Sets the value of quantity. 
*******************************************************/
void Item::setQuantity(double quantity) {
    this->quantity = quantity;
} 

/******************************************************* 
** Function: getTotal()
** Description: This fuction calculates the total.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Total is calculated. 
*******************************************************/
double Item::getTotal() {
    return quantity * price;
}



