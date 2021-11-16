#pragma once

#include <iostream>

struct Foo {
    static int staticVariableInitializedOutsideClassOutsideHeader;  // mixed external and internal linkage when initialized outside of the header
                                                                    // - external because the value is shared and each translation
                                                                    //   unit modifies the original value (unlike internal)
                                                                    // - internal because including the header file doesn't cause
                                                                    //   the linker to produce 'multiple definition' error (unlike external)
                                                                    //   multiple translation units
    static int staticVariableInitializedOutsideClassInsideHeader;   // external linkage - static member variable initialized outside class and inside of the header
                                                                    // externally linked variables cause linker errors
//    static int staticVariableInitializedInsideClassInsideHeader = 333;  // error: ISO C++ forbids in-class initialization of non-const static member
    static int staticVariableInitializedOutsideClassOutsideHeaderInsideSource;  // external linkage - static member variable initialized outside of the header
    const static int constStaticVariableInitInClass = 911 ;  // mixed external and internal linkage when initialized in-class?
                                                            // - external because the value is shared and each translation
                                                            //   unit modifies the original value (unlike internal)
                                                            // - internal because including the header file doesn't cause
                                                            //   the linker to produce 'multiple definition' error (unlike external)
                                                            //   multiple translation units
    constexpr static float constexprNonintegralStaticVariableInitInClass = 10.01;   // internal linkage

    static void function3();

    static void function4();    // do not call a function which has no definition

    static void function5() {
        static_cast<void*>(nullptr);
    }
};

//int Foo::staticVariableInitializedOutsideClassInsideHeader = 911;   // static member variable defined/initialized in the header file
                                                                    //  external linkage - causes linker error: multiple definition of `Foo::constStaticVariableInitInClass'
//const int Foo::constStaticVariableInitInClass = 911;

//void Foo::function4() { // linker error: multiple definition of `Foo::function4()'
//    static_cast<void*>(nullptr);
//}
