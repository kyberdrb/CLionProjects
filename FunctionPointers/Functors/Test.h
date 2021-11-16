//
// Created by laptop on 7/22/19.
//

#ifndef PASSINGFUNCTIONTOFUNCTION_TEST_H
#define PASSINGFUNCTIONTOFUNCTION_TEST_H

#include <string>

class Test {
public:
    virtual bool operator()(const std::string& text) = 0;
};

#endif //PASSINGFUNCTIONTOFUNCTION_TEST_H
