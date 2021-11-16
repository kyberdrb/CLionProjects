# 1 "file2.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "file2.cpp"
# 1 "file2.h" 1
       

int function2();
# 2 "file2.cpp" 2
# 1 "header.h" 1
       

struct Foo {
    static int staticVariableInitializedOutsideClassOutsideHeader;





    static int staticVariableInitializedOutsideClassInsideHeader;


    static int staticVariableInitializedOutsideClassOutsideHeaderInsideSource;
    const static int constStaticVariableInitInClass = 911;





    constexpr static float constexprNonintegralStaticVariableInitInClass = 10.01;

    static void function3();
};
# 3 "file2.cpp" 2

int function2() {
    Foo::staticVariableInitializedOutsideClassOutsideHeader = 10;
    Foo::staticVariableInitializedOutsideClassOutsideHeaderInsideSource = 1024;
    return Foo::staticVariableInitializedOutsideClassOutsideHeader;
}
