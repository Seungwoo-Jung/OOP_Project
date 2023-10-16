#include "Plant.h"

#include <iostream>
#include <string>

#include "Item.h"
using namespace std;

// default contructor sets values to 0 or null, and activates the default Item
// contructor;
Plant::Plant() : Item() {
  lifespan = 0;
  age = 0;
  water = 0;
  growthRate = 0;
}

// Standard contructor feeds some values to the Item contructor, including a
// default "growing" status.It also sets some default values of age, water and
// growthRate as either 0, 100 or 1 respectively, and sets the input species
// value to be that variable value
Plant::Plant(int ID, string name, int life, int setPrice) : Item(ID, name, "growing", life, price) {
  age = 0;
  water = 100;
  growthRate = 1;
}

// functions declared as virtual in the Plant.h file to be used in subclasses
void Plant::plantGrow(int growthRate){};
int Plant::plantHarvest() { return 0; };
void Plant::plantWater(){};
void Plant::getStatus(){};
Plant::~Plant(){};