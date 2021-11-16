//
// Created by laptop on 7/31/19.
//

#ifndef OPEN_CLOSED_PRINCIPLE_OCP_CONFORMING_PRODUCT_FILTER_WITH_SPECIFICATION_PATTERN_H
#define OPEN_CLOSED_PRINCIPLE_OCP_CONFORMING_PRODUCT_FILTER_WITH_SPECIFICATION_PATTERN_H

#include "Filter.h"
#include "../shared/Product.h"

struct OCP_Conforming_Product_Filter_With_Specification_Pattern : Filter<Product> {
    std::vector<Product *> filter(
            std::vector<Product *> items,
            Specification<Product> &spec) override;
};


#endif //OPEN_CLOSED_PRINCIPLE_OCP_CONFORMING_PRODUCT_FILTER_WITH_SPECIFICATION_PATTERN_H
