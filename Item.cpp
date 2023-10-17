#include "Item.h"
<<<<<<< HEAD

#include <string>
=======
#include <string>
#include <fstream>
>>>>>>> 25f174546402ee47766097f73d4208065f575038

using namespace std;

// default contructor sets values as 0 or null
Item::Item() {
<<<<<<< HEAD
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
=======
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
>>>>>>> 25f174546402ee47766097f73d4208065f575038
}

// returns the id of the item for reference
int Item::getID() const { return ID; }

// empty destructor
Item::~Item() {}