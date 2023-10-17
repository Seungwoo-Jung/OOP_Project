#ifndef SHOP_H
#define SHOP_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Equipment.h"
#include "Inventory.h"
#include "Item.h"
#include "Plant.h"

using namespace std;
typedef vector<string> NameList;
typedef vector<int> PriceList;
typedef vector<int> RevenueList;
NameList nameList;
PriceList priceList;
RevenueList revenueList;

class Shop {
 private:
 public:
  Shop();

  void loadItemList() {
    fstream _file;
    string _filename = "shopList.txt";

    _file.open(_filename, ios::in);
    if (_file.is_open()) {
      string line;
      while (getline(_file, line)) {
        nameList.push_back(line);
      }
      _file.close();
    } else {
      throw runtime_error("Error: Unable to open file " + _filename + ".");
    }
    //-------------------------------------------------------------------------------
    fstream costFile;
    string costFileName = "shopCost.txt";

    costFile.open(costFileName, ios::in);
    if (costFile.is_open()) {
      string line_;
      while (getline(costFile, line_)) {
        int costs = stoi(line_);
        priceList.push_back(costs);
      }
      costFile.close();
    } else {
      throw runtime_error("Error: Unable to open file " + costFileName + ".");
    }
    // --------------------------------------------------------------------------------
    fstream file;
    string filename = "sellList.txt";

    file.open(filename, ios::in);
    if (file.is_open()) {
      string _line;
      while (getline(file, _line)) {
        int revenue = stoi(_line);
        revenueList.push_back(revenue);
      }
      file.close();
    } else {
      throw runtime_error("Error: Unable to open file " + filename + ".");
    }
  };

  void buyGrain(Inventory& inventory, int amount, int ID);
  void sellGrain(Inventory& inventory, int amount, int ID);

  void buyFruit(Inventory& inventory, int amount, int ID);
  void sellFruit(Inventory& inventory, int amount, int ID);

  void buyEquipment(Inventory& inventory, Equipment* equipment, int ID);
  void sellEquipment(Inventory& inventory, Equipment* equipment, int ID);
  ~Shop();
};

#endif
