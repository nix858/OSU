#include <string>
#include <vector>
#include <iostream>

using namespace std;


  
Menu::Menu(string prompt, vector<MenuItem*> items) {
  this->items = items;
  this->prompt = prompt;
}

MenuItem* Menu::run() {
  cout << prompt << ":" << endls;
  for (uint i = 0; i < items.size(); ++i)
  {
    cout << i << ": " << items[i]->getLabel() << endl;
  }

  bool validSelection = true;
  int selection;
  do
  {
    // do selection
  } while (!validSelection);

  return items[selection];
}



#endif;