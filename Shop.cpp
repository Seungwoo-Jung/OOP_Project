#include "Shop.h"

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
  IDused = 4;
  eIDused = 2;
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
    if (amount >= 0) {
      int cost = priceList[ID];
      string name = nameList[ID];
      int lifespan = lifeList[ID];
      int yield = yieldList[ID];
      int bought = 0;
      int value = IDused;

      for (int i = value; i < (value + amount); i++) {
        if (amount == 0 || inventory.pFull() == false) {
          if (amount == 0 || inventory.getFunds() >= cost) {
            if (name == "Rye" || name == "rye" || name == "Rice" ||
                name == "rice" || name == "wheat" || name == "Wheat") {
              inventory.addPlant(new Grain(IDused, name, lifespan, yield));
            } else if (name == "apple" || name == "Apple" || name == "Pear" ||
                       name == "pear" || name == "banana" || name == "Banana") {
              inventory.addPlant(new Fruit(IDused, name, lifespan, yield));
            }
            IDused = IDused + 1;
            bought = (bought + 1);
            inventory.changeFunds((0 - cost));
          } else {
            if (name == "Rye" || name == "rye" || name == "Rice" ||
                name == "rice" || name == "wheat" || name == "Wheat") {
              cout << "Not enough funds to buy more " << name << "." << endl;
            } else if (name == "apple" || name == "Apple" || name == "Pear" ||
                       name == "pear" || name == "banana" || name == "Banana") {
              cout << "Not enough funds to buy more " << name << "s." << endl;
            }
            break;
          }
        } else {
          if (name == "Rye" || name == "rye" || name == "Rice" ||
              name == "rice" || name == "wheat" || name == "Wheat") {
            cout << "Unable to buy more " << name << ", Inventory Full" << endl;
          } else if (name == "apple" || name == "Apple" || name == "Pear" ||
                     name == "pear" || name == "banana" || name == "Banana") {
            cout << "Unable to buy more " << name << "s, Inventory Full"
                 << endl;
          }
          break;
        }
      }
      cost = (priceList[ID] * bought);
      if ((bought > 0 || amount == 0) &&
          (name == "wheat" || name == "Wheat" || name == "rye" ||
           name == "Rye" || name == "rice" || name == "Rice")) {
        cout << "You have bought " << bought << " " << name << " for $" << cost
             << endl;
      } else if ((bought > 0 || amount == 0) &&
                 (name == "apple" || name == "Apple" || name == "pear" ||
                  name == "Pear" || name == "banana" || name == "Banana")) {
        if (bought == 1 || amount == 1) {
          cout << "You have bought " << bought << " " << name << " for $"
               << cost << endl;
        } else {
          cout << "You have bought " << bought << " " << name << "s for $"
               << cost << endl;
        }
      }
    } else {
      cout << "Invalid amount, must be greater than or equal to 0" << endl;
    }
  } else if (exists == true && isOpen != true) {
    cout << "Unable, Shop is not open" << endl;
  } else {
    cout << "Unable, Shop doesn't exist" << endl;
  }
}

