#include <string>

#define noop static_cast<void>(0)

// The Cherno: Implicit Conversion and the Explicit Keyword in C++ [0:00 - 4:47] - https://www.youtube.com/watch?v=Rr1NX1lH3oE

class Entity {
    std::string name;
    int age;

public:
    Entity(const std::string& name) : name(name), age(-1) {}
    Entity(int age) : name("Unknown"), age(age) {}
};

void explicit_conversion();
void implicit_conversion();
void print_entry(const Entity& entity);

int main() {
    explicit_conversion();
    implicit_conversion();

    return 0;
}

void explicit_conversion() {
    Entity a1("Cherno"); // one implicit conversion from const char[] to std::string
    Entity a2(std::string("Cherno"));
    Entity b(22);

    Entity aa1 = Entity("Chernoo");  // one implicit conversion from const char[] to std::string
    Entity aa2 = Entity(std::string{"Chernoo"});
    Entity bb = Entity(222);
}

void implicit_conversion() {
//    Entity aaa1 = "Chernooo";  // error: invalid conversion from 'const char*' to 'int'
                                    // for this to work we need to implicitly cast two times in a row:
                                    // 1.) the string literals are in C++ of type const char[] so the first conversion is from 'const char[]' to 'std::string'
                                    // 2.) to create an Entity instance from std::string, we need to use the Entitie's string
                                    //     constructor to convert from 'std::string' to 'Entity'
                                    // The problem is that C++ allows at most one implicit conversion at a time,
                                    // therefore this code fails to compile
    Entity aaa2 = std::string("Chernooo");
    Entity bbb = 2222;

    print_entry(322);
//    print_entry("The Cherno");    // error: invalid user-defined conversion from ‘const char [11]’ to ‘const Entity&
                                    // double implicit cast: const char[] -> std::string, then std::string -> Entity

    print_entry(std::string("The Cherno"));
    print_entry(Entity("The Chernoo"));
}

void print_entry(const Entity& entity) {
    // Printing...
    noop;
}