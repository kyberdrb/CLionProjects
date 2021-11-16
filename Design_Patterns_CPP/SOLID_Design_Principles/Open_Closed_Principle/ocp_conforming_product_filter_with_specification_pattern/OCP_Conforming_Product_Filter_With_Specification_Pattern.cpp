//
// Created by laptop on 7/31/19.
//

#include "OCP_Conforming_Product_Filter_With_Specification_Pattern.h"

std::vector<Product *> OCP_Conforming_Product_Filter_With_Specification_Pattern::filter(
        std::vector<Product *> items,
        Specification<Product> &spec)
{
    std::vector<Product *> result;
    for (const auto& item : items) {
        if (spec.is_statisfied(item)) {
            result.emplace_back(item);
        }
    }
    return result;
}