// Sells a certain amount of plants, using the ID to specify the species and
// pricing. decreases the amount of that item in your inventory. Only functions
// if the inventory has some of that item, and the shop is both open and exists
// Different cases are used for each possible type of plant. If statements are
// used to determine the species for smooth functioning
void Shop::sellPlant(Inventory &inventory, int amount, int ID) {
  if (exists == true && isOpen == true) {
    if (amount >= 0) {
      string name = nameList[ID];
      int lifespan = lifeList[ID];
      int yield = yieldList[ID];
      int revenue = revenueList[ID];
      int sold = 0;

      if (amount == 0 || inventory.getWheat() != 0 ||
          inventory.getRice() != 0 || inventory.getRye() != 0 ||
          inventory.getApple() != 0 || inventory.getPear() != 0 ||
          inventory.getBanana() != 0) {
        if (name == "wheat" || name == "Wheat") {
          if (amount == 0 || inventory.getWheat() >= amount) {
            inventory.changeFunds(revenue * amount);
            inventory.changeWheat(-amount);
            cout << "You have sold " << amount << " " << name << " for $"
                 << (revenue * amount) << endl;
          } else if (amount == 0 || (inventory.getWheat() > 0 &&
                                     inventory.getWheat() < amount)) {
            cout << "Not enough Wheat in Inventory to sell this many, selling "
                    "all "
                    "remaining: "
                 << endl;
            sold = inventory.getWheat();
            inventory.changeWheat(-amount);
            cout << "You have sold " << sold << " " << name << " for $"
                 << (revenue * sold) << endl;
            inventory.changeFunds(revenue * sold);
          } else {
            cout << "No Wheat in your Inventory to sell" << endl;
          }
        } else if (name == "rice" || name == "Rice") {
          if (amount == 0 || inventory.getRice() >= amount) {
            inventory.changeFunds(revenue * amount);
            inventory.changeRice(-amount);
            cout << "You have sold " << amount << " " << name << " for $"
                 << (revenue * amount) << endl;
          } else if (amount == 0 || (inventory.getRice() > 0 &&
                                     inventory.getRice() < amount)) {
            cout << "Not enough Rice in Inventory to sell this many, selling "
                    "all "
                    "remaining: "
                 << endl;
            sold = inventory.getRice();
            inventory.changeRice(-amount);
            cout << "You have sold " << sold << " " << name << " for $"
                 << (revenue * sold) << endl;
            inventory.changeFunds(revenue * sold);
          } else {
            cout << "No Rice in your Inventory to sell" << endl;
          }
        } else if (name == "rye" || name == "Rye") {
          if (amount == 0 || inventory.getRye() >= amount) {
            inventory.changeFunds(revenue * amount);
            inventory.changeRye(-amount);
            cout << "You have sold " << amount << " " << name << " for $"
                 << (revenue * amount) << endl;
          } else if (amount == 0 ||
                     (inventory.getRye() > 0 && inventory.getRye() < amount)) {
            cout
                << "Not enough Rye in Inventory to sell this many, selling all "
                   "remaining: "
                << endl;
            sold = inventory.getRye();
            inventory.changeRye(-amount);
            cout << "You have sold " << sold << " " << name << " for $"
                 << (revenue * sold) << endl;
            inventory.changeFunds(revenue * sold);
          } else {
            cout << "No Rye in your Inventory to sell" << endl;
          }
        } else if (name == "apple" || name == "Apple") {
          if (amount == 0 || inventory.getApple() >= amount) {
            inventory.changeFunds(revenue * amount);
            inventory.changeApple(-amount);
            if (amount == 1) {
              cout << "You have sold " << amount << " " << name << " for $"
                   << (revenue * amount) << endl;
            } else {
              cout << "You have sold " << amount << " " << name << "s for $"
                   << (revenue * amount) << endl;
            }
          } else if (amount == 0 || (inventory.getApple() > 0 &&
                                     inventory.getApple() < amount)) {
            cout << "Not enough Apples in Inventory to sell this many, selling "
                    "all remaining: "
                 << endl;
            sold = inventory.getApple();
            inventory.changeApple(-amount);
            if (sold == 1) {
              cout << "You have sold " << sold << " " << name << " for $"
                   << (revenue * sold) << endl;
            } else {
              cout << "You have sold " << sold << " " << name << "s for $"
                   << (revenue * sold) << endl;
            }
            inventory.changeFunds(revenue * sold);
          } else {
            cout << "No Apples in your Inventory to sell" << endl;
          }
        } else if (name == "pear" || name == "Pear") {
          if (amount == 0 || inventory.getPear() >= amount) {
            inventory.changeFunds(revenue * amount);
            inventory.changePear(-amount);
            if (amount == 1) {
              cout << "You have sold " << amount << " " << name << " for $"
                   << (revenue * amount) << endl;
            } else {
              cout << "You have sold " << amount << " " << name << "s for $"
                   << (revenue * amount) << endl;
            }
          } else if (amount == 0 || (inventory.getPear() > 0 &&
                                     inventory.getPear() < amount)) {
            cout << "Not enough Pears in Inventory to sell this many, selling "
                    "all "
                    "remaining: "
                 << endl;
            sold = inventory.getPear();
            inventory.changePear(-amount);
            if (sold == 1) {
              cout << "You have sold " << sold << " " << name << " for $"
                   << (revenue * sold) << endl;
            } else {
              cout << "You have sold " << sold << " " << name << "s for $"
                   << (revenue * sold) << endl;
            }
            inventory.changeFunds(revenue * sold);
          } else {
            cout << "No Pears in your Inventory to sell" << endl;
          }
        } else if (name == "banana" || name == "Banana") {
          if (amount == 0 || inventory.getBanana() >= amount) {
            inventory.changeFunds(revenue * amount);
            inventory.changeBanana(-amount);
            if (amount == 1) {
              cout << "You have sold " << amount << " " << name << " for $"
                   << (revenue * amount) << endl;
            } else {
              cout << "You have sold " << amount << " " << name << "s for $"
                   << (revenue * amount) << endl;
            }
          } else if (amount == 0 || (inventory.getBanana() > 0 &&
                                     inventory.getBanana() < amount)) {
            cout
                << "Not enough Bananas in Inventory to sell this many, selling "
                   "remaining: "
                << endl;
            sold = inventory.getBanana();
            inventory.changeBanana(-amount);
            if (sold == 1) {
              cout << "You have sold " << sold << " " << name << " for $"
                   << (revenue * sold) << endl;
            } else {
              cout << "You have sold " << sold << " " << name << "s for $"
                   << (revenue * sold) << endl;
            }
            inventory.changeFunds(revenue * sold);
          } else {
            cout << "No Bananas in your Inventory to sell" << endl;
          }
        }
      } else {
        cout << "Unable to sell, Inventory Empty" << endl;
      }
    } else {
      cout << "Invalid amount, must be greater than or equal to 0" << endl;
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
        if (name == "fertiliser" || name == "Fertiliser") {
          cout << "You have bought some " << name << " for $" << cost << endl;
        } else {
          cout << "You have bought a " << name << " for $" << cost << endl;
        }
        eIDused = (eIDused + 1);
      } else {
        cout << "Unable to buy " << name << ", Inventory Full" << endl;
      }
    } else {
      cout << "Not enough funds to buy " << name << "." << endl;
    }
  } else if (exists == true && isOpen != true) {
    cout << "Unable, Shop is not open" << endl;
  } else {
    cout << "Unable, Shop doesn't exist" << endl;
  }
}

