#ifndef FIELD_H
#define FIELD_H
#include <string>
#include <vector>
#include "Plant.h"

class Field {
    private:
        std::vector<std::vector<plant>> fieldMatrix;
        int fieldSizeM;
        int fieldSizeN;
        std::string soilState;

    public:
        Field();
        Field(int size_row, int size_column);
        ~Field();
};

#endif