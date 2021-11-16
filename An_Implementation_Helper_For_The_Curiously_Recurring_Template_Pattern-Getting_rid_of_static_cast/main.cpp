#include <iostream>

template <typename T>
class NumericalFunctions_v1 {
public:
    void scale(double multiplicator) {
        T& underlying = static_cast<T&>(*this);
        underlying.setValue(underlying.getValue() * multiplicator);
    }
};

class Sensitivity_v1 : public NumericalFunctions_v1<Sensitivity_v1> {
    double value;

public:
    explicit Sensitivity_v1(double value) : value(value) {}

    double getValue() const {
        return value;
    }

    void setValue(double value) {
        this->value = value;
    }
};

template <typename T>
class crtp {
public:
    T& underlying() {
        return static_cast<T&>(*this);
    }

    T const& underlying() const {
        return static_cast<T const&>(*this);
    }
};

template <typename T>
class NumericalFunctions_v2 : public crtp<T>{
public:
    void scale(double multiplicator) {
        this->underlying().setValue(this->underlying().getValue() * multiplicator);
    }
};

class Sensitivity_v2 : public NumericalFunctions_v2<Sensitivity_v2> {
    double value;

public:
    Sensitivity_v2(double value) : value(value) {}

    double getValue() const {
        return value;
    }

    void setValue(double value) {
        this->value = value;
    }
};

int main() {
    Sensitivity_v1 s1(2.6);
    std::cout << s1.getValue() << std::endl;
    s1.scale(5.5);
    std::cout << s1.getValue() << std::endl;

    std::cout << std::endl;

    Sensitivity_v2 s2{3.4};
    std::cout << s2.getValue() << std::endl;
    s2.scale(2.5);
    std::cout << s2.getValue() << std::endl;
    return 0;
}
