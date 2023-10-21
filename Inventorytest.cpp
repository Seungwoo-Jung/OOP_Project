#include <iostream>
#include <map>
#include <string>

#include "Equipment.h"
#include "Fruit.h"
#include "Grain.h"
#include "Inventory.h"
#include "Plant.h"

int main() {
  // Testing empty contructor and it's properties:

  Inventory in = Inventory();

  cout << "expected output: 27 lines of 'Unable, Inventory does not exist'"
       << endl
       << endl;

  // all functions should not actvate due to the object not existing,
  // hence we should expect to get the message "Unable, Inventory does
  // not exist" for each (27 times)
  in.openInventory();
  in.closeInventory();
  in.inventoryOpen();
  in.getContents();
  in.changeFunds(1);
  in.changeWheat(2);
  in.changeRice(3);
  in.changeRye(2);
  in.changeApple(3);
  in.changePear(2);
  in.changeBanana(3);
  in.pFull();
  in.pEmpty();
  in.eFull();
  in.eEmpty();
  in.getEquipment();
  in.getFunds();
  in.getWheat();
  in.getRice();
  in.getRye();
  in.getApple();
  in.getPear();
  in.getBanana();
  in.addPlant(new Fruit());
  in.addEquipment(new Equipment());
  in.removePlant(30);
  in.removeEquipment(10);

  // add lines to separate objects
  cout << endl << endl;

  cout << "expected output: 3 messages detailing a plant creation, followed by "
          "one for equipment"
       << endl
       << endl;

  // creating a proper Inventory object. Pointer used for testing purposes
  Inventory* inv = new Inventory(4, 4);

  // testing functions while inventory is closed, should output "Unable,
  // inventory not open" for each (2 times)

  cout << endl
       << endl
       << "expected output: 2 lines of 'Unable, Inventory not open'" << endl
       << endl;

  inv->getContents();
  inv->closeInventory();

  // opening inventory to enable functionality, and then testing if it's open
  // using a function The getContents function is automatically called and
  // tested during the opening
  cout << endl
       << endl
       << "expected output: '0, Opening Inventory, (results from getContents), "
          "1, followed by a line of Unable, Inventory not closed' "
       << endl
       << endl;

  cout << inv->inventoryOpen() << endl << endl;
  inv->openInventory();
  cout << inv->inventoryOpen() << endl;
  inv->openInventory();

  // testing the retrieval and alteration of the funds and plant totals

  // testing for initial values
  cout << endl << "expected output: 7 lines of 0" << endl << endl;

  cout << inv->getFunds() << endl;
  cout << inv->getWheat() << endl;
  cout << inv->getRye() << endl;
  cout << inv->getRice() << endl;
  cout << inv->getPear() << endl;
  cout << inv->getApple() << endl;
  cout << inv->getBanana() << endl;

  // testing for positive values
  cout << endl << "expected output: 4, 3, 8, 2, 99, 1332, 655" << endl << endl;
  inv->changeFunds(4);
  inv->changeWheat(3);
  inv->changeRye(8);
  inv->changeRice(2);
  inv->changePear(99);
  inv->changeApple(1332);
  inv->changeBanana(655);

  cout << inv->getFunds() << endl;
  cout << inv->getWheat() << endl;
  cout << inv->getRye() << endl;
  cout << inv->getRice() << endl;
  cout << inv->getPear() << endl;
  cout << inv->getApple() << endl;
  cout << inv->getBanana() << endl;

  // testing for null inputs
  cout << endl << "expected output: 4, 3, 8, 2, 99, 1332, 655" << endl << endl;
  inv->changeFunds(0);
  inv->changeWheat(0);
  inv->changeRye(0);
  inv->changeRice(0);
  inv->changePear(0);
  inv->changeApple(0);
  inv->changeBanana(0);

  cout << inv->getFunds() << endl;
  cout << inv->getWheat() << endl;
  cout << inv->getRye() << endl;
  cout << inv->getRice() << endl;
  cout << inv->getPear() << endl;
  cout << inv->getApple() << endl;
  cout << inv->getBanana() << endl;

  // testing for negatives and if the result would be negative
  cout << endl << "expected output: 1, 0, 0, 0, 98, 1326, 655" << endl << endl;
  inv->changeFunds(-3);
  inv->changeWheat(-3);
  inv->changeRye(-19343);
  inv->changeRice(-654);
  inv->changePear(-1);
  inv->changeApple(-6);
  inv->changeBanana(-0);

  cout << inv->getFunds() << endl;
  cout << inv->getWheat() << endl;
  cout << inv->getRye() << endl;
  cout << inv->getRice() << endl;
  cout << inv->getPear() << endl;
  cout << inv->getApple() << endl;
  cout << inv->getBanana() << endl;

  // testing adding a plant and equipment item:
  cout << endl
       << endl
       << "expected output: 1 message each detailing an added plant and "
          "equipment item"
       << endl
       << endl;
  inv->addPlant(new Fruit(10, "Apple", 100, 3));
  inv->addEquipment(new Equipment(11, "Hoe", 50, 2));

  // testing removing a plant and equipment item:
  cout
      << endl
      << endl
      << "expected output: 1 message each detailing the removal of a plant and "
         "equipment item"
      << endl
      << endl;
  inv->removePlant(10);
  inv->removeEquipment(11);

  // testing removing nonexistant plants
  cout << endl
       << endl
       << "expected output: 1 message each detailing failure to remove the "
          "object"
       << endl
       << endl;
  inv->removePlant(10);
  inv->removeEquipment(11);

  // testing adding more objects than is possible

  cout << endl
       << endl
       << "expected output: messages detailing the addition of objects until "
          "both are full, followed by error messages detailing failure to add "
          "more. There should be 1 successful message for Plants and 3 "
          "failures, along with 3 successful messages for Equipment and 1 "
          "failure"
       << endl
       << endl;

  // loop for adding objects fast. High loop values are used so as to not
  // conflict with existing ids. Grain is used to ensure both subclasses work
  for (int i = 50; i < 54; i++) {
    inv->addPlant(new Grain(i, "Rice", 30, 1));
  }
  for (int i = 60; i < 64; i++) {
    inv->addEquipment(new Equipment(i, "Pick", 40, 3));
  }

  // testing closing the Inventory
  cout << endl << endl << "expected output: Closing Inventory:" << endl << endl;
  inv->closeInventory();

  // testing destructor
  cout << endl
       << endl
       << "expected output: messages detailing deletions of all currently "
          "existing plants () and equipment ()"
       << endl
       << endl;
  delete inv;
  return 0;
}
