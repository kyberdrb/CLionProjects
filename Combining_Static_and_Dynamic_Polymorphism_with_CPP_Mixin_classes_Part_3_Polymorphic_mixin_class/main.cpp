#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Combining Static and Dynamic Polymorphism with C++ Mixin classes - Part 3: https://michael-afanasiev.github.io/2016/08/03/Combining-Static-and-Dynamic-Polymorphism-with-C++-Template-Mixins.html

class Power {
public:
    std::string whatDoYouNeed() {
        return "I needed to see the power that I have when I catch mouses.";
    }
};

class Love {
public:
    std::string whatDoYouNeed() {
        return "I appretiate that you're showing me love when you're caring for me and feeding me and playing with me outside.";
    }
};

template <typename Need>
class Energetic : public Need {
public:
    std::string howDoYouFeel() {
        std::string feelingAndNeed{"I feel full of energy."};
        feelingAndNeed += " " + Need::whatDoYouNeed();
        return feelingAndNeed;
    }
};


template <typename Need>
class Safe : public Need {
public:
    std::string howDoYouFeel() {
        std::string feelingAndNeed{"I feel safe."};
        feelingAndNeed += " " + Need::whatDoYouNeed();
        return feelingAndNeed;
    }
};

class Animal {
public:
    virtual void vocalize() = 0;
    virtual ~Animal() = default;
};

template <typename NVC_Component>
class Cat : public Animal, public NVC_Component {
public:
    void vocalize() override {
        std::cout << "Meow." << " " << NVC_Component::howDoYouFeel() << std::endl;
    }
};

template <typename NVC_Component>
class Dog : public Animal, public NVC_Component {
public:
    void vocalize() override {
        std::cout << "Woof!" << " " << NVC_Component::howDoYouFeel() << std::endl;
    }
};

int main() {
    Cat<Energetic<Power>> cat;
    cat.vocalize();

    Dog<Safe<Love>> dog;
    dog.vocalize();

    std::cout << std::endl;

    std::vector<std::unique_ptr<Animal>> animals;
    animals.emplace_back(new Cat<Energetic<Power>>);
    animals.emplace_back(new Dog<Safe<Love>>);

    for (const auto& animal : animals) {
        animal->vocalize();
    }

    return 0;
}
