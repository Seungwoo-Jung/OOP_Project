#include "Shop.h"

#include <fstream>
#include <string>

#include "Equipment.h"
#include "Fruit.h"
#include "Grain.h"
#include "Inventory.h"
#include "Item.h"
#include "Plant.h"

using namespace std;

// contructor, sets the ID used variable as 5, open as false, and exists as true
Shop::Shop() {
  IDused = 5;
  eIDused = 5;
  isOpen = false;
  exists = true;
  nameList = {"Wheat", "Rice", "Rye", "Apple", "Pear", "Banana"};
  enameList = {"Hoe", "Shovel", "Fertiliser", "Weeder"};
  priceList = {15, 20, 25, 50, 75, 100};
  lifeList = {30, 40, 50, 100, 150, 200};
  yieldList = {10, 20, 30, 5, 4, 3};
  effectList = {3, 1, 4, 2};
  epriceList = {75, 25, 100, 50};
  elifeList = {40, 50, 20, 30};
  erevenueList = {37, 12, 50, 25};
  revenueList = {2, 3, 4, 5, 7, 10};
}

// buy Plant function buys a plant of a specified type using the ID to identify
// the species and other identifiers. automatically adds the plant(s) to your
// inventory until Inventory is full. Will only function is shop exists, is
// open, the player has enough funds, and the inventory is not full. In the case
// of the inventory filling up whhile buying, a separat tracker is used to
// determine the amount which was bought
void Shop::buyPlant(Inventory &inventory, int amount, int ID) {
  if (exists == true && isOpen == true) {
    int cost = priceList[ID];
    string name = nameList[ID];
    int lifespan = lifeList[ID];
    int yield = yieldList[ID];
    int bought = 0;
    int value = IDused;

    for (int i = value; i < (value + amount); i++) {
      if (inventory.getFunds() >= cost) {
        if (inventory.pFull() == false) {
          if (name == "Rye" || name == "rye" || name == "Rice" ||
              name == "rice" || name == "wheat" || name == "Wheat") {
            inventory.addPlant(new Grain(IDused, name, lifespan, yield));
          } else if (name == "apple" || name == "Apple" || name == "Pear" ||
                     name == "pear" || name == "banana" || name == "Banana") {
            inventory.addPlant(new Fruit(IDused, name, lifespan, yield));
          }
          IDused = IDused + 1;
          bought = (bought + 1);
          cost = (priceList[ID] * bought);
          inventory.changeFunds((0 - cost));
        } else {
          cout << "Unable to buy more items, Inventory Full" << endl;
        }
      } else {
        cout << "Not enough funds to buy plant." << endl;
      }
    }
    cost = (priceList[ID] * bought);
    cout << "You have bought " << bought << " " << name << " for $" << cost
         << endl;

  } else if (exists == true && isOpen != true) {
    cout << "Unable, Shop is not open" << endl;
  } else {
    cout << "Unable, Shop doesn't exist" << endl;
  }
}

