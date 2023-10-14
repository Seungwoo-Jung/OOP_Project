#include "Inventory.h"

#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "Equipment.h"
#include "Plant.h"

using namespace std;

Inventory::Inventory() {
  currentSize = 0;
  maxSize = 14;
  plantCapacity = 10;
  equipmentCapacity = 4;
  funds = 0;
  grain = 0;
  fruit = 0;
  isOpen = false;
  plantsInHand = new Plant*[plantCapacity];
  equipmentInHand = new Equipment*[equipmentCapacity];

  equipmentInHand[0] = new Equipment(01, "shovel", 25, 1);
}

void Inventory::openInventory() { isOpen = true; }
void Inventory::closeInventory() { isOpen = false; }
bool Inventory::inventoryOpen() { return isOpen; }

void Inventory::changeFunds(double amount) { funds = (funds + amount); }
void Inventory::changeGrain(int amount) { grain = (grain + amount); }
void Inventory::changeFruit(int amount) { fruit = (fruit + amount); }

void Inventory::addPlant() {}
void Inventory::addEquipment() {}

void Inventory::removePlant() {}
void Inventory::removeEquipment() {}
