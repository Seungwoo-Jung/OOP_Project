#include <iostream>
#include <string>

#include "fruit.h"
#include "grain.h"
#include "item.h"
#include "plant.h"
using namespace std;

int main() {
  grain* p1 = new grain();
  fruit* p2 = new fruit();
  grain* p3 = new grain(1, "grain", 10.76, 100, "wheat", 10);
  fruit* p4 = new fruit(4, "fruit", 15.42, 500, "apple", 5);

  p1->getStatus();
  p2->getStatus();
  p3->getStatus();
  p4->getStatus();

  p1->plantGrow();
  p2->plantGrow();
  for (int i = 0; i < 110; i++) {
    p3->plantGrow();
    p3->plantWater();
  }
  for (int i = 0; i < 110; i++) {
    p4->plantGrow();
    p4->plantWater();
  }

  delete p1;
  delete p2;
  delete p3;
  delete p4;
  return 0;
}