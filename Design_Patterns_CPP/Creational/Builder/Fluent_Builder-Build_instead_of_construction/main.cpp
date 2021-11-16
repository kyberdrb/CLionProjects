#include <iostream>
#include "HtmlBuilder.h"

int main() {

    auto htmlBuilder = HtmlBuilder
            ::create("ol")
            .addChild("li", "some")
            .addChild("li", "thing")
            .build();
    std::cout << htmlBuilder.str() << std::endl;

    return 0;
}