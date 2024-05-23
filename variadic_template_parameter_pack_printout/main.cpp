#include <cstdint>
#include <iostream>
#include <sstream>

template <typename T> std::string type_name();

template<typename FirstParameter, typename... VariadicParameters>
void start(FirstParameter firstParameter, VariadicParameters&&... args) {
    std::cout << "Value of first template parameter: ";
    std::cout << " [" << std::forward<FirstParameter>(firstParameter) << " : (" << typeid(firstParameter).name() << ")]";

    std::cout << "\n" << std::endl;

    std::cout << "Value of variadic template parameters via folding expression - since C++17:       ";
    ((std::cout << '[' << args << " : (" << typeid(args).name() << ")]; "), ...);

    std::cout << std::endl;

    std::cout << "Value of variadic template parameters via parameter pack expansion - up to C++14:";
    std::stringstream out;
    using expander = int[];
    (void)expander{0, (void(out << " [" << std::forward<VariadicParameters>(args) << " : (" << typeid(args).name() << ")];"), 0)...};
    std::cout << out.str();
}

int main() {
    start(1, "asdf", static_cast<int32_t>(2), "ghjkl");
    std::cout << std::endl;
    return 0;
}
