#include <iostream>
#include <memory>

#include "ProblematicUniquePtrDeleterSigns.h"
#include "MoreExpressiveUniquePtrDeleter.h"

// https://www.fluentcpp.com/2017/09/01/make-custom-deleters-expressive/

void problematicUniquePtrDeleterSignsDemo() {
    std::cout << "problematicUniquePtrDeleterSignsDemo" << std::endl;
    //std::unique_ptr<Computer, void(*)(const Computer*)>;    // declaration does not declare anything

    ComputerConstPtr computer(new Computer, deleteComputer);

    // The deleter needs to be defined before defining the unique_ptr, otherwise the linker will output an error:
    //  "undefined reference to `store::electronics::gaming::deleteNamespacedComputer(store::electronics::gaming::NamespacedComputer const*)'"
    store::electronics::gaming::NamespacedComputerConstPtr(new store::electronics::gaming::NamespacedComputer(), store::electronics::gaming::deleteNamespacedComputer);
    store::electronics::gaming::NamespacedComputerConstPtr(new store::electronics::gaming::NamespacedComputer(), deleteSomething<store::electronics::gaming::NamespacedComputer>);
}

void moreExpressiveUniquePtrWithDeleterDemo() {
    std::cout << "moreExpressiveUniquePtrWithDeleterDemo" << std::endl;
    auto myComputer = util::makeConstUnique(new store::electronics::gaming::NamespacedComputer);
    auto myOtherComputer = util::makeConstUniqueDoNotDelete(new store::electronics::gaming::NamespacedComputer);

    store::electronics::gaming::NamespacedComputer namespacedComputerOnStack("stack-based computer");
    auto namespacedComputerOnHeap = util::makeConstUnique(new store::electronics::gaming::NamespacedComputer("heap-based computer"));
    auto namespacedCoputerOnStackWrapper = util::makeConstUniqueDoNotDelete(&namespacedComputerOnStack);
    std::cout << std::endl;
}

int main() {
    problematicUniquePtrDeleterSignsDemo();

    moreExpressiveUniquePtrWithDeleterDemo();

    return 0;
}