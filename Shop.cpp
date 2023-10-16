#include "Shop.h"

Shop::Shop() {
    //setting the item costs.
}

void Shop::buyGrain(Inventory &inventory, int amount) {
    // double cost =  * amount; (need to find the way to load which grain and its price)

    if (inventory.getFunds() >= cost) {
        inventory.changeFunds(-cost);
        inventory.changeGrain(amount);
        cout << "You have bought " << amount << " grains for $" << cost << endl;
    } else {
        cout << "Not enough funds to buy grains." << endl;
    }
}

void Shop::sellGrain(Inventory &inventory, int amount) {
    if (inventory.getGrain() >= amount) {
        // double revenue =  * amount;  (need to find the way how to load which grain and its price)
        inventory.changeFunds(revenue);
        inventory.changeGrain(-amount);
        cout << "You have sold "<<amount<<" grains for $"<<revenue<<endl; 
    } else { 
        cout<<"Not enough grain in your Inventory to sell."<<endl; 
    }
}

void Shop::buyFruit(Inventory &inventory, int amount) { 
    // double cost =  *amount; (need to find the way how to load which fruit and its price)

    if(inventory.getFunds() >= cost){
        inventory.changeFunds(-cost);  
        inventory.changeFruit(amount);
        cout<<"You have bought "<<amount<<" fruits for $"<<cost<<endl;   
    } else {
        cout<<"Not enough funds to buy fruits."<<endl;   
    }
}

void Shop::sellFruit(Inventory &inventory,int amount){
    if(inventory.getFruit()>=amount){
        // double revenue = fruitPrice * amount; (need to find the way to load which fruit and its price)
        inventory.changeFunds(revenue);  
        inventory.changeFruit(-amount);
        cout<<"You have sold "<<amount<<" fruits for $"<<revenue<<endl; 
    } else {
        cout<<"Not enough fruit in your Inventory to sell."<<endl; 
    }
}

void Shop::buyEquipment(Inventory &inventory, Equipment* equipment) {
    // double cost = (need to find the way to load which equipment and its price)

    if (inventory.getFunds() >= cost) {
        inventory.changeFunds(-cost);
        inventory.addEquipment(equipment);
        cout << "You have bought an equipment for $" << cost << endl;
    } else {
        cout << "Not enough funds to buy the equipment." << endl;
    }
}

void Shop::sellEquipment(Inventory &inventory, Equipment* equipment) {
    // double revenue = (need to find the way to load which equipment and its price)

    if (equipment != nullptr && !equipment->itemEquipped()) {
        inventory.removeEquipment(equipment->getID());
        inventory.changeFunds(revenue);
        delete equipment;
        cout << "You have sold an piece of equipment for $" << revenue << endl;
    } else {
        cout<<"No such unequipped item in your Inventory to sell."<<endl; 
    }
}