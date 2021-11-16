//
// Created by laptop on 7/23/19.
//

#ifndef CPP_11_NEW_FEATURES_AUTO_H
#define CPP_11_NEW_FEATURES_AUTO_H


class Auto {
public:
    void exercise();

private:
    // declare a function with a trailing type;
    // useful for automatic type deduction via decltype()
    // especially with template functions
    auto test() -> int;

    template <typename T>
    auto templateTest(T value) -> decltype(value);

    template <typename T, typename S>
    auto templateAdd(T value1, S value2) -> decltype(value1 + value2);

    int get();
    auto testGet() -> decltype(get());

};


#endif //CPP_11_NEW_FEATURES_AUTO_H
