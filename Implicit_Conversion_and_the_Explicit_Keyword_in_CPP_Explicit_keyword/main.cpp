#include <string>

#define noop static_cast<void>(0)

// The Cherno: Implicit Conversion and the Explicit Keyword in C++ [4:47 - 6:58] - https://www.youtube.com/watch?v=Rr1NX1lH3oE

class Entity {
    std::string name;
    int age;

public:
    explicit Entity(const std::string& name) : name(name), age(-1) {}
    explicit Entity(int age) : name("Unknown"), age(age) {}
};

void print_entity(const Entity& entity) {
    noop;
}

int main() {
    Entity a1("Cherno");
    Entity a2(std::string("Cherno"));
    Entity b(22);

    Entity aa1 = Entity("Chernoo");
    Entity aa2 = Entity(std::string{"Chernoo"});
    Entity bb = Entity(222);

    // all implicit conversions stop working because we disabled them with the 'explicit' keyword in the constructors of the Entity class
    Entity aaa1 = "Chernooo";   // two implicit conversions - fails to compile because only one implicit conversion at a time is allowed in C++
    Entity aaa2 = std::string("Chernooo");  // implicit conversion - fails to compile because the respective converting constructor in Entity class is marked 'explicit'
    Entity bbb = 2222;  // implicit conversion - fails to compile because the respective converting constructor in Entity class is marked 'explicit'

    print_entity(322);  // implicit conversion - fails to compile because the respective converting constructor in Entity class is marked 'explicit'
    print_entity("The Cherno"); // two implicit conversions - fails to compile because only one implicit conversion at a time is allowed in C++
    print_entity(std::string("The Cherno"));    // implicit conversion - fails to compile because the respective converting constructor in Entity class is marked 'explicit'

    print_entity(Entity(322));
    print_entity(Entity("The Cherno"));

    return 0;
}