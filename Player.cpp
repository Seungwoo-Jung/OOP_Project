#include "Player.h"

#include <fstream>
#include <iostream>
#include <limits>
#include <string>

#include "Equipment.h"
#include "Fruit.h"
#include "Grain.h"
#include "Inventory.h"
#include "Item.h"
#include "Plant.h"
#include "Shop.h"

using namespace std;

// default constructor
Player::Player() {
  cout << "Enter numbers to create your userID: " << endl;
  cin >> userID;
  timepassed = 0;
  validInput = false;
  done = false;
}

// Navigate function handles overall meny selection, player can choose to go to
// the field, the shop, or the inventory
int Player::Navigate(Inventory* inv, Shop* shop, Field* field) {
  char input = '0';
  validInput = false;
  bool done = false;
  while (validInput == false && done == false) {
    cout << "What would you like to do? S: go to shop; F: go to field; I: open "
            "inventory; C: close program"
         << endl;
    cin >> input;
    switch (input) {
      case 'S':
      case 's':
        shop->openShop();
        shopAction(shop, *inv);
        break;
      case 'i':
      case 'I':
        inv->openInventory();
        invAction(inv);
        break;
      case 'f':
      case 'F':
        field->openField();
        fieldAction(field, inv);
        break;
      case 'c':
      case 'C':
        cout << "Closing program:" << endl;
        done = true;
        break;
      default:
        cout << "Invalid input, reenter" << endl;
        break;
    }
  }
  return 0;
}

// grows all plants currently in the field using the current growth rateas well
// as uses equipped equipment
void Player::passTime(Field* field, Inventory* inv) {
  unordered_map<int, Equipment*> equipment = inv->getEquipment();
  timepassed = timepassed + 1;
  std::vector<std::vector<Plant*>> matrix = field->getField();
  int i = 0, j = 0;
  int rate = 1;
  cout << "day " << timepassed << "has ended." << endl;
  for (auto& pair : equipment) {
    if (pair.second->itemEquipped() == true) {
      rate = pair.second->getEffect();
      pair.second->use();
    }
  }
  if (field->Empty() == false) {
    cout << "Your plants have grown! Their status is: " << endl;
    for (i = 0; i < field->get_sizeM(); i++) {
      for (j = 0; j < field->get_sizeN(); j++) {
        if (matrix[i][j] != nullptr) {
          matrix[i][j]->plantGrow(rate);
          cout << "Plant in position " << i << ", " << j << ":" << endl;
          matrix[i][j]->getStatus();
        }
      }
    }
  }
}

int Player::loadData() {
  ifstream loadFile("player.txt");
  if (loadFile.is_open()) {
    loadFile >> userID >> Currency;
    loadFile.close();
  }
  return userID, Currency;
}

void Player::saveData() {
  ofstream saveFile("player.txt");
  if (saveFile.is_open()) {
    saveFile << userID << "\n" << Currency << "\n";
    saveFile.close();
  } else {
    cout << "unable to open file" << endl;
  }
}

