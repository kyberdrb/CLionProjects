//
// Created by laptop on 7/29/19.
//

#include <iostream>
#include "Type_Casting.h"
#include "static_cast/Static_Cast.h"
#include "dynamic_cast/Dynamic_Cast.h"
#include "reinterpret_cast/Reinterpret_Cast.h"

void Type_Casting::exercise() {
    Static_Cast staticCast;
    staticCast.exercise();

    std::cout << std::endl;
    Dynamic_Cast dynamicCast;
    dynamicCast.exercise();

    std::cout << std::endl;
    Reinterpret_Cast reinterpretCast;
    reinterpretCast.exercise();
}
