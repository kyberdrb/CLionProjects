#include "Name.h"
#include "RepeatPrintMixin.h"

int main() {
    Name name("Paul");
    name.print();

    std::cout << std::endl;

    RepeatPrintMixin<Name> repeatPrinter(name);
    repeatPrinter.repeat();
    return 0;
}