// sells equipment. Unlike selling plants, this removes the object from your
// inventory directly, using it's identifier to do so. Only works if the object
// exists in the inventory, and the shop is both open and exists
void Shop::sellEquipment(Inventory &inventory, Equipment *e1, int ID) {
  if (exists == true && isOpen == true) {
    int revenue = erevenueList[ID];
    string name = enameList[ID];

    if (inventory.eEmpty() == false) {
      if (e1->getStat() != "broken") {
        if (inventory.getEquipment().count(e1->getID()) > 0) {
          inventory.removeEquipment(e1->getID());
          inventory.changeFunds(revenue);
          if (name == "fertiliser" || name == "Fertiliser") {
            cout << "You have sold some " << name << " for $" << revenue
                 << endl;
          } else {
            cout << "You have sold a " << name << " for $" << revenue << endl;
          }
        } else {
          cout << "No " << name << " with that ID in your Inventory to sell."
               << endl;
        }
      } else {
        revenue = 0;
        if (name == "fertiliser" || name == "Fertiliser") {
          cout << "You have sold the" << name << " for $" << revenue
               << ", as it has been used." << endl;
        } else {
          cout << "You have sold a " << name << " for $" << revenue
               << ", as it is broken." << endl;
        }
        inventory.removeEquipment(e1->getID());
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