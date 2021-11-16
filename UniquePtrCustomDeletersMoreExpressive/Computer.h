#pragma once

#include <string>

class Computer {
    std::string id;

public:
    Computer() : id(std::move("1234")) {}

    explicit Computer(std::string id) : id(std::move(id)) {}

    ~Computer() {
        std::cout << "Computer deleted:\t" << id << std::endl;
    }
};