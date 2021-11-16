#include <iostream>
#include "Test.h"
#include "Bottle.h"

template<typename T>
void print(T obj) {
    std::cout << "print from template: " << obj << std::endl << std::flush;
}

void print(int num) {
    std::cout << "print from basic function: " << num << std::endl << std::flush;
}

template <typename T>
void show() {
    std::cout << T() << std::endl << std::flush;
}

int main() {
    print<int>(1);
    print(5);
    print<>(42);
    print(.2);
    print<std::string>("Hello");
    print("World");

//    show();
//    show<>();
    show<double>();

    Test<std::string> t("Hello Template Class");
    print(t);

    Test<Bottle> bottleTest(Bottle(199));
    print(bottleTest);

    return 0;
}