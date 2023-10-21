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
  wheat = 0;
  rice = 0;
  rye = 0;
  apple = 0;
  banana = 0;
  pear = 0;
  isOpen = false;
  exists = false;
  plantFull = false;
  equipFull = false;
  plantEmpty = true;
  equipEmpty = true;
}

// standard constructor takes 2 inputs and sets the amount of plants/equipment
// as required, setting the rest as 0. It creates 3 plants and 1 equipment for
// the player to use by default
Inventory::Inventory(int p, int e) {
  exists = true;
  plantCapacity = p;
  equipmentCapacity = e;
  funds = 0;
  wheat = 0;
  rice = 0;
  rye = 0;
  apple = 0;
  banana = 0;
  pear = 0;
  plantFull = false;
  equipFull = false;
  plantEmpty = true;
  equipEmpty = true;
  isOpen = true;

  addPlant(new Fruit(1, "Apple", 50, 2));
  addPlant(new Grain(2, "Wheat", 20, 10));
  addPlant(new Grain(3, "Rice", 20, 15));
  addEquipment(new Equipment(4, "Shovel", 50, 1));

  isOpen = false;
}

// getcontents function prints out all the current contents of the inventory.
// Only activates if inventory is Open and exists

void Inventory::getContents() {
  if (isOpen == true && exists == true) {
    cout << endl << "Tradeable goods: " << endl << endl;
    cout << "Current Funds: " << getFunds() << "." << endl;
    cout << "Current Wheat: " << getWheat() << "." << endl;
    cout << "Current Rice: " << getRice() << "." << endl;
    cout << "Current Rye: " << getRye() << "." << endl;
    cout << "Current Apple: " << getApple() << "." << endl;
    cout << "Current Pear: " << getPear() << "." << endl;
    cout << "Current Banana: " << getBanana() << "." << endl;
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

// returns the equipment map, required for a different class
unordered_map<int, Equipment*> Inventory::getEquipment() {
  if (exists == true) {
    return equipInventory;
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
}

// following 3 functions open/close/return the current status (open or closed)
// of the inventory, and calls the getContents function if opening. Only
// activate if Inventory exists
void Inventory::openInventory() {
  if (exists == true && isOpen == false) {
    isOpen = true;
    cout << "Opening Inventory: " << endl;
    getContents();
  } else if (exists == true && isOpen == true) {
    cout << "Unable, Inventory not closed" << endl;
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

// the following 7 functions alter the current aamount of funds/grain/fruit on
// hand. if the result is negative, the amount will be set to 0. Only activate
// if Inventory exists
void Inventory::changeFunds(int amount) {
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

void Inventory::changeWheat(int amount) {
  if (exists == true) {
    if ((wheat + amount) >= 0) {
      wheat = (wheat + amount);
    } else if ((wheat + amount) < 0) {
      wheat = 0;
    }
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
}

void Inventory::changeRice(int amount) {
  if (exists == true) {
    if ((rice + amount) >= 0) {
      rice = (rice + amount);
    } else if ((rice + amount) < 0) {
      rice = 0;
    }
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
}

void Inventory::changeRye(int amount) {
  if (exists == true) {
    if ((rye + amount) >= 0) {
      rye = (rye + amount);
    } else if ((rye + amount) < 0) {
      rye = 0;
    }
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
}

void Inventory::changeApple(int amount) {
  if (exists == true) {
    if ((apple + amount) >= 0) {
      apple = (apple + amount);
    } else if ((apple + amount) < 0) {
      apple = 0;
    }
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
}

void Inventory::changePear(int amount) {
  if (exists == true) {
    if ((pear + amount) >= 0) {
      pear = (pear + amount);
    } else if ((pear + amount) < 0) {
      pear = 0;
    }
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
}

void Inventory::changeBanana(int amount) {
  if (exists == true) {
    if ((banana + amount) >= 0) {
      banana = (banana + amount);
    } else if ((banana + amount) < 0) {
      banana = 0;
    }
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
}

// checks if either plant or equipment is full and returns the value.
bool Inventory::pFull() {
  if (exists == true) {
    return plantFull;
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
}
bool Inventory::eFull() {
  if (exists == true) {
    return equipFull;
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
}
bool Inventory::pEmpty() {
  if (exists == true) {
    return plantEmpty;
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
}
bool Inventory::eEmpty() {
  if (exists == true) {
    return equipEmpty;
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
}

// These 7 functions return the current funds, and amount of each plant
// species respectively
int Inventory::getFunds() {
  if (exists == true) {
    return funds;
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
  return -1;
}

int Inventory::getWheat() {
  if (exists == true) {
    return wheat;
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
  return -1;
}

int Inventory::getRice() {
  if (exists == true) {
    return rice;
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
  return -1;
}
int Inventory::getRye() {
  if (exists == true) {
    return rye;
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
  return -1;
}

int Inventory::getApple() {
  if (exists == true) {
    return apple;
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
  return -1;
}
int Inventory::getPear() {
  if (exists == true) {
    return pear;
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
  return -1;
}

int Inventory::getBanana() {
  if (exists == true) {
    return banana;
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
  return -1;
}

// the addPlant function uses an unordered map and an id to add a plant
// to the inventory, so long as there is space. Will only work if
// inventory exists
void Inventory::addPlant(Plant* p1) {
  if (exists == true) {
    if (plantInventory.size() < plantCapacity) {
      plantInventory[p1->getID()] = p1;
      cout << p1->getName() << " with id " << p1->getID() << " was added"
           << endl;
    } else {
      cout << "Unable to add " << p1->getName() << " - Inventory full" << endl;
    }
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
  if (plantInventory.size() > 0) {
    plantEmpty = false;
  }
  if (plantInventory.size() == plantCapacity) {
    plantFull = true;
  }
}

// the removePlant function uses an auto tracker value wth a map and an
// id to remove a plant from the inventory, if it exists there. Will
// only work if inventory exists
void Inventory::removePlant(int plantID) {
  if (exists == true) {
    auto it = plantInventory.find(plantID);
    if (it != plantInventory.end()) {
      string name = plantInventory[plantID]->getName();
      cout << name << " with id " << plantID << " was removed" << endl;
      plantInventory.erase(it);
    } else {
      cout << "Unable to remove Plant - Item not in inventory" << endl;
    }
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
  if (plantInventory.size() < plantCapacity) {
    plantFull = false;
  }
  if (plantInventory.size() == 0) {
    plantEmpty = true;
  }
}

// the addEquipment function uses an unordered map and an id to add
// Equipment to the inventory, so long as there is space. Will only work
// if inventory exists
void Inventory::addEquipment(Equipment* e1) {
  if (exists == true) {
    if (equipInventory.size() < equipmentCapacity) {
      equipInventory[e1->getID()] = e1;
      cout << e1->getName() << " with id " << e1->getID() << " was added"
           << endl;
    } else {
      cout << "Unable to add " << e1->getName() << " - Inventory full" << endl;
    }
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
  if (equipInventory.size() > 0) {
    equipEmpty = false;
  }
  if (equipInventory.size() == equipmentCapacity) {
    equipFull = true;
  }
}

// the removeEquipment function uses an auto tracker value wth a map and
// an id to remove Equipment fromthe inventory, if it exists there. Will
// only work if inventory exists
void Inventory::removeEquipment(int EquipmentID) {
  if (exists == true) {
    auto it = equipInventory.find(EquipmentID);
    if (it != equipInventory.end()) {
      string name = equipInventory[EquipmentID]->getName();
      equipInventory.erase(it);
      cout << name << " with id " << EquipmentID << " was removed" << endl;
    } else {
      cout << "Unable to remove Equipment - Item not in inventory " << endl;
    }
  } else {
    cout << "Unable, Inventory does not exist" << endl;
  }
  if (equipInventory.size() == equipmentCapacity) {
    equipFull = false;
  }
  if (equipInventory.size() == 0) {
    equipEmpty = true;
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
