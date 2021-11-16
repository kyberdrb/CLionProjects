// Internal and External Linkage in C++: http://www.goldsborough.me/c/c++/linker/2016/03/30/19-34-25-internal_and_external_linkage_in_c++/

#include <iostream>
#include "global.h"

int main() {
    std::cout << Global::clock_rate << std::endl;

    Global::clock_rate=10;

    std::cout << Global::clock_rate << std::endl;
    return 0;
}
