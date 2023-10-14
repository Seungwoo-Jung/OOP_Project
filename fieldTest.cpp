#include "Field.h"
#include "Plant.h"
#include "Grain.h"

#include <iostream>

int main(){

    Field field(5, 5);

    Grain grain;

    field.set_plant(&grain, 1, 1);

    for (int i = 0; i < field.get_sizeM(); i++){
        for (int j = 0; j < field.get_sizeN(); j++){
            std::cout << field.get_plant(i, j) << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    return 0;
}