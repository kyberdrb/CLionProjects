//
// Created by laptop on 7/31/19.
//

#include "Size_Specification.h"

Size_Specification::Size_Specification(Size size) : size(size) {}

bool Size_Specification::is_statisfied(Product *item) {
    return item->size == this->size;
}
