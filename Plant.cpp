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
Plant::Plant(int ID, string name, int life) : Item(ID, name, "growing", life) {
  age = 0;
  water = 100;
  growthRate = 1;
}

// sets the growth rate of the plant using the input
void Plant::setRate(int rate) { growthRate = rate; }

// returns the growth rate of the plant
int Plant::getRate() { return growthRate; };

// functions declared as virtual in the Plant.h file to be used in subclasses
void Plant::plantGrow(int growthRate) {}
int Plant::plantHarvest() { return 0; }
void Plant::plantWater() {}
void Plant::getStatus() {}
Plant::~Plant() {}