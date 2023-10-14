#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "Shop.h"


using namespace std;

Shop::Shop() {

}
void Shop::buyItems(const string& item, int amount) {
    
}
void Shop::sellItems(const string& item, int amount) {

}
void Shop::setItemPrice(string& item, int price) {
    ifstream loadFile("shop.txt");
    loadFile >> currentPlantPrice >> itemPrice;
    loadFile.close();
    


    std::ofstream saveFile("shop.txt");
    saveFile << currentPlantPrice << "\n" << itemPrice << "\n";
    saveFile.close();
}

Shop::~Shop() {

}