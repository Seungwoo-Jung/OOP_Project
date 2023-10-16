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
    exists = false;
}

// standard constructor takes 2 inputs and sets the amount of plants/equipment
// as required, setting the rest as 0. It creates 3 plants and 1 equipment for
// the player to use by default
Inventory::Inventory(int p, int e) {
    exists = true;
    plantCapacity = p;
    equipmentCapacity = e;
    funds = 0;
    grain = 0;
    fruit = 0;
    isOpen = true;

    addPlant(new Fruit(1, "Apple", 50, 2, 5));
    addPlant(new Grain(2, "Wheat", 20, 10, 2));
    addPlant(new Grain(3, "Rice", 20, 15, 2));
    addEquipment(new Equipment(4, "shovel", 50, 1, 50));

    isOpen = false;
}

// getcontents function prints out all the current contents of the inventory.
// Only activates if inventory is Open and exists

void Inventory::getContents() {
    if (isOpen == true && exists == true) {
        cout << endl << "Tradeable goods: " << endl << endl;
        cout << "Current Funds: " << getFunds() << "." << endl;
        cout << "Current Fruit: " << getFruit() << "." << endl;
        cout << "Current Grain: " << getGrain() << "." << endl;
        cout << endl << "Plants: " << endl << endl;
        if (!plantInventory.empty()) {
        for (auto& pair : plantInventory) {
            pair.second->getStatus();
        }
        } else {
        cout << "No plants currently in Hand" << endl;
        }

        cout << endl << "Equipment: " << endl << endl;
        if (!equipInventory.empty()) {
        for (auto& pair : equipInventory) {
            pair.second->getStatus();
        }
        } else {
        cout << "No Equipment currently in Hand" << endl;
        }

        cout << endl;
    } else if (isOpen == false && exists == true) {
        cout << "Unable, Inventory not open" << endl;
    } else {
        cout << "Unable, Inventory does not exist" << endl;
    }
}

// following 3 functions open/close/return the current status (open or closed)
// of the inventory, and calls the getContents function if opening. Only
// activate if Inventory exists
void Inventory::openInventory() {
    if (exists == true) {
        isOpen = true;
        cout << "Opening Inventory: " << endl;
        getContents();
    } else {
        cout << "Unable, Inventory does not exist" << endl;
    }
}

void Inventory::closeInventory() {
    if (exists == true && isOpen == true) {
        isOpen = false;
        cout << "Closing inventory: " << endl;
    } else if (exists == true && isOpen == false) {
        cout << "Unable, Inventory not open" << endl;
    } else {
        cout << "Unable, Inventory does not exist" << endl;
    }
}

bool Inventory::inventoryOpen() {
    if (exists == true) {
        return isOpen;
    } else {
        cout << "Unable, Inventory does not exist" << endl;
    }
}

// the following 3 functions alter the current aamount of funds/grain/fruit on
// hand. if the result is negative, the amount will be set to 0. Only activate
// if Inventory exists
void Inventory::changeFunds(double amount) {
    if (exists == true) {
        if ((funds + amount) >= 0) {
        funds = (funds + amount);
        } else if ((funds + amount) < 0) {
        funds = 0;
        }
    } else {
        cout << "Unable, Inventory does not exist" << endl;
    }
}

void Inventory::changeGrain(int amount) {
    if (exists == true) {
        if ((grain + amount) >= 0) {
        grain = (grain + amount);
        } else if ((grain + amount) < 0) {
        grain = 0;
        }
    } else {
        cout << "Unable, Inventory does not exist" << endl;
    }
}

void Inventory::changeFruit(int amount) {
    if (exists == true) {
        if ((fruit + amount) >= 0) {
        fruit = (fruit + amount);
        } else if ((fruit + amount) < 0) {
        fruit = 0;
        }
    } else {
        cout << "Unable, Inventory does not exist" << endl;
    }
}

// These 3 functions return the current funds, grain and fruit respectively
double Inventory::getFunds() {
    if (exists == true) {
        return funds;
    } else {
        cout << "Unable, Inventory does not exist" << endl;
    }
}

int Inventory::getGrain() {
    if (exists == true) {
        return grain;
    } else {
        cout << "Unable, Inventory does not exist" << endl;
    }
}

int Inventory::getFruit() {
    if (exists == true) {
        return fruit;
    } else {
        cout << "Unable, Inventory does not exist" << endl;
    }
}

// the addPlant function uses an unordered map and an id to add a plant to the
// inventory, so long as there is space. Will only work if inventory is open and
// exists
void Inventory::addPlant(Plant* p1) {
    if (isOpen == true && exists == true) {
        if (plantInventory.size() < plantCapacity) {
        plantInventory[p1->getID()] = p1;
        cout << "Plant with id " << p1->getID() << " was added" << endl;
        } else {
        cout << "Unable to add more Plants - Inventory full" << endl;
        }
    } else if (isOpen == false && exists == true) {
        cout << "Unable, Inventory not open" << endl;
    } else {
        cout << "Unable, Inventory does not exist" << endl;
    }
}

// the removePlant function uses an auto tracker value wth a map and an id
// to remove a plant from the inventory, if it exists there. Will only work if
// inventory is open and exists
void Inventory::removePlant(int plantID) {
    if (isOpen == true && exists == true) {
        auto it = plantInventory.find(plantID);
        if (it != plantInventory.end()) {
        plantInventory.erase(it);
        cout << "Plant with id " << plantID << " was removed" << endl;
        } else {
        cout << "Unable to remove Plant - Item not in inventory" << endl;
        }
    } else if (isOpen == false && exists == true) {
        cout << "Unable, Inventory not open" << endl;
    } else {
        cout << "Unable, Inventory does not exist" << endl;
    }
}

// the addEquipment function uses an unordered map and an id to add Equipment to
// the inventory, so long as there is space. Will only work if inventory is open
// and exists
void Inventory::addEquipment(Equipment* e1) {
    if (isOpen == true && exists == true) {
        if (equipInventory.size() < equipmentCapacity) {
        equipInventory[e1->getID()] = e1;
        cout << "Equipment with id " << e1->getID() << " was added" << endl;
        } else {
        cout << "Unable to add more Equipment - Inventory full" << endl;
        }
    } else if (isOpen == false && exists == true) {
        cout << "Unable, Inventory not open" << endl;
    } else {
        cout << "Unable, Inventory does not exist" << endl;
    }
}

// the removeEquipment function uses an auto tracker value wth a map and an id
// to remove Equipment fromthe inventory, if it exists there. Will only work if
// inventory is open and exists
void Inventory::removeEquipment(int EquipmentID) {
    if (isOpen == true && exists == true) {
        auto it = equipInventory.find(EquipmentID);
        if (it != equipInventory.end()) {
        equipInventory.erase(it);
        cout << "Equipment with id " << EquipmentID << " was removed" << endl;
        } else {
        cout << "Unable to remove Equipment - Item not in inventory" << endl;
        }
    } else if (isOpen == false && exists == true) {
        cout << "Unable, Inventory not open" << endl;
    } else {
        cout << "Unable, Inventory does not exist" << endl;
    }
}

// destructor deletes the Inventory as well as all objects within it
Inventory::~Inventory() {
    for (auto& pair : plantInventory) {
        delete pair.second;
    }
    for (auto& pair : equipInventory) {
        delete pair.second;
    }
};