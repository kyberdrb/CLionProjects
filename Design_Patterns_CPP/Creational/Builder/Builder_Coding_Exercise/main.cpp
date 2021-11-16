#include <iostream>
#include "CodeBuilder.h"

int main() {
    auto cb = CodeBuilder{"Person"}
        .add_field("name", "string")
        .add_field("age", "int");

    std::cout << cb << std::endl;
    return 0;
}