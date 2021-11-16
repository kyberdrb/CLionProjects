//
// Created by laptop on 7/31/19.
//

#ifndef OPEN_CLOSED_PRINCIPLE_COLOR_SPECIFICATION_H
#define OPEN_CLOSED_PRINCIPLE_COLOR_SPECIFICATION_H


#include "Specification.h"
#include "../shared/Product.h"

struct Color_Specification : public Specification<Product> {
    Color color;
    explicit Color_Specification(Color color);

    bool is_statisfied(Product *item) override;
};


#endif //OPEN_CLOSED_PRINCIPLE_COLOR_SPECIFICATION_H
