- `std::vector`
    - C++ equivalent of an `ArrayList` in Java
    - `ArrayList` vs `std::vector` method names
        - add: push_back / emplace_back / insert
        - remove: erase
        - get: at / `operator[]`
        - isEmpty: empty
        - size: size
- `std::list`
    - C++ equivalent of an LinkedList in Java
- `std::unique_ptr`
    - type of **Smart Pointers are a part of C++ for automatic memory management (since C++11)**. Smart pointers are equivalent to _Garbage Collector_ in Java.
    - `unique_ptr` cannot be copied. Instead of copying the pointer, we move it via `std::move`.
    - Learn Advanced C++ Programming: https://www.youtube.com/playlist?list=PLw_k9CF7hBpJKHeOFXOHOyy_KuR06aLqt
    - `shared_ptr` - smart pointer that can be shared among multiple instances
        - Videos `067`, `068`
- C++ Move Semantics
    - feature of the language since C++11
    - Learn Advanced C++ Programming: https://www.youtube.com/playlist?list=PLw_k9CF7hBpJKHeOFXOHOyy_KuR06aLqt
        - Videos `060`, `061`
- **Exercises**
    - Triangles
        - add an attribute `name` to the class `Triangle`
        - use the `name` in the _stream insertion operator_ `<<` to print out the `name` of the triangle instead of the general _triangle_ name.
    - Templates / Template Metaprogramming
        - class and function templates
        - programm a `Ring Buffer` data structure
            - Learn Advanced C++ Programming: https://www.youtube.com/playlist?list=PLw_k9CF7hBpJKHeOFXOHOyy_KuR06aLqt
                - RingBuffer: Videos `029` - `032`