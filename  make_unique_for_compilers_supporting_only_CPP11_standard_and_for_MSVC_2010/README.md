# `std::make_unique()` support for C++11

For GCC (and possible Clang) compiler which support the features only up to C++11 standard, the **_variadic template_** implementation will most likely work.

For MSVC 2010 (or even 2012) and other compilers which don't support variadic templates, the **_fixed template_** implementation is available. There is also **_variadic template implementation via macro expansion_** implementation, which I haven't tested and is available at https://stackoverflow.com/questions/17902405/how-to-implement-make-unique-function-in-c11

## Sources

- https://duckduckgo.com/?q=add+unique_ptr+make_unique+to+c%2B%2B11&t=ffab&ia=web
- https://stackoverflow.com/questions/64054795/how-can-i-use-make-unique-with-c11
- https://en.cppreference.com/w/cpp/memory/unique_ptr/make_unique
- ChatGPT: How would you add std::unique_ptr and std::make_unique features into C++11 project?

    ```
    C++11 does not include `std::make_unique`, which was introduced in C++14. However, you can add these features to a C++11 project by implementing std::make_unique yourself and using `std::unique_ptr` which is already part of C++11. Here's how you can do it:

    . Include the `<memory>` Header:
        Make sure you include the `<memory>` header at the top of your source file.

    . Check Your C++ Standard:
        Ensure that your compiler is set to use at least the C++11 standard, as `std::unique_ptr` was introduced in C++11.
    ```

  You can implement a simple version of `std::make_unique` by creating a utility function:

- ChatGPT: My bad. I tested it again and I made a typo. I compiled it again with success. To my surprise the std::unique_ptr is indeed in the C++11 standard. But I had to rely on fixed templates, as variadic templates are not supported in MSVC 2010.

    ```
   Given that you are working with MSVC 2010, which does not fully support variadic templates, you can still implement a version of `std::make_unique` using fixed templates for a limited number of arguments. Below is an implementation that supports up to four arguments. You can extend this pattern as needed for more arguments.
    ```
- https://en.cppreference.com/w/cpp/language/parameter_pack
- https://duckduckgo.com/?t=ffab&q=std%3A%3Amake_unique+implementation&ia=web
- https://stackoverflow.com/questions/17902405/how-to-implement-make-unique-function-in-c11