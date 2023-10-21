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

class Shop {
 private:
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
  NameList nameList;
  eNameList enameList;
  PriceList priceList;
  LifeList lifeList;
  YieldList yieldList;
  EffectList effectList;
  ePriceList epriceList;
  eLifeList elifeList;
  eRevenueList erevenueList;
  RevenueList revenueList;
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
  void sellEquipment(Inventory& inventory, Equipment* Equipment, int ID);

  void openShop();
  void closeShop();
  ~Shop();
};
#endif
