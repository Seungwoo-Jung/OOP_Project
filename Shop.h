#ifndef SHOP_H
#define SHOP_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Equipment.h"
#include "Fruit.h"
#include "Grain.h"
#include "Inventory.h"
#include "Item.h"
#include "Plant.h"

using namespace std;
typedef vector<string> NameList;
typedef vector<string> eNameList;
typedef vector<int> PriceList;
typedef vector<int> LifeList;
typedef vector<int> YieldList;
typedef vector<int> RevenueList;
typedef vector<int> ePriceList;
typedef vector<int> eLifeList;
typedef vector<int> eRevenueList;
typedef vector<int> EffectList;
NameList nameList = {"Wheat", "Rice", "Rye", "Apple", "Pear", "Banana"};
eNameList enameList = {"Hoe", "Shovel", "Fertiliser", "Weeder"};
PriceList priceList = {15, 20, 25, 50, 75, 100};
LifeList lifeList = {30, 40, 50, 100, 150, 200};
YieldList yieldList = {10, 20, 30, 5, 4, 3};
EffectList effectList = {3, 1, 4, 2};
ePriceList epriceList = {75, 25, 100, 50};
eLifeList elifeList = {40, 50, 20, 30};
eRevenueList erevenueList = {37, 12, 50, 25};
RevenueList revenueList = {2, 3, 4, 5, 7, 10};

class Shop {
 private:
  int IDused;
  int eIDused;
  bool isOpen;
  bool exists;

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

  void buyPlant(Inventory& inventory, int amount, int ID);
  void sellPlant(Inventory& inventory, int amount, int ID);

  void buyEquipment(Inventory& inventory, int ID);
  void sellEquipment(Inventory& inventory, int mapID, int ID);

  void openShop();
  void closeShop();
  ~Shop();
};
#endif
