#include <iostream>

template <typename Derived>
class Comparisons {};

template <typename Derived>
bool operator==(const Comparisons<Derived>& o1, const Comparisons<Derived>& o2) {
    const Derived& d1 = static_cast<const Derived&>(o1);
    const Derived& d2 = static_cast<const Derived&>(o2);

    return !(d1 < d2) && !(d2 < d1);
}

template <typename Derived>
bool operator!=(const Comparisons<Derived>& o1, const Comparisons<Derived>& o2) {
    return !(o1 == o2);
}

class Person : public Comparisons<Person> {
    std::string name;
    unsigned int age;

public:
    Person(std::string name, unsigned int age) :
        name(name), age(age) {}

    friend bool operator<(const Person& p1, const Person& p2);
};

bool operator<(const Person& p1, const Person& p2) {
    return p1.age < p2.age;
}

int main() {
    Person p1("Andrej", 25);
    Person p2("Andrew", 36);

    std::cout << (p1 == p2) << std::endl;
    std::cout << (p1 != p2) << std::endl;
    std::cout << (p1 < p2) << std::endl;
    std::cout << true << std::endl;
    std::cout << false << std::endl;

    return 0;
}
