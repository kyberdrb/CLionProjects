//
// Created by laptop on 7/31/19.
//

#ifndef OPEN_CLOSED_PRINCIPLE_SIZE_SPECIFICATION_H
#define OPEN_CLOSED_PRINCIPLE_SIZE_SPECIFICATION_H


#include "Specification.h"
#include "../shared/Size.h"
#include "../shared/Product.h"

struct Size_Specification : public Specification<Product> {
    Size size;

    explicit Size_Specification(Size size);

    bool is_statisfied(Product *item) override;

};


#endif //OPEN_CLOSED_PRINCIPLE_SIZE_SPECIFICATION_H
