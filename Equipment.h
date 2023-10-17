#ifndef EQUIPMENT_H
#define EQUIPMENT_H
<<<<<<< HEAD

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
  bool itemEquipped();
  void equip();
  void unequip();
  int use();
=======
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
      Equipment(int ID, string name, int lifespan, int effect, int setPrice);
      ~Equipment();
      void getStatus() override;
      bool itemEquipped();
      void equip();
      void unequip();
      int use();
>>>>>>> 25f174546402ee47766097f73d4208065f575038
};

#endif