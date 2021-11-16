#include <iostream>
#include <memory>

void somethingSomething(int*& awesome) {
    std::cout << *awesome << std::endl;
}

int main() {
    int num = 3;
    int& var = num;
    int& bar = var;
    int& baz = bar;
    std::forward<int>(var);
    std::forward<int>(bar);
    std::cout << baz << std::endl;

    int* qux = &baz;

    somethingSomething(qux);

    return 0;
}