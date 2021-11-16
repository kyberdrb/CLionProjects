#include <iostream>

// Introduction to C++ Variadic Templates: https://kevinushey.github.io/blog/2016/01/27/introduction-to-c++-variadic-templates/

template <typename... Ts>
void ignore(Ts... ts) {}

template <typename... Ts>
double sumWithIteration(Ts... ts) {
    double result{0};
    //for (auto element : ts) {   // compiler doesn't allow us to iterate through the parameter pack...
    //    result += element;
    //}
    return result;
}

// the base case - stops the recursion
template <typename T>
double sum(T t) {
    return t;
}

// the recursive case - keeps expanding the parameter pack
template <typename T, typename... Rest>
double sum(T t, Rest... rest) {
    return t + sum(rest...);
}

template <typename T>
double square(T t) {
    return t * t;
}

template <typename T>
double power_sum(T t) {
    return square(t);
}

template <typename T, typename... Rest>
double power_sum(T t, Rest... rest) {
    return t + power_sum(square(rest)...);
}

template <typename T>
double sum_squares(T t) {
    return t * t;
}

template <typename T, typename... Rest>
double sum_squares(T t, Rest... rest) {
    return sum_squares(t) + sum_squares(rest...);
}

int main() {
    ignore(1, 2.0, true);
    auto zwischenErgebnis = sumWithIteration(1.1, 2.2, 3, 4);
    auto summe = sum(1, 3.4, 5, 6);
    auto etwas = power_sum(2, 3, 4);
    auto quadratensumme = sum_squares(2, 3, 4);
    return 0;
}
