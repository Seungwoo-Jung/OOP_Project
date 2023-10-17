#include "Equipment.h"
<<<<<<< HEAD

#include <iostream>
#include <string>

=======
#include <iostream>
#include <string>
>>>>>>> 25f174546402ee47766097f73d4208065f575038
#include "Item.h"

// default contructor sets values as 0, false or null, and activates the default
// Item constructor
Equipment::Equipment() : Item() {
<<<<<<< HEAD
  ID = 0;
  name = "null";
  status = "null";
  lifespan = 0;
  equipped = false;
  effect = 0;
  currentUses = 0;
=======
    ID = 0;
    name = "null";
    status = "null";
    lifespan = 0;
    equipped = false;
    effect = 0;
    currentUses = 0;
>>>>>>> 25f174546402ee47766097f73d4208065f575038
};

// standard contructor feeds some value to the Item contructor, sets others as
// the input ones, equipped as false, and currentUses as 0
<<<<<<< HEAD
Equipment::Equipment(int setID, string setName, int totalUses, int impact)
    : Item(setID, setName, "functional", totalUses) {
  equipped = false;
  effect = impact;
  currentUses = 0;
=======
Equipment::Equipment(int setID, string setName, int totalUses, int impact, int setPrice) : Item(setID, setName, "functional", totalUses, price) {
    equipped = false;
    effect = impact;
    currentUses = 0;
    price = 0;
>>>>>>> 25f174546402ee47766097f73d4208065f575038
};

// destructor prints out message detailing deletion
Equipment::~Equipment() {
<<<<<<< HEAD
  cout << "Equipment with ID " << ID << " was deleted." << endl;
=======
    cout << "Equipment with ID " << ID << " was deleted." << endl;
>>>>>>> 25f174546402ee47766097f73d4208065f575038
}

// getStatus function prints out information about the item, including it's
// name, ID, current amount of uses, and lifespan. it then prints out the equip
// status based on the variable value, and the overall status of the item.
void Equipment::getStatus() {
<<<<<<< HEAD
  cout << "Equipment of type " << name << ", with ID " << ID << " and "
       << currentUses << " uses out of " << lifespan << ". ";
  if (equipped == true) {
    cout << "Currently equipped, providing an increase in growth rate by a "
            "factor of "
         << effect << ". ";
  } else {
    cout << "Currently unequipped. Can increase growth rate by a factor of "
         << effect << ". ";
  }
  cout << "Current status: " << status << "." << endl;
=======
    cout << "Equipment of type " << name << ", with ID " << ID << " and "
        << currentUses << " uses out of " << lifespan << ". ";
    if (equipped == true) {
        cout << "Currently equipped, providing an increase in growth rate by a "
                "factor of "
            << effect << ". ";
    } else {
        cout << "Currently unequipped. Can increase growth rate by a factor of "
            << effect << ". ";
    }
    cout << "Current status: " << status << "." << endl;
>>>>>>> 25f174546402ee47766097f73d4208065f575038
}

// itemEquipped function returns the equip status of the item
bool Equipment::itemEquipped() { return equipped; }

// equip function equips the item - if it exists
void Equipment::equip() {
<<<<<<< HEAD
  if (status != "null") {
    equipped = true;
  }
=======
    if (status != "null") {
        equipped = true;
    }
>>>>>>> 25f174546402ee47766097f73d4208065f575038
}

// unequip function unequips item - if it exists
void Equipment::unequip() {
<<<<<<< HEAD
  if (status != "null") {
    equipped = false;
  }
=======
    if (status != "null") {
        equipped = false;
    }
>>>>>>> 25f174546402ee47766097f73d4208065f575038
}

// use function uses the item depending on it's status. If the item exists, and
// is equipped and functional it will use it once. it will then print a message
// showing the amount of uses, and update the status to be broken once it
// reaches it's lifespan amount of uses, after which it will not be used Returns
// the effect on growth the item has.
int Equipment::use() {
<<<<<<< HEAD
  if (equipped == true && currentUses <= lifespan) {
    if (status != "broken") {
      currentUses = currentUses + 1;
      cout << "Uses: " << currentUses << " out of " << lifespan << "." << endl;
      if (currentUses == lifespan) {
        status = "broken";
      }
    }
    return effect;
  } else {
    return 0;
  }
=======
    if (equipped == true && currentUses <= lifespan) {
        if (status != "broken") {
        currentUses = currentUses + 1;
        cout << "Uses: " << currentUses << " out of " << lifespan << "." << endl;
        if (currentUses == lifespan) {
            status = "broken";
        }
        }
        return effect;
    } else {
        return 0;
    }
>>>>>>> 25f174546402ee47766097f73d4208065f575038
}