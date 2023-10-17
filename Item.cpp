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
  price = 0;
}

// standard conctructor sets variables equivalent to the input values
Item::Item(int setID, string setname, string setstatus, int life,
           double setPrice) {
  ID = setID;
  name = setname;
  status = setstatus;
  lifespan = life;
  price = setPrice;
}

// returns the id of the item for reference
int Item::getID() const { return ID; }
double Item::getPrice() { return price; }
void Item::setPrice(double newPrice) { price = newPrice; }

// empty destructor
Item::~Item() {}