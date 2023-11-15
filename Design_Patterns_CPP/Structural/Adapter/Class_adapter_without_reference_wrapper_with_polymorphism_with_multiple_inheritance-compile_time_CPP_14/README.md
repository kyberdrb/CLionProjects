# Adapter Design Pattern

_Adapter / Converter / Wrapper / Compatibility Layer / Impostor_

Reference implementation of an Adapter design pattern

- implementation of an Adapter as a **Class Adapter** - **_compile-time Adapter_**
- compile-time usability only - not reassignable to another Adaptee instance: once assigned to a specific Adaptee instance, will be assigned to the Adapter until the end of the Adapter's lifetime
- with `virtual` function and multiple inheritance

## Sources

- Design
    - https://refactoring.guru/design-patterns/adapter
    - https://devtut.github.io/cpp/design-pattern-implementation-in-c.html#adapter-pattern

- Implementation
    - https://duckduckgo.com/?t=ffab&q=sqrt+c%2B%2B&ia=web
    - https://www.programiz.com/cpp-programming/library-function/cmath/sqrt
    - https://duckduckgo.com/?t=ffab&q=std%3A%3Areference_wrapper+reassign&ia=web
    - https://stackoverflow.com/questions/15463721/assign-a-value-to-a-stdreference-wrapper
    - https://www.geeksforgeeks.org/visibility-modes-in-c-with-examples/
