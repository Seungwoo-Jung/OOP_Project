#include <iostream>
#include <string>
#include "Field.h"


Field::Field() {
    soilState = "default";
    fieldSizeM = 1;
    fieldSizeN = 1;
    fieldMatrix = new plant*[fieldSizeM][fieldSizeN];
}

Field::Field(int size_row, int size_column) {
    soilState = "default";
    fieldSizeM = size_row;
    fieldSizeN = size_column;
    fieldMatrix = new plant*[fieldSizeM][fieldSizeN];
}