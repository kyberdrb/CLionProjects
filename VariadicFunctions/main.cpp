#include <iostream>
#include <string>

// https://stackoverflow.com/questions/12515616/expression-contains-unexpanded-parameter-packs
// https://kevinushey.github.io/blog/2016/01/27/introduction-to-c++-variadic-templates/

template <typename T>
void print(T t) {
    std::cout << t << std::endl;
}

template <typename T, typename ...Args>
void print(T t, Args&&... args) {
    print(t);
    print(args...);
}

class Something {
    std::string greeting;
public:
    Something(std::string greeting) : greeting(greeting) {}

    friend std::ostream& operator<<(std::ostream& out, const Something& something);
};

std::ostream& operator<<(std::ostream& out, const Something& something) {
    out << something.greeting;
    return out;
}

class DistortedSomething {
    std::string& distortedGreeting;
public:
    DistortedSomething(std::string distortedGreeting) : distortedGreeting(distortedGreeting) {}

    friend std::ostream& operator<<(std::ostream& out, const DistortedSomething& distortedSomething);
};

std::ostream& operator<<(std::ostream& out, const  DistortedSomething& something) {
    out << something.distortedGreeting;
    return out;
}

int main() {
    print(1.23, "foo", 246, 'd', Something("I am something"));

    Something s{"What will happen?"};
    std::cout << s << std::endl;

    std::cout << std::endl;

    DistortedSomething distortedSomething("Referencing a temporary variable");
    std::cout << distortedSomething << std::endl;

    return 0;
}
