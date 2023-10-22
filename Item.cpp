#include "Item.h"

#include <fstream>
#include <string>

using namespace std;

// default contructor sets values as 0 or null
Item::Item() {
  ID = 0;
  name = "null";
  status = "null";
  lifespan = 0;
}

// standard conctructor sets variables equivalent to the input values
Item::Item(int setID, string setname, string setstatus, int life) {
  ID = setID;
  name = setname;
  status = setstatus;
  lifespan = life;
}

// returns the id of the item for reference
int Item::getID() const { return ID; }

// returns the item name for reference
string Item::getName() { return name; }

// returns the
string Item::getStat() { return status; }

// empty destructor
Item::~Item() {}