// handles actions in the shop, primarily buying and selling items, as well as
// closing the shop.
void Player::shopAction(Shop* shop, Inventory& inv) {
  done = false;
  char input = '0';
  char type = '0';
  int quantity = -1;
  int ID = -1;
  int species = -1;
  unordered_map<int, Equipment*> owned = inv.getEquipment();
  while (done == false) {
    owned = inv.getEquipment();
    input = '0';
    validInput = false;
    type = '0';
    quantity = -1;
    ID = -1;
    species = -1;
    cout << "What would you like to do? B: buy items; S: sell items; C: close "
            "shop"
         << endl;
    cin >> input;
    switch (input) {
      case 'B':
      case 'b':
        validInput = false;
        while (validInput == false) {
          cout << "Equipment or Plant? P: plant; E: equipment" << endl;
          cin >> type;
          switch (type) {
            case 'e':
            case 'E':
              while (validInput == false) {
                cout << "Enter type: 1: Hoe 2: Shovel 3: Fertiliser 4: Weeder"
                     << endl;
                while (true) {
                  if (std::cin >> ID) {
                    break;
                  } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                    '\n');
                    std::cout << "Invalid input. Please enter an integer."
                              << std::endl;
                  }
                }
                switch (ID) {
                  case 1:
                  case 2:
                  case 3:
                  case 4:
                    shop->buyEquipment(inv, (ID - 1));
                    validInput = true;
                    break;
                  default:
                    cout << "Invalid input, reenter" << endl;
                    break;
                }
              }
              break;
            case 'p':
            case 'P':
              quantity = -1;
              cout << "Enter quantity" << endl;
              while (quantity < 0) {
                while (true) {
                  if (std::cin >> quantity) {
                    break;
                  } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                    '\n');
                    std::cout << "Invalid input. Please enter an integer."
                              << std::endl;
                  }
                }
                if (quantity < 0) {
                  cout << "Invaid input, must be greater than or equal to 0"
                       << endl;
                }
              }
              while (validInput == false) {
                cout << "Enter type: 1: Wheat; 2: Rice; 3: Rye; 4: Apple; 5: "
                        "Pear; 6: Banana;"
                     << endl;
                while (true) {
                  if (std::cin >> species) {
                    break;
                  } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                    '\n');
                    std::cout << "Invalid input. Please enter an integer."
                              << std::endl;
                  }
                }
                switch (species) {
                  case 1:
                  case 2:
                  case 3:
                  case 4:
                  case 5:
                  case 6:
                    shop->buyPlant(inv, quantity, (species - 1));
                    validInput = true;
                    break;
                  default:
                    cout << "Invalid Input, reenter" << endl;
                    break;
                }
              }
              break;
            default:
              cout << "Invalid input, reenter" << endl;
              break;
          }
        }
        break;
      case 'S':
      case 's':
        validInput = false;
        while (validInput == false) {
          cout << "Equipment or Plant? P: plant; E: equipment" << endl;
          cin >> type;
          switch (type) {
            case 'e':
            case 'E':
              if (!owned.empty()) {
                while (validInput == false) {
                  cout << "Enter the ID of the equipment you'd like to sell"
                       << endl;
                  while (true) {
                    if (std::cin >> ID) {
                      break;
                    } else {
                      std::cin.clear();
                      std::cin.ignore(
                          std::numeric_limits<std::streamsize>::max(), '\n');
                      std::cout << "Invalid input. Please enter an integer."
                                << std::endl;
                    }
                  }
                  auto it = owned.find(ID);
                  if (it != owned.end()) {
                    string name = owned[ID]->getName();
                    if (name == "Hoe") {
                      shop->sellEquipment(inv, owned[ID], 0);
                    } else if (name == "Shovel") {
                      shop->sellEquipment(inv, owned[ID], 1);
                    } else if (name == "Fertiliser") {
                      shop->sellEquipment(inv, owned[ID], 2);
                    } else if (name == "Weeder") {
                      shop->sellEquipment(inv, owned[ID], 3);
                    }
                  } else {
                    cout << "Item not found" << endl;
                  }
                  validInput = true;
                }
              } else {
                cout << "No item to sell, inventory empty" << endl;
                validInput = true;
              }
              break;
            case 'p':
            case 'P':
              quantity = -1;
              cout << "Enter quantity" << endl;
              while (quantity < 0) {
                while (true) {
                  if (std::cin >> quantity) {
                    break;
                  } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                    '\n');
                    std::cout << "Invalid input. Please enter an integer."
                              << std::endl;
                  }
                }
                if (quantity < 0) {
                  cout << "Invaid input, must be greater than or equal to 0"
                       << endl;
                }
              }
              while (validInput == false) {
                cout << "Enter type: 1: Wheat; 2: Rice; 3: Rye; 4: Apple; 5: "
                        "Pear; 6: Banana;"
                     << endl;
                while (true) {
                  if (std::cin >> species) {
                    break;
                  } else {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                    '\n');
                    std::cout << "Invalid input. Please enter an integer."
                              << std::endl;
                  }
                }
                switch (species) {
                  case 1:
                  case 2:
                  case 3:
                  case 4:
                  case 5:
                  case 6:
                    shop->sellPlant(inv, quantity, (species - 1));
                    validInput = true;
                    break;
                  default:
                    cout << "Invalid Input, reenter" << endl;
                    break;
                }
              }
              break;
            default:
              cout << "Invalid input, reenter" << endl;
              break;
          }
        }
        break;
      case 'C':
      case 'c':
        shop->closeShop();
        done = true;
        break;
      default:
        cout << "Invalid input, reenter" << endl;
        break;
    }
  }
  validInput = false;
};

