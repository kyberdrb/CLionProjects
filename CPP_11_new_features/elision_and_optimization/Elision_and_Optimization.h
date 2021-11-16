//
// Created by laptop on 7/26/19.
//

#ifndef CPP_11_NEW_FEATURES_ELISION_AND_OPTIMIZATION_H
#define CPP_11_NEW_FEATURES_ELISION_AND_OPTIMIZATION_H


#include "TestOptimizationCandidate.h"

class Elision_and_Optimization {
public:
    void exercise();

private:
    void check(const TestOptimizationCandidate&);
    void check(TestOptimizationCandidate&&);
    void workWithLvalue(int&);
    void workWithRvalue(int&&);
};


#endif //CPP_11_NEW_FEATURES_ELISION_AND_OPTIMIZATION_H
