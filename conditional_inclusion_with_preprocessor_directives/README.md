# Conditional Inclusion

a.k.a. passing macro from CMake into compiler into source code as macro

## Guide

1. [OPTIONAL] Switch to the dir with the repo.

1. Generate `CMake` makefiles passing the macro name `OUTSIDE_CMAKE_VARIABLE` with `-D` option

```cmake
/usr/bin/cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PROGRAM=/usr/bin/ninja -DCMAKE_C_COMPILER=/usr/bin/gcc -DCMAKE_CXX_COMPILER=/usr/bin/g++ -DOUTSIDE_CMAKE_VARIABLE=EXAMPLE_VALUE -G Ninja -S /home/laptop/CLionProjects/conditional_inclusion_with_preprocessor_directives -B /home/laptop/CLionProjects/conditional_inclusion_with_preprocessor_directives/cmake-build-debug
```

1. Clean the target binaries

```cmake
/usr/bin/cmake --build /home/laptop/CLionProjects/conditional_inclusion_with_preprocessor_directives/cmake-build-debug --target clean -j 1
```

Compile the project

```cmake
/usr/bin/cmake --build /home/laptop/CLionProjects/conditional_inclusion_with_preprocessor_directives/cmake-build-debug --target conditional_inclusion_with_preprocessor_directives -j $(nproc)
```

Run the target binary

```shell
/home/laptop/CLionProjects/conditional_inclusion_with_preprocessor_directives/./cmake-build-debug/conditional_inclusion_with_preprocessor_directives
```

## Sources

- https://duckduckgo.com/?t=ffab&q=c%2B%2B+ifdef&ia=web
- https://stackoverflow.com/questions/33117233/what-does-purpose-use-ifdef-and-if-in-c#33117658
- https://en.cppreference.com/w/cpp/preprocessor/conditional
- https://duckduckgo.com/?t=ffab&q=ifdef+gcc+-D&ia=web
- https://duckduckgo.com/?t=ffab&q=c%2B%2B+preprocessor+only+debug+build&ia=web
- https://stackoverflow.com/questions/31402179/how-to-make-some-code-run-only-in-debug-build-target
- https://duckduckgo.com/?t=ffab&q=c%2B%2B+debug+output+wrap+ifdef&ia=web
- https://stackoverflow.com/questions/29260027/ifdef-debug-in-main-function
- https://duckduckgo.com/?t=ffab&q=ifdef+doesn%27t+work&ia=web&iax=qa
- https://duckduckgo.com/?t=ffab&q=cmake+dndebug&ia=web&iax=qa
- https://duckduckgo.com/?t=ffab&q=cmake+pass+vairable+into+code&ia=web
- https://stackoverflow.com/questions/22259279/passing-a-cmake-variable-to-c-source-code
- https://stackoverflow.com/questions/34302265/does-cmake-build-type-release-imply-dndebug#34314956
- https://duckduckgo.com/?t=ffab&q=pass+cmake+variables+to+source+code&ia=web&iax=qa
- https://duckduckgo.com/?q=cmake+%22-D%22&t=ffab&ia=web
- https://discourse.cmake.org/t/cmake-command-line-d-and-using-defined/2264/2
