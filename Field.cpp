#include "Field.h"

#include <iostream>
#include <string>

Field::Field() {
  soilState = "default";
  fieldSizeM = 1;
  fieldSizeN = 1;
  fieldMatrix = new Plant*[fieldSizeM][fieldSizeN];
}

Field::Field(int size_row, int size_column) {
  soilState = "default";
  fieldSizeM = size_row;
  fieldSizeN = size_column;
  fieldMatrix = new Plant*[fieldSizeM][fieldSizeN];
}