#include <iostream>
#include <string>

#include "Fruit.h"
#include "Grain.h"
#include "Item.h"
#include "Plant.h"
using namespace std;

int main() {
  Grain* p1 = new Grain();
  Fruit* p2 = new Fruit();
  Grain* p3 = new Grain(1, "grain", 100, "wheat", 10);
  Fruit* p4 = new Fruit(4, "fruit", 500, "apple", 5);

  p3->getStatus();
  p4->getStatus();

  p1->plantGrow(1);
  p2->plantGrow(3);

  for (int i = 0; i < 19; i++) {
    p3->plantGrow(2);
  }

  for (int i = 0; i < 19; i++) {
    p4->plantGrow(2);
  }

  p3->plantWater();
  p4->plantWater();

  for (int i = 0; i < 19; i++) {
    p3->plantGrow(2);
  }

  for (int i = 0; i < 200; i++) {
    p4->plantGrow(2);
    p4->plantWater();
  }
  for (int i = 0; i < 19; i++) {
    p4->plantGrow(2);
  }

  p3->plantWater();
  p4->plantWater();

  p3->getStatus();
  p4->getStatus();

  int fruitharvest = p4->plantHarvest();
  int grainyield = p3->plantHarvest();

  cout << fruitharvest << " " << grainyield << endl;

  p3->getStatus();
  p4->getStatus();

  delete p1;
  delete p2;
  delete p3;
  delete p4;

  return 0;
}