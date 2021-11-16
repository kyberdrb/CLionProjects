#include <iostream>

#include "widget_old.h"
#include "widget.h"

// https://herbsutter.com/gotw/_101/

int main() {
    widget_old w_old;
    w_old.foo();

    widget w;   // build fails on this line:
                // undefined reference to `pimpl<widget::impl>::pimpl()'
                // and
                // undefined reference to `pimpl<widget::impl>::~pimpl()'
                // even though I defined them in "pimpl_impl.h"
    w.bar();

    return 0;
}