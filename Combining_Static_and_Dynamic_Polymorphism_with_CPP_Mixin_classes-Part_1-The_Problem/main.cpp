#include <iostream>
#include <vector>
#include <memory>

// Combining Static and Dynamic Polymorphism with C++ Mixin classes - Part 1: https://michael-afanasiev.github.io/2016/08/03/Combining-Static-and-Dynamic-Polymorphism-with-C++-Template-Mixins.html

class Animal {
public:
    virtual void vocalize() = 0;
};

class Dog : public Animal{
public:
    void vocalize() override {
        std::cout << "Woof" << std::endl;
    }
};

class Cat : public Animal {
public:
    void vocalize() override {
        std::cout << "Meow" << std::endl;
    }
};

int main() {
    std::vector<std::unique_ptr<Animal>> animals;
    animals.emplace_back(new Dog());
    animals.emplace_back(new Cat());

    for (const auto& animal : animals) {
        animal->vocalize();
    }
    return 0;
}
