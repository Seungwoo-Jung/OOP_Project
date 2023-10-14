#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <string>
#include <map>
#include "Plant.h"

using namespace std;

class Inventory {
    private:
        int currentSize;
        int maxSize;
        int plantCapacity;
        int equipmentCapacity;
        plant* *plantsInHand = new plant*[plantCapacity];
        Equipment equipmentInHand;

    public:
        void openInventory();
        void closeInventory();
        void addPlant();
        void addEquipment();
        void moveItem();
        void removeItem();
        void removeEquipment();
};
#endif