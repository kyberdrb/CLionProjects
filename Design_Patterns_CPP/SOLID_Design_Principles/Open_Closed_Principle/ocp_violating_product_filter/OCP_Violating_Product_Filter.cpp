//
// Created by laptop on 7/31/19.
//

#include "OCP_Violating_Product_Filter.h"

std::vector<Product*> OCP_Violating_Product_Filter::by_color(std::vector<Product*> items, Color color) {
    std::vector<Product*> result;
    for (const auto& product : items) {
        if (product->color == color) {
            result.emplace_back(product);
        }
    }
    return result;
}

std::vector<Product*> OCP_Violating_Product_Filter::by_size(std::vector<Product*> items, Size size) {
    std::vector<Product*> result;
    for (const auto& product : items) {
        if (product->size == size) {
            result.emplace_back(product);
        }
    }
    return result;
}

std::vector<Product*> OCP_Violating_Product_Filter::by_size_and_color(
        std::vector<Product*> items,
        Size size,
        Color color)
{
    std::vector<Product*> result;
    for (const auto& product : items) {
        if (product->size == size && product->color == color) {
            result.emplace_back(product);
        }
    }
    return result;
}