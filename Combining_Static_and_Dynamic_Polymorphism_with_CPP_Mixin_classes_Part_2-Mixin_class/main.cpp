#include <iostream>
#include <string>

// Combining Static and Dynamic Polymorphism with C++ Mixin classes - Part 2: https://michael-afanasiev.github.io/2016/08/03/Combining-Static-and-Dynamic-Polymorphism-with-C++-Template-Mixins.html

class Food {
public:
    std::string whatDoYouNeed() {
        return "I would like to eat something...";
    }
};

class Affection {
public:
    std::string whatDoYouNeed() {
        return "I would like some tenderness and closeness.";
    }
};

template <typename Need>
class Hunger : public Need {
public:
    std::string howDoYouFeel() {
        std::string feelingAndNeed;
        feelingAndNeed += "I'm hungry :(";
        feelingAndNeed += " " + Need::whatDoYouNeed();
        return feelingAndNeed;
    }
};

template <typename Need>
class Happiness : public Need {
public:
    std::string howDoYouFeel() {
        std::string feelingAndNeed{"I'm glad that you care for me :)"};
        feelingAndNeed += " " + this->whatDoYouNeed();
        return feelingAndNeed;
    }
};

template <typename Feeling>
class Cat : public Feeling {
public:
    void vocalize() {
        std::cout << "Meow." << " " << Feeling::howDoYouFeel() << std::endl;
    }
};

template <typename Feeling>
class Dog : public Feeling {
public:
    void vocalize() {
        std::cout << "Woof!" << " " << this->howDoYouFeel() << std::endl;
    }
};

int main() {
    Cat<Happiness<Affection>> cat;
    cat.vocalize();

    Dog<Hunger<Food>> dog;
    dog.vocalize();

    return 0;
}
