#include <iostream>

#include "widget.h"
#include "pimpl_impl.h"

class widget::impl {
public:
    void bar() {
        std::cout << "Hello Template Metaprogramming World" << std::endl;
    }
};

void widget::bar() {
    m->bar();
}