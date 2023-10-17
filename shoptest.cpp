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
       << "Expected output: Unable to buy plant, Inventory full, followed by a "
          "line stating we bought no wheat for no money, and the current funds "
          "should stay as 100"
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
       << "Expected output: 2 lines stating lack of funds, followed by one "
          "stating we bought nothing. The funds should then remain at 20"
       << endl
       << endl;

  // buying a plant when there is low funding to test response
  shop->buyPlant(*inv, 2, 5);

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