#include "item.h"
#include "groceryList.h"
#include "listManager.h"
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

/****************************************************************** 
** Function: addItem()
** Description: This function will get the user input to add an item.
   It then adds this input to a instance of item called newItem and 
   then calls GroceryList::addItem() to add the item to the list.
** Parameters: None
** Pre-Conditions: None.
** Post-Conditions: Item added to groceryList. 
*******************************************************************/
void ListManager::addItem() {
    string name;
    string unitInput;
    string quantity;
    bool validQuantity = true;
    string price;
    bool validPrice= true;
    Item newItem;

    cout << "Add Item to shopping List: " << endl;
    cout << "Enter item name: " << endl;
    getline(cin, name);
    newItem.setName(name);

    cout << "Enter unit. Example: Can, Pound, Ounce, Bunch, Liter, Other: " << endl;
    cin >> unitInput;
    newItem.setUnit(unitInput);
    cin.ignore();

    do {
       
        validQuantity = true; 
        cout << "Enter quantity: " << endl;
        getline(cin, quantity);

        for (uint i = 0; i < quantity.length(); ++i) {
            if ((!isdigit(quantity[i])) && quantity[i] != '.') {
                validQuantity = false;
                cin.clear();
            }
        }  
        if (quantity.empty()) {
            validQuantity = false;
            cin.clear();
        }
        if (!validQuantity) {
            cout << "Invalid input. Retry" << endl;
        } 

    } while (!validQuantity);

    double newQuantity = atof(quantity.c_str());
    newItem.setQuantity(newQuantity);

    do {
       
        validPrice = true; 
        cout << "Enter price: " << endl;
        getline(cin, price);

        for (uint i = 0; i < price.length(); ++i) {
            if ((!isdigit(price[i])) && price[i] != '.') {
                validPrice = false;
                cin.clear();
            }
        }
        if (price.empty()) {
            validPrice = false;
            cin.clear();
        }
        if (!validPrice) {
            cout << "Invalid input. Retry" << endl;
        } 

    } while (!validPrice);

    double newPrice = atof(price.c_str());
    newItem.setPrice(newPrice);

    groceryList.addItem(newItem);
    cout << "Item " << name << " has been added to shopping list." << endl;
}

/****************************************************************** 
** Function: removeItem()
** Description: This function gets user input to remove an item.
   It then calls GroceryList::removeItem() to remove the item.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: Item removed from groceryList. 
*******************************************************************/
void ListManager::removeItem() {
    uint selection;
    bool validSelection = true;

    displayList();

    do {
        validSelection = true;
        cout << "Select an item number from the list to remove: " << endl;
        cin >> selection;
        cin.ignore();

        cout << "list size:" << groceryList.items.size() << endl;

        if (selection < groceryList.items.size() || 
            selection > groceryList.items.size()) {
            
            cout << "Invalid selection." << endl;
            validSelection = false;
        }
    } while (!validSelection);

   groceryList.removeItem(selection); 

   cout << "Item " << selection << " has been removed." << endl; 
}

/****************************************************************** 
** Function: displayList()
** Description: This function displays the shopping list.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None 
*******************************************************************/
void ListManager::displayList() {
 
    cout << "Shopping List Items" << endl;
    cout << setw(12) << right << "Item Name" <<
            setw(15) << right << "Unit" << 
            setw(14) << right << "Quantity" << 
            setw(9) << right << "Price" << 
            setw(16) << right << "Sub-total" << endl;
   
    for (uint i = 0; i < groceryList.items.size(); ++i) {
      cout << setw(2) << right << i+1 <<setw(1) << right << "." <<
              setw(20) << left << groceryList.items[i].getName() <<
              setw(10) << left << groceryList.items[i].getUnit() <<
              setw(10) << left << groceryList.items[i].getQuantity() <<  
              setw(3) << right << "$" << fixed << setprecision(2) << 
                          left << groceryList.items[i].getPrice() <<
              setw(8) << right << "$" << fixed << setprecision(2) << 
                          right << groceryList.items[i].getTotal() << endl;
    }

    cout << "List total: " << "$" << setw(6) << left << groceryList.getTotal() << endl;
}

/****************************************************************** 
** Function: savFile()
** Description: This function saves the groceryList to a file.
** Parameters: None
** Pre-Conditions: A groceryList has been created.
** Post-Conditions:A file called shoppingList.txt has been created. 
*******************************************************************/
void ListManager::saveFile() {
    ofstream outputFile;
    outputFile.open("shoppingList.txt");

    for (uint i = 0; i < groceryList.items.size(); ++i)
    {
        outputFile << groceryList.items[i].getName() << " ";
        outputFile << groceryList.items[i].getUnit() << " ";
        outputFile << groceryList.items[i].getQuantity() << " ";
        outputFile << groceryList.items[i].getPrice() << endl;
    }

    outputFile.close();

    cout << "Shopping list file has been saved." << endl;
}

/****************************************************************** 
** Function: loadfile()
** Description: This function opens a file.
** Parameters: None
** Pre-Conditions: None.
** Post-Conditions: File has been opened or user informed file not opened. 
*******************************************************************/
void ListManager::loadFile() {
   
    ifstream inputFile;
    inputFile.open("shoppingList.txt");

    if(inputFile.fail()) {
        cout << "Error. File did not open!";
        return;
    }
    else {
        groceryList.items.clear();

        char ch = inputFile.peek();     //peek at first character
        while(ch != EOF) {
            Item newItem;
            string name;
            string unit;
            int qty;
            double price;

            inputFile >> name;
            newItem.setName(name);

            inputFile >> unit;
            newItem.setUnit(unit);

            inputFile >> qty;
            newItem.setQuantity(qty);

            inputFile >> price;
            newItem.setPrice(price);
            inputFile.ignore();

            groceryList.addItem(newItem);

            ch = inputFile.peek();
        }
    }
    inputFile.close();
    cout << "Shopping list file has been opened." << endl;
}

/****************************************************************** 
** Function: runMenu()
** Description: This function displays the menu for the shopping list and 
   gets user input for their selection. Which then calls corresponding 
   functions accordingly.
** Parameters: None
** Pre-Conditions: None
** Post-Conditions: None 
*******************************************************************/
void ListManager::runMenu() {
    int menuSelection;
    bool selectionValid = true;
    bool shouldContinue= true;

    do {
        do {
            system("clear");
            cin.clear();
        
            selectionValid = true;
            cout << "Please select 1-6 from the menu: " << endl;
            cout << "1. Open list from file " << endl;
            cout << "2. Add an item " << endl;
            cout << "3. Remove an item " << endl;
            cout << "4. Display list " << endl;
            cout << "5. Save list " << endl;
            cout << "6. Quit" << endl;
            cin >> menuSelection;

            if (menuSelection < 1 ||  menuSelection > 6 || cin.fail()) {
                cout << "Invalid input. Hit enter to continue." << endl;
                selectionValid = false;

                cin.clear();
                cin.ignore(1000, '\n');
                cin.get();
            }
            cin.ignore();
        } while (!selectionValid);

        switch(menuSelection) {
            case 1:
                loadFile();
                break;
            case 2:
                addItem();
                break;
            case 3:
                removeItem();
                break;
            case 4:
                displayList();
                break;
            case 5:
                saveFile();
                break;
            default:
                cout << "Good Bye." << endl;
                shouldContinue = false;
        }  
        cout << "Press enter to continue";
        cin.get();

    } while (shouldContinue);
}



