#include "Shop.h"

#include <fstream>
#include <string>

using namespace std;

Shop::Shop() {}

void Shop::buyGrain(Inventory &inventory, int amount, int ID) {
  int cost = priceList[ID];

  if (inventory.getFunds() >= cost) {
    inventory.changeFunds(0 - cost);
    inventory.changeGrain(amount);
    cout << "You have bought " << amount << " grains for $" << cost << endl;
  } else {
    cout << "Not enough funds to buy grains." << endl;
  }
}

void Shop::sellGrain(Inventory &inventory, int amount, int ID) {
  if (inventory.getGrain() >= amount) {
    int revenue = revenueList[ID] * amount;
    inventory.changeFunds(revenue);
    inventory.changeGrain(-amount);
    cout << "You have sold " << amount << " grains for $" << revenue << endl;
  } else {
    cout << "Not enough grain in your Inventory to sell." << endl;
  }
}

void Shop::buyFruit(Inventory &inventory, int amount, int ID) {
  int cost = priceList[ID];

  if (inventory.getFunds() >= cost) {
    inventory.changeFunds(-cost);
    inventory.changeFruit(amount);
    cout << "You have bought " << amount << " fruits for $" << cost << endl;
  } else {
    cout << "Not enough funds to buy fruits." << endl;
  }
}

void Shop::sellFruit(Inventory &inventory, int amount, int ID) {
  if (inventory.getFruit() >= amount) {
    int revenue = revenueList[ID] * amount;
    inventory.changeFunds(revenue);
    inventory.changeFruit(-amount);
    cout << "You have sold " << amount << " fruits for $" << revenue << endl;
  } else {
    cout << "Not enough fruit in your Inventory to sell." << endl;
  }
}

void Shop::buyEquipment(Inventory &inventory, Equipment *equipment, int ID) {
  int cost = priceList[ID];

  if (inventory.getFunds() >= cost) {
    inventory.changeFunds(-cost);
    inventory.addEquipment(equipment);
    cout << "You have bought an equipment for $" << cost << endl;
  } else {
    cout << "Not enough funds to buy the equipment." << endl;
  }
}

void Shop::sellEquipment(Inventory &inventory, Equipment *equipment, int ID) {
  int revenue = revenueList[ID];

  if (equipment != nullptr && !equipment->itemEquipped()) {
    inventory.removeEquipment(equipment->getID());
    inventory.changeFunds(revenue);
    delete equipment;
    cout << "You have sold an piece of equipment for $" << revenue << endl;
  } else {
    cout << "No such unequipped item in your Inventory to sell." << endl;
  }
}

Shop::~Shop() {}