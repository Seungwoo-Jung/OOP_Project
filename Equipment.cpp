#include "Equipment.h"

#include <iostream>
#include <string>

#include "Item.h"

// default contructor sets values as 0, false or null, and activates the default
// Item constructor
Equipment::Equipment() : Item() {
  ID = 0;
  name = "null";
  status = "null";
  lifespan = 0;
  equipped = false;
  effect = 0;
  currentUses = 0;
};

// standard contructor feeds some value to the Item contructor, sets others as
// the input ones, equipped as false, and currentUses as 0
Equipment::Equipment(int setID, string setName, int totalUses, int impact)
    : Item(setID, setName, "functional", totalUses) {
  equipped = false;
  effect = impact;
  currentUses = 0;
  if (setName == "Fertiliser" || setName == "fertiliser") {
    status = "usable";
  }
};

// destructor prints out message detailing deletion
Equipment::~Equipment() {
  cout << "Equipment with ID " << ID << " was deleted." << endl;
}

// getStatus function prints out information about the item, including it's
// name, ID, current amount of uses, and lifespan. it then prints out the equip
// status based on the variable value, and the overall status of the item.
void Equipment::getStatus() {
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
}

// returns the effect of the equipment for reference
int Equipment::getEffect() { return effect; }

// itemEquipped function returns the equip status of the item
bool Equipment::itemEquipped() { return equipped; }

// equip function equips the item - if it exists
void Equipment::equip() {
  if (status != "null") {
    if (equipped != true) {
      equipped = true;
      cout << name << " with ID " << ID << " equipped" << endl;
    } else {
      cout << "This item is already equipped" << endl;
    }
  }
}

// unequip function unequips item - if it exists
void Equipment::unequip() {
  if (status != "null") {
    if (equipped != false) {
      cout << name << " with ID " << ID << " unequipped" << endl;
      equipped = false;
    }
  }
}

// use function uses the item depending on it's status. If the item exists, and
// is equipped and functional it will use it once. it will then print a message
// showing the amount of uses, and update the status to be broken/empty once it
// reaches it's lifespan amount of uses, after which it will not be used Returns
// the effect on growth the item has.
int Equipment::use() {
  if (equipped == true && currentUses <= lifespan) {
    if (status != "broken") {
      currentUses = currentUses + 1;
      cout << name << " with ID " << ID << " was used." << endl;
      cout << "Current uses: " << currentUses << " out of " << lifespan << "."
           << endl;
      if (currentUses == lifespan) {
        if (name == "Fertiliser" || name == "fertiliser") {
          status = "empty";
        } else {
          status = "broken";
        }
      }
      cout << "status: " << status << "." << endl;
      if (status == "broken" || status == "empty") {
        effect = 1;
      }
    }
    return effect;
  } else {
    return 0;
  }
}