#include "item.h"

#include <string>

using namespace std;

Item::Item() {
  ID = 0;
  name = "null";
  status = "null";
}
Item::Item(int setID, string setname, string setstatus) {
  ID = setID;
  name = setname;
  status = setstatus;
}
Item::~Item() {}