// handles inventory actions, including viewing contents, equipping equipment,
// removing equipment, and closing inventory
void Player::invAction(Inventory* inv) {
  done = false;
  char input = '0';
  int ID = -1;
  unordered_map<int, Equipment*> equipment = inv->getEquipment();
  while (done == false) {
    input = '0';
    ID = -1;
    cout << "What would you like to do? V: view contents; E: equip item; R: "
            "remove Equipment; C: "
            "close inventory"
         << endl;
    cin >> input;
    switch (input) {
      case 'v':
      case 'V':
        inv->getContents();
        break;
      case 'R':
      case 'r':
        cout << "Enter the ID of the item you want to remove" << endl;
        cin >> ID;
        inv->removeEquipment(ID);
        break;
      case 'e':
      case 'E':
        cout << "Enter the ID of the item you want to equip" << endl;
        cin >> ID;
        if (!equipment.empty()) {
          auto it = equipment.find(ID);
          if (it != equipment.end()) {
            for (auto& pair : equipment) {
              if (pair.second->getID() == ID) {
                pair.second->equip();
              } else {
                pair.second->unequip();
              }
            }
          } else {
            cout << "Item not found " << endl;
          }
        } else {
          cout << "No items in Inventory" << endl;
        }
        break;
      case 'c':
      case 'C':
        inv->closeInventory();
        done = true;
        break;
      default:
        cout << "Invalid input, reenter" << endl;
        break;
    }
  }
  validInput = false;
};

// handles field actions, including viewing contents, adding/removing plants,
// harvesting plants, and closing the field
void Player::fieldAction(Field* field, Inventory* inv) {
  char input = '0';
  done = false;
  unordered_map<int, Plant*> plants = inv->getPlants();
  std::vector<std::vector<Plant*>> matrix = field->getField();
  int ID = -1, i = 0, j = 0;
  Plant* p1 = nullptr;
  while (done == false) {
    input = '0';
    p1 = nullptr;
    cout << "What would you like to do? A: add plant; H: harvest plant; R: "
            "remove plant; G: get contents; C: close field;"
         << endl;
    cin >> input;
    switch (input) {
      case 'a':
      case 'A':
        cout << "Enter the ID of the Plant you want to Add:" << endl;
        cin >> ID;
        for (auto& pair : plants) {
          if (pair.second->getID() == ID) {
            p1 = pair.second;
            break;
          }
        }
        if (p1 != nullptr) {
          if (field->Full() == false) {
            for (i = 0; i < field->get_sizeM(); i++) {
              for (j = 0; j < field->get_sizeN(); j++) {
                if (matrix[i][j] == nullptr) {
                  field->set_plant(p1, i, j);
                  cout << "Plant with ID " << p1->getID() << " and name "
                       << p1->getName() << " added to position " << i << ","
                       << j << "." << endl;
                  break;
                }
              }
            }
          } else {
            cout << "Unable to add plant, Field is full" << endl;
          }
        } else {
          cout << "Plant not found in Inventory" << endl;
        }
        break;

      case 'h':
      case 'H':
        cout << "Enter the ID of the Plant you want to Harvest:" << endl;
        cin >> ID;
        if (field->Empty() == false) {
          for (i = 0; i < field->get_sizeM(); i++) {
            for (j = 0; j < field->get_sizeN(); j++) {
              if (matrix[i][j] != nullptr) {
                int plantID = matrix[i][j]->getID();
                if (plantID == ID) {
                  cout << "Plant in position " << i << "," << j
                       << " was harvested." << endl;
                  matrix[i][j]->plantHarvest();
                } else if (plantID != ID && i == field->get_sizeM() &&
                           j == field->get_sizeN()) {
                  cout << "Plant not found on the field" << endl;
                }
              }
            }
          }
        } else {
          cout << "Nothing to Harvest, Field is empty" << endl;
        }
        break;

      case 'r':
      case 'R':
        cout << "Enter the ID of the Plant you want to remove:" << endl;
        cin >> ID;
        if (field->Empty() == false) {
          for (i = 0; i < field->get_sizeM(); i++) {
            for (j = 0; j < field->get_sizeN(); j++) {
              if (matrix[i][j] != nullptr) {
                int plantID = matrix[i][j]->getID();
                if (plantID == ID) {
                  cout << "Plant in position " << i << "," << j
                       << " was removed." << endl;
                  matrix[i][j]->plantHarvest();
                  if (matrix[i][j]->getStat() == "dead") {
                    cout << "Removing plant, as it is dead " << endl;
                    field->remove_plant(i, j);
                  }
                  break;
                } else if (plantID != ID && i == field->get_sizeM() &&
                           j == field->get_sizeN()) {
                  cout << "Plant not found on the field" << endl;
                }
              }
            }
          }
        } else {
          cout << "Nothing to remove, Field is empty" << endl;
        }
        break;

      case 'g':
      case 'G':
        field->getContents();
        break;

      case 'c':
      case 'C':
        field->closeField();
        done = true;
        break;

      default:
        cout << "Invalid input, reenter" << endl;
        break;
    }
  }
};

// destructor deletes the player class
Player::~Player() { cout << "Player was deleted" << endl; }