// Sells a certain amount of plants, using the ID to specify the species and
// pricing. decreases the amount of that item in your inventory. Only functions
// if the inventory has some of that item, and the shop is both open and exists
// Different cases are used for each possible type of plant.
void Shop::sellPlant(Inventory &inventory, int amount, int ID) {
  if (exists == true && isOpen == true) {
    string name = nameList[ID];
    int lifespan = lifeList[ID];
    int yield = yieldList[ID];
    int revenue = revenueList[ID];
    int sold = 0;

    if (inventory.pEmpty() == false) {
      if (name == "wheat" || name == "Wheat") {
        if (inventory.getWheat() >= amount) {
          int revenue = revenueList[ID] * amount;
          inventory.changeFunds(revenue);
          inventory.changeWheat(-amount);
          cout << "You have sold " << amount << " " << name << "for $"
               << revenue << endl;
        } else if (inventory.getWheat() > 0 && inventory.getWheat() < amount) {
          sold = inventory.getWheat();
          revenue = revenueList[ID] * amount;
          inventory.changeFunds(revenue);
          inventory.changeWheat(-amount);
          cout << "You have sold " << sold << " " << name << "for $" << revenue
               << endl;
        }
      } else if (name == "rice" || name == "Rice") {
        if (inventory.getRice() >= amount) {
          int revenue = revenueList[ID] * amount;
          inventory.changeFunds(revenue);
          inventory.changeRice(-amount);
          cout << "You have sold " << amount << " " << name << "for $"
               << revenue << endl;
        } else if (inventory.getRice() > 0 && inventory.getRice() < amount) {
          sold = inventory.getRice();
          revenue = revenueList[ID] * amount;
          inventory.changeFunds(revenue);
          inventory.changeRice(-amount);
          cout << "You have sold " << sold << " " << name << "for $" << revenue
               << endl;
        }
      } else if (name == "rye" || name == "Rye") {
        if (inventory.getRye() >= amount) {
          int revenue = revenueList[ID] * amount;
          inventory.changeFunds(revenue);
          inventory.changeRye(-amount);
          cout << "You have sold " << amount << " " << name << "for $"
               << revenue << endl;
        } else if (inventory.getRye() > 0 && inventory.getRye() < amount) {
          sold = inventory.getRye();
          revenue = revenueList[ID] * amount;
          inventory.changeFunds(revenue);
          inventory.changeRye(-amount);
          cout << "You have sold " << sold << " " << name << "for $" << revenue
               << endl;
        }
      } else if (name == "apple" || name == "Apple") {
        if (inventory.getApple() >= amount) {
          int revenue = revenueList[ID] * amount;
          inventory.changeFunds(revenue);
          inventory.changeApple(-amount);
          cout << "You have sold " << amount << " " << name << "for $"
               << revenue << endl;
        } else if (inventory.getApple() > 0 && inventory.getApple() < amount) {
          sold = inventory.getApple();
          revenue = revenueList[ID] * amount;
          inventory.changeFunds(revenue);
          inventory.changeApple(-amount);
          cout << "You have sold " << sold << " " << name << "for $" << revenue
               << endl;
        }
      } else if (name == "pear" || name == "Pear") {
        if (inventory.getPear() >= amount) {
          int revenue = revenueList[ID] * amount;
          inventory.changeFunds(revenue);
          inventory.changePear(-amount);
          cout << "You have sold " << amount << " " << name << "for $"
               << revenue << endl;
        } else if (inventory.getPear() > 0 && inventory.getPear() < amount) {
          sold = inventory.getPear();
          revenue = revenueList[ID] * amount;
          inventory.changeFunds(revenue);
          inventory.changePear(-amount);
          cout << "You have sold " << sold << " " << name << "for $" << revenue
               << endl;
        }
      } else if (name == "banana" || name == "Banana") {
        if (inventory.getBanana() >= amount) {
          int revenue = revenueList[ID] * amount;
          inventory.changeFunds(revenue);
          inventory.changeBanana(-amount);
          cout << "You have sold " << amount << " " << name << "for $"
               << revenue << endl;
        } else if (inventory.getBanana() > 0 &&
                   inventory.getBanana() < amount) {
          sold = inventory.getBanana();
          revenue = revenueList[ID] * amount;
          inventory.changeFunds(revenue);
          inventory.changeBanana(-amount);
          cout << "You have sold " << sold << " " << name << "for $" << revenue
               << endl;
        }
      }
    } else {
      cout << "Unable to sell, Inventory Empty" << endl;
    }
  } else if (exists == true && isOpen != true) {
    cout << "Unable, Shop is not open" << endl;
  } else {
    cout << "Unable, Shop doesn't exist" << endl;
  }
}

// buys Equipment, under the same conditions as buying plants.
void Shop::buyEquipment(Inventory &inventory, int ID) {
  if (exists == true && isOpen == true) {
    int cost = priceList[ID];
    string name = enameList[ID];
    int lifespan = elifeList[ID];
    int effect = effectList[ID];

    if (inventory.getFunds() >= cost) {
      if (inventory.eFull() == false) {
        inventory.changeFunds((0 - cost));
        inventory.addEquipment(new Equipment(eIDused, name, lifespan, effect));
        cout << "You have bought a " << name << " for $" << cost << endl;
        eIDused = (eIDused + 1);
      } else {
        cout << "Unable to buy equipment, Inventory Full" << endl;
      }
    } else {
      cout << "Not enough funds to buy the equipment." << endl;
    }
  } else if (exists == true && isOpen != true) {
    cout << "Unable, Shop is not open" << endl;
  } else {
    cout << "Unable, Shop doesn't exist" << endl;
  }
}

// sells equipment. Unlike selling plants, this remov3es the object from your
// inventory directly, using it's identifier to do so. Only works if the object
// exists in the inventory, and the shop is both open and exists
void Shop::sellEquipment(Inventory &inventory, int mapID, int ID) {
  if (exists == true && isOpen == true) {
    int revenue = erevenueList[ID];
    string name = enameList[ID];

    if (inventory.eEmpty() == false) {
      if (inventory.getEquipment().count(mapID) > 0) {
        inventory.removeEquipment(mapID);
        inventory.changeFunds(revenue);
        cout << "You have sold a " << name << " for $" << revenue << endl;
      } else {
        cout << "No item in your Inventory to sell." << endl;
      }
    } else {
      cout << "Unable to sell item, Inventory Empty" << endl;
    }
  } else if (exists == true && isOpen != true) {
    cout << "Unable, Shop is not open" << endl;
  } else {
    cout << "Unable, Shop doesn't exist" << endl;
  }
}

// Opens the shop, if it is closed and exists
void Shop::openShop() {
  if (exists == true && isOpen == false) {
    isOpen = true;
    cout << "Opening Shop: " << endl;
  } else if (exists == true && isOpen == true) {
    cout << "Unable, shop already open" << endl;
  } else {
    cout << "Unable, Shop doesn't exist" << endl;
  }
}
// closes the shop, if it is open and exists
void Shop::closeShop() {
  if (exists == true && isOpen == true) {
    isOpen = false;
    cout << "Closing Shop: " << endl;
  } else if (exists == true && isOpen != true) {
    cout << "Unable, Shop is not open" << endl;
  } else {
    cout << "Unable, Shop doesn't exist" << endl;
  }
}

// destructor deletes shop with message
Shop::~Shop() { cout << "Shop was deleted" << endl; }