#include <iostream>
#include <memory>
#include <typeinfo>

struct Bar {};

struct Foo {
    uint8_t uint8_t_variable;
    uint16_t uint16_t_variable;
    uint32_t uint32_t_variable;
    uint64_t uint64_t_variable;

    int8_t int8_t_variable;
    int16_t int16_t_variable;
    int32_t int32_t_variable;
    int64_t int64_t_variable;

    int int_variable;
    double double_variable;

    char* char_pointer;
    Bar* bar_pointer;
};

int main() {

    int initial_value_int{};
    for (int i = 0; i < 10000; ++i) {
        auto foo = std::make_unique<Foo>();
        auto current_value_int = foo->int_variable;
        if (current_value_int != initial_value_int) {
            std::cout << "member variable of type " << typeid(current_value_int).name() << " is initialized randomly" << std::endl;
            break;
        }
    }

    double initial_value_double{};
    for (int i = 0; i < 10000; ++i) {
        Foo foo;
        auto current_value_double = foo.double_variable;
        if (current_value_double != initial_value_double) {
            std::cout << "member variable of type " << typeid(current_value_double).name() << " for a stack allocated object is initialized randomly" << std::endl;
            break;
        }
    }

    initial_value_double = 0;
    for (int i = 0; i < 10000; ++i) {
        Foo* foo = new Foo;   // make_unique initializes all uninitialized variables, even pointers to NULL or nullptr
        auto current_value_double = foo->double_variable;
        if (current_value_double != initial_value_double) {
            std::cout << "member variable of type " << typeid(current_value_double).name() << " for a make_unique allocated object is initialized randomly" << std::endl;
            break;
        }
        delete foo;
    }

    initial_value_double = 0;
    for (int i = 0; i < 10000; ++i) {
        std::unique_ptr<Foo> foo = std::make_unique<Foo>();   // make_unique initializes all uninitialized variables, even pointers to NULL or nullptr
        auto current_value_double = foo->double_variable;
        if (current_value_double != initial_value_double) {
            std::cout << "member variable of type " << typeid(current_value_double).name() << " for a make_unique allocated object is initialized randomly" << std::endl;
            break;
        }
    }

    initial_value_double = 0;
    for (int i = 0; i < 10000; ++i) {
        std::unique_ptr<Foo> foo(new Foo);
        auto current_value_double = foo->double_variable;
        if (current_value_double != initial_value_double) {
            std::cout << "member variable of type " << typeid(current_value_double).name() << " for a unique_ptr object allocated with new is initialized randomly" << std::endl;
            break;
        }
    }

    return 0;
}
