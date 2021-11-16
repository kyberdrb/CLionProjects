#include <iostream>
#include <vector>
#include "shared/Product.h"
#include "ocp_violating_product_filter/OCP_Violating_Product_Filter.h"
#include "ocp_conforming_product_filter_with_specification_pattern/OCP_Conforming_Product_Filter_With_Specification_Pattern.h"
#include "ocp_conforming_product_filter_with_specification_pattern/Color_Specification.h"
#include "ocp_conforming_product_filter_with_specification_pattern/Size_Specification.h"
#include "ocp_conforming_product_filter_with_specification_pattern/TwoSpecificationsCombinator.h"
#include "shared/Color.h"

int main() {
    Product apple{"apple", Color::green, Size::small};
    Product tree{"tree", Color::green, Size::large};
    Product house{"house", Color::blue, Size::large};
    std::vector<Product*> items{ &apple, &tree, &house };

    OCP_Violating_Product_Filter pf;
    auto green_things = pf.by_color(items, Color::green);
    for (const auto& thing : green_things) {
        std::cout << thing->name << " is green" << std::endl;
    }

    std::cout << std::endl;

    OCP_Conforming_Product_Filter_With_Specification_Pattern better_filter;
    Color_Specification green{Color::green};
    for (const auto& item : better_filter.filter(items, green)) {
        std::cout << item->name << std::endl;
    }

    std::cout << std::endl;
    Size_Specification large{Size::large};
    for (const auto& item : better_filter.filter(items, large)) {
        std::cout << item->name << std::endl;
    }

    std::cout << std::endl;
    TwoSpecificationsCombinator<Product> green_and_large(green, large);
    for (const auto& item : better_filter.filter(items, green_and_large)) {
        std::cout << item->name << std::endl;
    }

    return 0;
}