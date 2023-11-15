# Adapter Design Pattern

_Adapter / Converter / Wrapper / Compatibility Layer / Impostor_

Reference implementation of an Adapter design pattern

- implementation of an Adapter as an **Object Adapter** - **_run-time Adapter_**
- run-time reusability: reassignable Adaptee instance via `std::reference_wrapper`
- adapter implemented with an Interface: a class with only pure `virtual` function and single inheritance

## Sources

- Design
    - https://refactoring.guru/design-patterns/adapter
    - https://devtut.github.io/cpp/design-pattern-implementation-in-c.html#adapter-pattern

- UML
    - Abstract and Static: https://plantuml.com/class-diagram#9fd9d25be2fbb118
    - https://duckduckgo.com/?t=ffab&q=class+which+has+only+pure+virtual+functions+c%2B%2B&ia=web
    - C++ class with only pure virtual functions: what's that called?: https://softwareengineering.stackexchange.com/questions/206663/c-class-with-only-pure-virtual-functions-whats-that-called#comment410912_209114
    - https://plantuml.com/sequence-diagram

- Implementation
    - https://duckduckgo.com/?t=ffab&q=sqrt+c%2B%2B&ia=web
    - https://www.programiz.com/cpp-programming/library-function/cmath/sqrt
    - https://duckduckgo.com/?t=ffab&q=std%3A%3Areference_wrapper+reassign&ia=web
    - https://stackoverflow.com/questions/15463721/assign-a-value-to-a-stdreference-wrapper
