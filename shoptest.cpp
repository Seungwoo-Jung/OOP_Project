#include <iostream>

#include "Equipment.h"
#include "Fruit.h"
#include "Grain.h"
#include "Inventory.h"
#include "Item.h"
#include "Plant.h"
#include "Shop.h"

using namespace std;

int main() {
  // making object
  Shop* shop = new Shop();

  cout << endl
       << endl
       << "Expected output: 4 lines of object creation from inventory "
          "construction, followed by the current funds (1000)"
       << endl
       << endl;

  // making inventory to use when testing, set initial funcds to 1000 and print
  // that value to test
  Inventory* inv = new Inventory(10, 10);
  inv->changeFunds(1000);
  cout << inv->getFunds() << endl;

  cout << endl
       << endl
       << "Expected output: 5 lines of 'Unable, Shop is not open'" << endl
       << endl;

  // testing functions when shop closed, none should work
  shop->buyPlant(*inv, 1, 2);
  shop->sellPlant(*inv, 1, 2);
  shop->buyEquipment(*inv, 2);
  shop->sellEquipment(*inv, 1, 2);
  shop->closeShop();

  cout << endl
       << endl
       << "Expected output: Opening shop: followed by 'Unable, Shop is already "
          "open"
       << endl
       << endl;

  // testing opening of shop and opening again while currently open
  shop->openShop();
  shop->openShop();

  cout << endl
       << endl
       << "Expected output: 6 lines detailing no plants being bought and $0 "
          "being spent, followed by 10 lines detailing the additioml of a "
          "plant, then 1 line detailing failure to add plant, and 2 lines of "
          "buying nothing."
       << endl
       << endl;

  // testing buying no plants with items in inventory
  shop->buyPlant(*inv, 0, 0);
  shop->buyPlant(*inv, 0, 1);
  shop->buyPlant(*inv, 0, 2);
  shop->buyPlant(*inv, 0, 3);
  shop->buyPlant(*inv, 0, 4);
  shop->buyPlant(*inv, 0, 5);

  // adding plants to the inventory to make it full
  inv->addPlant(new Fruit(1, "Apple", 50, 2));
  inv->addPlant(new Fruit(2, "Apple", 50, 2));
  inv->addPlant(new Fruit(3, "Apple", 50, 2));
  inv->addPlant(new Fruit(4, "Apple", 50, 2));
  inv->addPlant(new Fruit(5, "Apple", 50, 2));
  inv->addPlant(new Fruit(6, "Apple", 50, 2));
  inv->addPlant(new Fruit(7, "Apple", 50, 2));
  inv->addPlant(new Fruit(8, "Apple", 50, 2));
  inv->addPlant(new Fruit(9, "Apple", 50, 2));
  inv->addPlant(new Fruit(10, "Apple", 50, 2));
  inv->addPlant(new Fruit(11, "Apple", 50, 2));

  // testing buying 0 plants with a full inventory
  shop->buyPlant(*inv, 0, 0);
  shop->buyPlant(*inv, 0, 0);

  cout << endl
       << endl
       << "Expected output: 10 lines detailing the removal of plants with 1 "
          "line of failure to remove, then 6 lines of buying nothing, followed "
          "by 3 lines of qadding plants, and ending with the funds (1000)"
       << endl
       << endl;

  // removing current plants in the inventory to make it empty
  inv->removePlant(1);
  inv->removePlant(2);
  inv->removePlant(3);
  inv->removePlant(5);
  inv->removePlant(6);
  inv->removePlant(7);
  inv->removePlant(8);
  inv->removePlant(9);
  inv->removePlant(10);
  inv->removePlant(11);

  // testing buying no plants with an empty inventory
  shop->buyPlant(*inv, 0, 0);
  shop->buyPlant(*inv, 0, 1);
  shop->buyPlant(*inv, 0, 2);
  shop->buyPlant(*inv, 0, 3);
  shop->buyPlant(*inv, 0, 4);
  shop->buyPlant(*inv, 0, 5);

  // restoring initial plants for later testing
  inv->addPlant(new Fruit(1, "Apple", 50, 2));
  inv->addPlant(new Grain(2, "Wheat", 20, 10));
  inv->addPlant(new Grain(3, "Rice", 20, 15));

  // printing funds to ensure they did not change
  cout << inv->getFunds() << endl;

  cout << endl
       << endl
       << "Expected output: lines for plant creation with ID's 5 through 11, "
          "followed by a line where the Inventory is full. the lines for 9 and "
          "10 are next to each other along with 11 and the 'FULL' line, while "
          "all other gaps have a line specifying the buying of an object. we "
          "should in order buy 1 wheat, 1 rice, 1 rye, 1 apple, 2 pear and 2 "
          "banana, each showing the prices of 15, 20, 25, 50, 150 and 100 "
          "respectively."
       << endl
       << endl;

  // testing buying 8 plants using the appropriate values, splitting them
  // between the 6 types. Inventory should fill up two too many.
  shop->buyPlant(*inv, 1, 0);
  shop->buyPlant(*inv, 1, 1);
  shop->buyPlant(*inv, 1, 2);
  shop->buyPlant(*inv, 1, 3);
  shop->buyPlant(*inv, 2, 4);
  shop->buyPlant(*inv, 2, 5);

  cout << endl
       << endl
       << "Expected output: same format as plant buying, id's of creation are "
          "5 through 13, this time all being spaced apart by a buy line. we "
          "should buy in order a hoe, shovel, fertiliser, and a weeder, before "
          "buying one more of each and a final hoe. The final 2 lines should "
          "say full inventory. Prices are 15, 20, 25, and 50 respectively."
       << endl
       << endl;

  // testing buying equipment - again inventory should fill up with 2 left over
  shop->buyEquipment(*inv, 0);
  shop->buyEquipment(*inv, 1);
  shop->buyEquipment(*inv, 2);
  shop->buyEquipment(*inv, 3);
  shop->buyEquipment(*inv, 0);
  shop->buyEquipment(*inv, 1);
  shop->buyEquipment(*inv, 2);
  shop->buyEquipment(*inv, 3);
  shop->buyEquipment(*inv, 0);
  shop->buyEquipment(*inv, 1);
  shop->buyEquipment(*inv, 2);

  // altering funds for testing full inventory out:
  inv->changeFunds(-1000);
  inv->changeFunds(100);

  cout << endl
       << endl
       << "Expected output: Unable to buy plant, Inventory full, followed by "
          "the current funds which should stay 100"
       << endl
       << endl;

  // testing buying a plant with a full inventory
  shop->buyPlant(*inv, 1, 0);

  // checking that funds have not changed
  cout << inv->getFunds() << endl;

  cout << endl
       << endl
       << "Expected output: Unable to buy equipment, Inventory full, followed "
          "by the current funds which stay 100"
       << endl
       << endl;

  // testing buying equipment with a full inventory
  shop->buyEquipment(*inv, 1);

  // checking that funds have not changed
  cout << inv->getFunds() << endl;

  // altering funds for testing running out:
  inv->changeFunds(-1000);
  inv->changeFunds(20);

  cout << endl
       << endl
       << "Expected output: 2 lines stating lack of funds, followed by a line "
          "detailing 0 plants were bought, and then the "
          "funds which remain at 20"
       << endl
       << endl;

  // buying a plant when there is low funding to test response
  shop->buyPlant(*inv, 2, 5);
  shop->buyPlant(*inv, 0, 3);

  // checking that funds have not changed
  cout << inv->getFunds() << endl;

  cout << endl
       << endl
       << "Expected output: 1 line stating lack of funds, followed by the "
          "funds which remain at 20"
       << endl
       << endl;

  // testing for equipment this time
  shop->buyEquipment(*inv, 3);

  // checking that funds have not changed
  cout << inv->getFunds() << endl;

  cout << endl
       << endl
       << "Expected output: a line stating an item is missing, followed by "
          "successfully removing a shovel with ID 4, and then another item "
          "missing. Then there should be sequential removing of all remaining "
          "euipment that was bought in the same order it was bought. Prices "
          "for the hoe, shovel, fertiliser and equipment are 37, 12, 50 and 25 "
          "respectivedly. A final line stating the Inventory is Empty should "
          "follow."
       << endl
       << endl;

  // testing selling equipment
  shop->sellEquipment(*inv, 3, 1);
  shop->sellEquipment(*inv, 4, 1);
  shop->sellEquipment(*inv, 4, 1);
  shop->sellEquipment(*inv, 5, 0);
  shop->sellEquipment(*inv, 6, 1);
  shop->sellEquipment(*inv, 7, 2);
  shop->sellEquipment(*inv, 8, 3);
  shop->sellEquipment(*inv, 9, 0);
  shop->sellEquipment(*inv, 10, 1);
  shop->sellEquipment(*inv, 11, 2);
  shop->sellEquipment(*inv, 12, 3);
  shop->sellEquipment(*inv, 13, 0);
  shop->sellEquipment(*inv, 14, 1);

  cout << endl
       << endl
       << "Expected output: current funds figure of 317" << endl
       << endl;

  // testing funds to make sure these processes function correctly. This also
  // tests that funds do not change if the inventory is empty or the item is not
  // there.
  cout << inv->getFunds();

  cout << endl
       << endl
       << "Expected Output: 6 lines of 'Unable to sell, Inventory Empty, "
          "followed by 6 lines of selling 0 plants for $0"
       << endl
       << endl;

  // testing selling plants with empty inventory:

  shop->sellPlant(*inv, 3, 0);
  shop->sellPlant(*inv, 4, 1);
  shop->sellPlant(*inv, 4, 2);
  shop->sellPlant(*inv, 5, 3);
  shop->sellPlant(*inv, 6, 4);
  shop->sellPlant(*inv, 7, 5);

  // testing selling no plants with empty inventory
  shop->sellPlant(*inv, 0, 0);
  shop->sellPlant(*inv, 0, 1);
  shop->sellPlant(*inv, 0, 2);
  shop->sellPlant(*inv, 0, 3);
  shop->sellPlant(*inv, 0, 4);
  shop->sellPlant(*inv, 0, 5);

  // adding plants of one type to test response
  inv->changeWheat(10);

  cout << endl
       << endl
       << "Expected Output: 6 lines of 'No (name of plant) in your Inventory "
          "to sell', followd by 6 lines of selling nothing"
       << endl
       << endl;

  // testing selling Plants when none exist in Inventory but Inventory is not
  // empty
  shop->sellPlant(*inv, 4, 1);
  shop->sellPlant(*inv, 4, 2);
  shop->sellPlant(*inv, 5, 3);
  shop->sellPlant(*inv, 6, 4);
  shop->sellPlant(*inv, 7, 5);

  // changing plant quantities to test this behaviour for wheat
  inv->changeWheat(-10);
  inv->changeRice(10);

  // testing for Wheat when none exist
  shop->sellPlant(*inv, 3, 0);

  // testing selling no items when none exist but inventory is not empty
  shop->sellPlant(*inv, 0, 0);
  shop->sellPlant(*inv, 0, 2);
  shop->sellPlant(*inv, 0, 3);
  shop->sellPlant(*inv, 0, 4);
  shop->sellPlant(*inv, 0, 5);

  // changing quantities back for testing Rice:
  inv->changeWheat(10);
  inv->changeRice(-10);

  // testing for rice
  shop->sellPlant(*inv, 0, 1);

  // adding plants to all types for testing
  inv->changeRye(10);
  inv->changeApple(10);
  inv->changePear(10);
  inv->changeBanana(10);
  inv->changeRice(10);

  cout << endl << endl << "Expected Output: 6 lines of 10" << endl << endl;

  // printing these values to ensure that all are equal to 10
  cout << inv->getWheat() << endl;
  cout << inv->getRice() << endl;
  cout << inv->getRye() << endl;
  cout << inv->getApple() << endl;
  cout << inv->getPear() << endl;
  cout << inv->getBanana() << endl;

  cout << endl
       << endl
       << "Expected output: 6 lines of 0 (name of plant) being sold for $0, "
          "followed by the current funds still at 317"
       << endl
       << endl;

  // testing selling no plants
  shop->sellPlant(*inv, 0, 0);
  shop->sellPlant(*inv, 0, 1);
  shop->sellPlant(*inv, 0, 2);
  shop->sellPlant(*inv, 0, 3);
  shop->sellPlant(*inv, 0, 4);
  shop->sellPlant(*inv, 0, 5);
  cout << inv->getFunds() << endl;

  cout << endl
       << endl
       << "Expected output: 6 lines detailing selling a different type of "
          "plant. The amount sold for each should be 1, 4, 2, 5, 6, 1 "
          "respectively, for prices of 2, 12, 8, 25, 42, 10."
       << endl
       << endl;

  // testing selling plants when some exist of varying amounts
  shop->sellPlant(*inv, 1, 0);
  shop->sellPlant(*inv, 4, 1);
  shop->sellPlant(*inv, 2, 2);
  shop->sellPlant(*inv, 5, 3);
  shop->sellPlant(*inv, 6, 4);
  shop->sellPlant(*inv, 1, 5);

  cout << endl << endl << "Expected Output: 416" << endl << endl;

  // printing funds to ensure they are correct:
  cout << inv->getFunds() << endl;

  cout << endl
       << endl
       << "Expected output: 6 lines detailing selling a different type plant. "
          "The amount sold for each should be 9, 6, 8, 5, 4, 9 respectively, "
          "for prices of 18, 18, 32, 25, 28, 90. each line has a message "
          "before it stating that you have too few to sell the amount you want "
          "and will sell all remaining in your inventoruy"
       << endl
       << endl;

  // testing selling too many plants
  shop->sellPlant(*inv, 11, 0);
  shop->sellPlant(*inv, 14, 1);
  shop->sellPlant(*inv, 12, 2);
  shop->sellPlant(*inv, 15, 3);
  shop->sellPlant(*inv, 16, 4);
  shop->sellPlant(*inv, 17, 5);

  cout << endl << endl << "Expected Output: 627" << endl << endl;

  // printing funds to ensure they are correct:
  cout << inv->getFunds() << endl;

  cout << endl
       << endl
       << "Expected output: 2 lines of Invalid amount, must be greater than or "
          "equaal to 0"
       << endl;

  // testing buying and selling plants when the amount is negative
  shop->buyPlant(*inv, -3, 0);
  shop->sellPlant(*inv, -3, 0);

  cout << endl << endl << "Expected Output: 627" << endl << endl;

  // printing funds to ensure they are correct:
  cout << inv->getFunds() << endl;

  cout << endl << endl << "Expected output: Closing shop:" << endl << endl;

  // testing closing shop
  shop->closeShop();

  cout << endl
       << endl
       << "Expected output: lines deleting all items and then the Shop. 4 "
          "fruits, 5 grains, then 1 fruit should be deleted, followed by all "
          "10 equipment, and then the shop"
       << endl
       << endl;

  // deleting objects and testing shop destructor
  delete inv;
  delete shop;
  return 0;
}