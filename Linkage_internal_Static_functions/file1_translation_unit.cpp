# 1 "file1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "file1.cpp"
# 1 "file1.h" 1
       






static int foo() {
    return 42;
}

int doSomething();
# 2 "file1.cpp" 2

int doSomething() {
    return foo() + 1;
}
