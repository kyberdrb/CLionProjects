//
// Created by laptop on 7/22/19.
//

#ifndef PASSINGFUNCTIONTOFUNCTION_MATCHTEST_H
#define PASSINGFUNCTIONTOFUNCTION_MATCHTEST_H

#include <string>
#include "Test.h"

class MatchTest : public Test {
public:
    bool operator()(const std::string& text) override {
        return text == "lion";
    }
};

#endif //PASSINGFUNCTIONTOFUNCTION_MATCHTEST_H
