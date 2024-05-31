# Inheritance, Polymorphism, Virtual Destructors, Virtual/Override/Final functions, Unique Pointers and Memory Leaks

In this project are depicted scenarios of using virtual and nonvirtual functions in an inheritance class composition in base and derived classes.

In the first part of the `main()` function are examples of calling a virtual and nonvirtual function from a polymorfic object variable, i.e. an instance of the derived class is being assigned to a local variable of a base class type. The goal of the experiments was to find out, how polymorphism works with variously declared functions in the inheritance hierarchy.

In the second part are shown the behavior and consequences of having virtual and nonvirtual destructors in base and derived classes, and having dynamically allocated member variable in derived classes. The goal of the experiments was to find out, how polymorphism applies to variously declared destructors in base and derived classes.

All derived classes have a dynamically allocated internal state, i. e. have a member variable allocated on the heap. In case of raw pointer, if a destructor is defined, the variable is explicitly deallocated with `delete` keyword in the destructor. In case of `unique_ptr`, as for its deallocation, we are relying on the RAII mechanism to take place.

Below is a table showcasing the behavior of variously declared virtual and nonvirtual destructors in base and derived classes, together with consequences of each tested combination.

|                                                 | Base class with nonvirtual destructor | Base class with virtual destructor                                                          |
|-------------------------------------------------|--------------------------------------|---------------------------------------------------------------------------------------------|
| Derived with implicit destructor                | memory leak | memory leak                                                                                 |
| Derived with nonvirtual destructor              | memory leak | clean                                                                                       |
| Derived with `virtual` destructor               | memory leak | clean                                                                                       |
| Derived with `override` destructor              | N/A - Base destructor not virtual | clean                                                                                       |
| Derived with `final` destructor                 | N/A - Base destructor not virtual | clean                                                                                       |
| Derived with unique_ptr and implicit destructor | memory leak | \<test case skipped: assuming same result as in mentioned equivalent test case, i.e. clean> |
| Derived with unique_ptr and nonvirtual destructor | memory leak | \<test case skipped: assuming same result as in mentioned equivalent test case, i.e. clean>             |
| Derived with unique_ptr and `virtual` destructor | memory leak | \<test case skipped: assuming same result as in mentioned equivalent test case, i.e. clean>             |

## Evaluation

When the derived class has a dynamically allocated internal state, and it's being used in the client code in a polymorphic way, i. e. through a variable of a base class type, in order to completely deallocate the base and derived class with their internal state, we need to make the destructor of the base class `virtual` , and mark the destructor of the derived class as `virtual` , `override` (same as `virtual` , but recommended by the compiler as it's more descriptive for the virtual function usage in the derived class) or `final` (similar to `override` ; also marking the class as `final` to prohibit further inheriting from the derived class). Leaving the polymorphic function in the derived class as-is without marking it at all also produces polymorphic behavior, i. e. call to the function in the derived class, but at the same time produces a compiler warning to annotate the polymorphic function as `override` , when the function is defined in the base class as `virtual`. When mentioned scenario is applied to virtual member functions, the produced polymorphic behavior is then attained via combination of polymorphism and function declaration shadowing - function with the same name is defined in base and derived class.

Note: Commented lines of code are either describing the intent, or produce compiler errors or memory leaks.

## Sources

- https://duckduckgo.com/?t=ffab&q=c%2B%2B+virtual+override+final&ia=web
- https://www.fluentcpp.com/2020/02/21/virtual-final-and-override-in-cpp/
