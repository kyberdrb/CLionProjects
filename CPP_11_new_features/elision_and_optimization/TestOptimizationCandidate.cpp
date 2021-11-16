//
// Created by laptop on 7/26/19.
//

#include <iostream>
#include <cstring>
#include "TestOptimizationCandidate.h"

TestOptimizationCandidate::TestOptimizationCandidate() {
    std::cout << "constructor" << std::endl;
    // The curly brackets in allocation zero-out the allocated memory
    _pBuffer = new int[SIZE]{};
}

TestOptimizationCandidate::TestOptimizationCandidate(int i) {
    std::cout << "parametrized constructor" << std::endl;
    _pBuffer = new int[SIZE]{};

    for (int i = 0; i < SIZE; i++) {
        _pBuffer[i] = 7 * i;
    }
}

TestOptimizationCandidate::TestOptimizationCandidate(std::string label) :
        TestOptimizationCandidate()
{
    this->label = label;
}

TestOptimizationCandidate::TestOptimizationCandidate(const TestOptimizationCandidate& other) {
    std::cout << "copy constructor" << std::endl;
    _pBuffer = new int[SIZE]{};
    memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
}

TestOptimizationCandidate& TestOptimizationCandidate::operator=(const TestOptimizationCandidate& other){
    std::cout << "copy assignment operator" << std::endl;
    _pBuffer = new int[SIZE]{};
    memcpy(_pBuffer, other._pBuffer, SIZE * sizeof(int));
    return *this;
}

TestOptimizationCandidate::TestOptimizationCandidate(TestOptimizationCandidate&& other) {
    std::cout << "move constructor" << std::endl;
    _pBuffer = other._pBuffer;

    // calling 'delete' over 'nullptr' is safe at object destruction
    // and DOES NOT produce undefined behaviour
    other._pBuffer = nullptr;
}

TestOptimizationCandidate& TestOptimizationCandidate::operator=(TestOptimizationCandidate&& other) {
    std::cout << "move assignment operator" << std::endl;

    // Delete everything dynamically allocated for this instance i.e.
    // repeat the deallocation stepps from destructor
    delete [] _pBuffer;

    // steal the resources
    this->_pBuffer = other._pBuffer;

    // clean the internals of the source object
    // and destroy the source object
    other._pBuffer = nullptr;

    return *this;
}

TestOptimizationCandidate::~TestOptimizationCandidate() {
    std::cout << "destructor" << std::endl;
    delete [] _pBuffer;
}

std::ostream& operator<<(std::ostream &os, const TestOptimizationCandidate&) {
    std::cout << "Hello from test";
    return os;
}
