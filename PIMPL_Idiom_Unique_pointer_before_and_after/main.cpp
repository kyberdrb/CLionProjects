#include <iostream>

#include "OldFridge.h"
#include "UniquePtrPIMPL_Idiom/Fridge.h"

// https://www.fluentcpp.com/2017/09/22/make-pimpl-using-unique_ptr/
// GotW #100: Compilation Firewalls (Difficulty: 6/10): https://herbsutter.com/gotw/_100/

int main() {
    std::cout << "Before PIMPL - direct dependency" << std::endl;
    OldFridge fridge;
    fridge.coolDown();

    std::cout << std::endl;

    std::cout << "After PIMPL - indirect dependency - driving class wraps implementation class" << std::endl;
    Fridge anotherFridge;
    anotherFridge.coolDown();
    return 0;
}