#include "Inventory.h"

#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "Equipment.h"
#include "Fruit.h"
#include "Grain.h"
#include "Plant.h"

using namespace std;

// default constructor sets values as 0 or false
Inventory::Inventory() {
  plantCapacity = 0;
  equipmentCapacity = 0;
  funds = 0;
  grain = 0;
  fruit = 0;
  isOpen = false;
};

// standard constructor takes 2 inputs and sets the amount of plants/equipment
// as required, setting the rest as 0
Inventory::Inventory(int p, int e) {
  plantCapacity = p;
  equipmentCapacity = e;
  funds = 0;
  grain = 0;
  fruit = 0;
  isOpen = false;
}

// following 3 functions open/close/return the current status (open or closed)
// of the inventory
void Inventory::openInventory() { isOpen = true; }
void Inventory::closeInventory() { isOpen = false; }
bool Inventory::inventoryOpen() { return isOpen; }

// the following 3 functions alter the current aamount of funds/grain/fruit on
// hand. if the result is negative, the amount will be set to 0
void Inventory::changeFunds(double amount) {
  if ((funds + amount) >= 0) {
    funds = (funds + amount);
  } else if ((funds + amount) < 0) {
    funds = 0;
  }
}
void Inventory::changeGrain(int amount) {
  if ((grain + amount) >= 0) {
    grain = (grain + amount);
  } else if ((grain + amount) < 0) {
    grain = 0;
  }
}
void Inventory::changeFruit(int amount) {
  if ((fruit + amount) >= 0) {
    fruit = (fruit + amount);
  } else if ((fruit + amount) < 0) {
    fruit = 0;
  }
}

// These 3 functions return the current funds, grain and fruit respectively
double Inventory::getFunds() { return funds; }
int Inventory::getGrain() { return grain; }
int Inventory::getFruit() { return fruit; }

// the addPlant function uses an unordered map and an id to add a plant to the
// inventory, so long as there is space. Will only work if inventory is open
void Inventory::addPlant(const Plant& p1) {
  if (isOpen == true) {
    if (plantInventory.size() < plantCapacity) {
      plantInventory[p1.getID()] = p1;
      cout << "Plant with id " << p1.getID() << " was added" << endl;
    } else {
      cout << "Unable to add more Plants - Inventory full" << endl;
    }
  } else {
    cout << "Unable, Inventory not open" << endl;
  }
}

// the removePlant function uses an auto tracker value wth a map and an id
// to remove a plant fromthe inventory, if it exists there. Will only work if
// inventory is open
void Inventory::removePlant(int plantID) {
  if (isOpen == true) {
    auto it = plantInventory.find(plantID);
    if (it != plantInventory.end()) {
      plantInventory.erase(it);
      cout << "Plant with id " << plantID << " was removed" << endl;
    } else {
      cout << "Unable to remove Plant - Item not in inventory" << endl;
    }
  } else {
    cout << "Unable, Inventory not open" << endl;
  }
}

// the addEquipment function uses an unordered map and an id to add Equipment to
// the inventory, so long as there is space. Will only work if inventory is open
void Inventory::addEquipment(const Equipment& e1) {
  if (isOpen == true) {
    if (equipInventory.size() < equipmentCapacity) {
      equipInventory[e1.getID()] = e1;
      cout << "Equipment with id " << e1.getID() << " was added" << endl;
    } else {
      cout << "Unable to add more Equipment - Inventory full" << endl;
    }
  } else {
    cout << "Unable, Inventory not open" << endl;
  }
}

// the removeEquipment function uses an auto tracker value wth a map and an id
// to remove Equipment fromthe inventory, if it exists there. Will only work if
// inventory is open
void Inventory::removeEquipment(int EquipmentID) {
  if (isOpen == true) {
    auto it = equipInventory.find(EquipmentID);
    if (it != equipInventory.end()) {
      equipInventory.erase(it);
      cout << "Equipment with id " << EquipmentID << " was removed" << endl;
    } else {
      cout << "Unable to remove Equipment - Item not in inventory" << endl;
    }
  } else {
    cout << "Unable, Inventory not open" << endl;
  }
}
