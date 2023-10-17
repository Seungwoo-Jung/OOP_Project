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

  cout << "expected output: 14 lines of 'Unable, Inventory does not exist'"
       << endl
       << endl;

  // all functions should not actvate due to the object not existing,
  // hence we should expect to get the message "Unable, Inventory does
  // not exist" for each (14 times)
  in.openInventory();
  in.closeInventory();
  in.inventoryOpen();
  in.getContents();
  in.changeFunds(1);
  in.changeFruit(2);
  in.changeGrain(3);
  in.getFunds();
  in.getFruit();
  in.getGrain();
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
  // inventory not open" for each (6 times)

  cout << endl
       << endl
       << "expected output: 6 lines of 'Unable, Inventory not open'" << endl
       << endl;

  inv->getContents();
  inv->addPlant(new Fruit());
  inv->addEquipment(new Equipment());
  inv->removePlant(5);
  inv->removeEquipment(4);
  inv->closeInventory();

  // opening inventory to enable functionality, and then testing if it's open
  // using a function The getContents function is automatically called and
  // tested during the opening
  cout << endl
       << endl
       << "expected output: '0, Opening Inventory, (results from getContents), "
          "1' "
       << endl
       << endl;

  cout << inv->inventoryOpen() << endl << endl;
  inv->openInventory();
  cout << inv->inventoryOpen() << endl;

  // testing the retrieval and alteration of the Funds/Fruit/Grain totals

  // testing for initial values
  cout << endl << "expected output: 0, 0, 0" << endl << endl;

  cout << inv->getFunds() << endl;
  cout << inv->getGrain() << endl;
  cout << inv->getFruit() << endl;

  // testing for positive values
  cout << endl << "expected output: 59.7, 6000, 2" << endl << endl;
  inv->changeFunds(59.7);
  inv->changeGrain(6000);
  inv->changeFruit(2);

  cout << inv->getFunds() << endl;
  cout << inv->getGrain() << endl;
  cout << inv->getFruit() << endl;

  // testing for null inputs
  cout << endl << "expected output: 59.7, 6000, 2" << endl << endl;
  inv->changeFunds(0);
  inv->changeGrain(0);
  inv->changeFruit(0);

  cout << inv->getFunds() << endl;
  cout << inv->getGrain() << endl;
  cout << inv->getFruit() << endl;

  // testing for negatives and if the result would be negative
  cout << endl << "expected output: 1.35, 5998, 0" << endl << endl;
  inv->changeFunds(-58.35);
  inv->changeGrain(-2);
  inv->changeFruit(-9122);

  cout << inv->getFunds() << endl;
  cout << inv->getGrain() << endl;
  cout << inv->getFruit() << endl;

  // testing adding a plant and equipment item:
  cout << endl
       << endl
       << "expected output: 1 message each detailing an added plant and "
          "equipment item"
       << endl
       << endl;
  inv->addPlant(new Fruit(10, "Apple", 100, 3, 6.3));
  inv->addEquipment(new Equipment(11, "Hoe", 50, 2, 9.5));

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
    inv->addPlant(new Grain(i, "Rice", 30, 1, 4.8));
  }
  for (int i = 60; i < 64; i++) {
    inv->addEquipment(new Equipment(i, "Pick", 40, 3, 1.6));
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
