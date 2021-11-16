#ifndef TEMPLATES_TEST_H
#define TEMPLATES_TEST_H

#include <iostream>

template <typename T>
class Test {
public:
    Test(T obj) : obj(obj) {}

    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const Test<U>& test);

private:
    T obj;
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const Test<T>& test) {
    return out << test.obj << std::flush;
}
#endif //TEMPLATES_TEST_H
