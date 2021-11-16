#pragma once
#include <cstdint>

namespace Global {
    extern uint32_t clock_rate;

//    void foo() {                        // linker error: multiple definition of `Global::foo()'
//        static_cast<void*>(nullptr);    // each include of this header in other files expands this defined function
//    }                                   // in each file this header is included.
//                                        // and because the default linkage for global function, even in a custom namespace,
//                                        // is extern, the linker will see multiple definition of this function in
//                                        // multiple places, i.e. multiple translation units,
//                                        // which violates the ODR - One Definition Rule.
}
