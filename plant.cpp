#include "plant.h"

#include <string>

#include "item.h"
using namespace std;

Plant::Plant() : Item() {
  areaUsed = 0;
  lifespan = 0;
  species = "null";
  age = 0;
  water = 100;
}
Plant::Plant(int ID, string name, float area, int life, string type)
    : Item(ID, name, "growing") {
  areaUsed = area;
  lifespan = life;
  species = type;
  age = 0;
  water = 100;
}
void Plant::plantGrow(){};
int Plant::plantHarvest() { return 0; };
void Plant::plantWater(){};
Plant::~Plant(){};