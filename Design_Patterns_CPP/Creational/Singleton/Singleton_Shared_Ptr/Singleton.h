#pragma once

#include <memory>
#include <iostream>

class Singleton {
    Singleton() = default;

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton& getInstance();

    std::string use();

    ~Singleton() {
        std::cout << "Object destroyed" << std::endl;
    }
};
