#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <string>
#include "Inventory.h"
#include "Plant.h"
#include "Equipment.h"

using namespace std;

class Shop {
private:
    double itemPrice;
    // setting each of the item prices.

public:
    Shop();
    void buyGrain(Inventory& inventory, int amount);
    void sellGrain(Inventory& inventory, int amount);
    
    void buyFruit(Inventory& inventory, int amount);
    void sellFruit(Inventory& inventory, int amount);

    void buyEquipment(Inventory& inventory, Equipment* equipment);
    void sellEquipment(Inventory& inventory, Equipment* equipment);

};

#endif
