//
// Created by laptop on 7/29/19.
//

#ifndef CPP_11_NEW_FEATURES_PERFECT_FORWARDING_H
#define CPP_11_NEW_FEATURES_PERFECT_FORWARDING_H

#include "Test.h"

class Perfect_Forwarding {
public:
    void exercise();

private:
    template <typename T>
    void call_and_convert(T&&);

    template <typename T>
    void call_and_preserve_with_static_cast(T&&);

    template <typename T>
    void call_and_preserve_with_forward(T&&);

    void check(const Test&);
    void check(Test&&);
};


#endif //CPP_11_NEW_FEATURES_PERFECT_FORWARDING_H
