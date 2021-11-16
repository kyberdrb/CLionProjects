//
// Created by laptop on 7/21/19.
//

#ifndef OPERATOROVERLOADING_TEST_H
#define OPERATOROVERLOADING_TEST_H


#include <cstdint>
#include <string>
#include <utility>
#include <iostream>

class Test {
private:
    uint_fast32_t id;
    std::string name;

public:
    Test() : id(0), name("") {}

    Test(uint_fast32_t id, std::string name) : id(id), name(std::move(name)) {}

    void print() const;

    friend std::ostream& operator<<(std::ostream&, const Test&);

    // Rule of three/Dreiregel (C++):
    // ...  if a class defines one (or more) of the following
    // it should probably explicitly define all three:
    // - destructor,
    // - copy constructor
    // - copy assignment operator.

    ~Test() {}

    Test(const Test& otherTest);

    const Test& operator=(const Test& otherTest);

};



#endif //OPERATOROVERLOADING_TEST_H
