#ifndef EQUIPMENT_H
#define EQUIPMENT_H
#include <string>

#include "Item.h"

using namespace std;

class Equipment : public Item {
 private:
  int effect;
  bool equipped;
  int currentUses;

 public:
  Equipment();
  Equipment(int ID, string name, int lifespan, int effect);
  ~Equipment();
  void getStatus() override;
  int getEffect();
  bool itemEquipped();
  void equip();
  void unequip();
  int use();
};

#endif