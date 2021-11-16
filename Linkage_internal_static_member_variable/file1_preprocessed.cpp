# 1 "file1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "file1.cpp"
# 1 "file1.h" 1
       

int function1();
# 2 "file1.cpp" 2
# 1 "header.h" 1
       

struct Foo {
    static int staticVariableInitializedOutsideClassOutsideHeader;





    static int staticVariableInitializedOutsideClassInsideHeader;


    static int staticVariableInitializedOutsideClassOutsideHeaderInsideSource;
    const static int constStaticVariableInitInClass = 911;





    constexpr static float constexprNonintegralStaticVariableInitInClass = 10.01;

    static void function3();
};
# 3 "file1.cpp" 2

int function1() {
    Foo::staticVariableInitializedOutsideClassOutsideHeader = 123;
    Foo::staticVariableInitializedOutsideClassOutsideHeaderInsideSource = 512;
    return Foo::staticVariableInitializedOutsideClassOutsideHeader;
}
