- Comparison of base class types in Java and C++:
    - public class = class
    - public abstract class = class with at least one virtual function
    - interface = pure abstract class (a class class with only pure virtual functions. C++ way of making interfaces. May contain a default pure virtual destructor: `virtual ~PureVirtualClass() = default;`)
- **abstract** method and pure **virtual** functions
    - Java: `public abstract foo();`
    - C++: `virtual void foo() = 0;`
- Inheritance and Polymorphism in C++ and Java
    - C++: `class DerivedClass : public BaseClass`
    - Java:
        - `public class DerivedClass extends BaseClass`
        - `public class DerivedClass implements IClass`

- Abstract classes and pure virtual functions
    - https://www.geeksforgeeks.org/pure-virtual-functions-and-abstract-classes/

- (Pure) virtual destructor
    - https://stackoverflow.com/questions/461203/when-to-use-virtual-destructors/461224#461224
    - https://www.geeksforgeeks.org/pure-virtual-destructor-c/
    - https://www.studytonight.com/cpp/virtual-destructors.php
    - https://isocpp.org/wiki/faq/virtual-functions#virtual-dtors

- When the destructor doesn't need to be virtual...
    - https://stackoverflow.com/questions/57275522/virtual-destructor-for-pure-abstract-class/57275661#57275661

- Multiple Inheritance
    - Advanced C++: Multiple Inheritance - Devil or Angel: https://www.youtube.com/watch?v=7APovvvftQs

- Destructors and multiple inheritance
    - https://isocpp.org/wiki/faq/multiple-inheritance#mi-vi-dtor-order

- The 'Diamond Problem' / 'Dreaded Diamond'
    - https://isocpp.org/wiki/faq/multiple-inheritance#mi-diamond

- `#pragma once` Preprocessor directive
    - https://en.wikipedia.org/wiki/Pragma_once

- Exceptions
    - Exceptions enable us to decouple the occurence of a fail state from the handling of the failure.
    - Learn Advanced C++ Programming: https://www.youtube.com/playlist?list=PLw_k9CF7hBpJKHeOFXOHOyy_KuR06aLqt
        - Videos `002` bis `005`
    - Hierarchy of exceptions in C++
        - https://flylib.com/books/en/2.253.1/standard_library_exception_hierarchy.html
    - C++ Exceptions: 
        - https://www.geeksforgeeks.org/comparison-of-exception-handling-in-c-and-java/
    - Checked and Unchecked Exceptions:
        - http://tutorials.jenkov.com/java-exception-handling/checked-or-unchecked-exceptions.html
    - Exception safety
        - https://stackoverflow.com/questions/24150472/c-avoiding-memory-leak-with-exceptions
        - https://vorbrodt.blog/2019/04/03/initialization-list-exceptions-and-raw-pointers/
        - https://herbsutter.com/gotw/_102/

- C++ mapping to UML
    - https://cppcodetips.wordpress.com/2013/12/23/uml-class-diagram-explained-with-c-samples/
    - https://docs.nomagic.com/pages/viewpage.action?pageId=38044261