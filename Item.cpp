#include "Item.h"
#include <string>
#include <fstream>

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
Item::Item(int setID, string setname, string setstatus, int life, int setPrice) {
    ID = setID;
    name = setname;
    status = setstatus;
    lifespan = life;
    price = setPrice;
}

// returns the id of the item for reference
int Item::getID() const { return ID; }

// empty destructor
Item::~Item() {}