//
// Created by laptop on 7/26/19.
//

#ifndef CPP_11_NEW_FEATURES_TESTOPTIMIZATIONCANDIDATE_H
#define CPP_11_NEW_FEATURES_TESTOPTIMIZATIONCANDIDATE_H


#include <ostream>

class TestOptimizationCandidate {
private:
    static const int SIZE = 100;
    int* _pBuffer {nullptr};
    std::string label;

public:
    TestOptimizationCandidate();
    explicit TestOptimizationCandidate(int i);
    explicit TestOptimizationCandidate(std::string label);
    TestOptimizationCandidate(const TestOptimizationCandidate&);
    TestOptimizationCandidate(TestOptimizationCandidate&&);
    TestOptimizationCandidate& operator=(const TestOptimizationCandidate&);
    TestOptimizationCandidate& operator=(TestOptimizationCandidate&&);
    virtual ~TestOptimizationCandidate();
    friend std::ostream &operator<<(std::ostream &os, const TestOptimizationCandidate& test);
};

#endif CPP_11_NEW_FEATURES_TESTOPTIMIZATIONCANDIDATE_H
