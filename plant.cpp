#include "plant.h"

#include <string>

#include "item.h"
using namespace std;

plant::plant() : item() {
  areaUsed = 0;
  lifespan = 0;
  species = "null";
  age = 0;
  water = 100;
}
plant::plant(int ID, string name, float area, int life, string type)
    : item(ID, name, "growing") {
  areaUsed = area;
  lifespan = life;
  species = type;
  age = 0;
  water = 100;
}
void plant::plantGrow(){};
int plant::plantHarvest() { return 0; };
void plant::plantWater(){};
plant::~plant(){};