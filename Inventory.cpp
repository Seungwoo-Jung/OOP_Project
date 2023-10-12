#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include "Inventory.h"

using namespace std;

void Inventory::openInventory() {

    cout << "Opening inventory..." << endl;
    ifstream loadFile("inventory.txt");
    loadFile >> currentSize >> maxSize >> plantCapacity >> equipmentCapacity >> plantsInHand >> equipmentInHand; 
    loadFile.close();
    for (int i = 0; i < plantCapacity; i++) {
        cout << "- Plant specie: " << plantsInHand[i]->species << ", quantity: " << plantsInHand->amount << " / ";
    }
    cout << endl;

    for (int i = 0; i < equipmentCapacity; i++) {
        cout << "- Equipment: " << equipmentInHand[i]->name << ", effects: " << equipmentInHand->getStatus() << " / ";
    }
    cout << endl;

    int condition;
    while (condition != 1) {
        char input;
        cout << "What do you want to do? (C:close inventory/ r: remove items)" << endl;
        cin >> &input;

        if (input == 'C' || input == 'c') {
            closeInventory();
            condition = 1;
        }
        else if (input == 'r' || input == 'R') {
            int cond;
            while (cond != 1) {
                char second;
                cout << "What do you want to remove? (E: Equipment / o: others)" << endl;
                cin >> &second;
                if (second == 'o' || second == 'O') {
                    removeItem();
                    cond = 1;
                }
                else if (second == 'E' || second == 'e')
                {
                    removeEquipment();
                    cond = 1;
                }
                else
                {
                    cout << "wrong input please enter again: " << endl;
                    continue;
                }
            }
            condition = 1;
        }
    }
}

void Inventory::closeInventory() {

    cout << "Closing inventory..." << endl;
    ofstream saveFile("inventory.txt");
    saveFile << currentSize << "\n" << maxSize << "\n" << plantCapacity << "\n" << equipmentCapacity << "\n" << plantsInHand << "\n" << equipmentInHand; 
    saveFile.close();

}

void Inventory::addPlant() {

    int counter = 0;
    while (plantsInHand[counter] != "null") {
        
    }
        if ()
            plantsInHand

}

void Inventory::addEquipment() {

}


void Inventory::removeItem() {  

}  

void Inventory::removeEquipment() {  

} 

