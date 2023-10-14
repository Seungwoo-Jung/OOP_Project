#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include <string>
#include <map>
#include <fstream>


using namespace std;

class Shop {
    private: 
        int currentInventory;
        int currentPlantPrice;
        int itemPrice;

    public:
        Shop();
        void buyItems(const string& item, int amount);
        void sellItems(const string& item, int amount); 
        void setItemPrice(string& item, int price);
        ~Shop();
};
#endif