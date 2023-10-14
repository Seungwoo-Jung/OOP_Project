#include <iostream>
#include <string>

#include "Equipment.h"
#include "Item.h"

using namespace std;

int main() {
  Equipment* e1 = new Equipment();
  Equipment* e2 = new Equipment(1, "hoe", 100, 2);

  e1->getStatus();
  e2->getStatus();

  cout << e1->itemEquipped() << endl;
  cout << e2->itemEquipped() << endl;

  e1->equip();
  e2->equip();

  e1->getStatus();
  e2->getStatus();

  cout << e1->itemEquipped() << endl;
  cout << e2->itemEquipped() << endl;

  e1->unequip();
  e2->unequip();

  cout << e1->itemEquipped() << endl;
  cout << e2->itemEquipped() << endl;

  e2->equip();

  cout << e1->use() << endl;
  cout << e2->use() << endl;

  for (int i = 0; i < 100; i++) {
    e2->use();
  }

  e2->getStatus();

  delete e1;
  delete e2;
  return 0;
}