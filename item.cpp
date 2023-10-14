#include "item.h"

#include <string>

using namespace std;

item::item() {
  ID = 0;
  name = "null";
  status = "null";
}
item::item(int setID, string setname, string setstatus) {
  ID = setID;
  name = setname;
  status = setstatus;
}
item::~item() {}