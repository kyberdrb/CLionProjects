#include <iostream>

#include "widget_old.h"

class widget_old::old_widget_impl {
public:
    void foo() {
        std::cout << "Hello World" << std::endl;
    }
};

widget_old::widget_old() : impl(new old_widget_impl) {}

widget_old::~widget_old() = default;

void widget_old::foo() {
    impl->foo();
}