#ifndef ITEM
#define ITEM
#include <string>
#include <iostream>

using namespace std;

class Item {
private:
    string name;
    string unit;  
    double price;
    double quantity;

public:
    string getName();
    string getUnit();
    double getPrice();
    double getQuantity();

    void setName(string name); 
    void setUnit(string unit);
    void setPrice(double price);
    void setQuantity(double quantity);
    double getTotal();
};

#endif