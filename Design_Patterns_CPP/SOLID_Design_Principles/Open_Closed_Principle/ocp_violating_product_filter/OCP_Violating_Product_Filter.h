//
// Created by laptop on 7/31/19.
//

#ifndef OPEN_CLOSED_PRINCIPLE_OCP_VIOLATING_PRODUCT_FILTER_H
#define OPEN_CLOSED_PRINCIPLE_OCP_VIOLATING_PRODUCT_FILTER_H


#include <vector>
#include "../shared/Product.h"

struct OCP_Violating_Product_Filter {
    std::vector<Product*> by_color(std::vector<Product*> items, Color color);
    std::vector<Product*> by_size(std::vector<Product*> items, Size size);
    std::vector<Product*> by_size_and_color(std::vector<Product*> items, Size size, Color color);
};

#endif //OPEN_CLOSED_PRINCIPLE_OCP_VIOLATING_PRODUCT_FILTER_H
