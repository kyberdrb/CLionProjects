#include <iostream>

class Sensitivity_v1 {
public:
    double getValue() const;

    void setValue(double value);
};

class Sensitivity_v2 {
public:
    double getValue() const;

    void setValue(double value);

    void scale(double multiplicator) {
        setValue(getValue() * multiplicator);
    }

    void square() {
        setValue(getValue() * getValue());
    }

    void setToOpposite() {
        scale(-1);
    }
};

template <typename T>
class NumericalFunctions {
public:
    void scale(double multiplicator) {
        T& underlying = static_cast<T&>(*this);
        underlying.setValue(underlying.getSensitivity() * multiplicator);
    }

    void square() {
        T& underlying = static_cast<T&>(*this);
        underlying.setValue(underlying.getValue() * underlying.getValue());
    }

    void setToOpposite() {
        T& underlying = static_cast<T&>(*this);
        underlying.scale(-1);
    }
};

class Sensitivity_v3 : public NumericalFunctions<Sensitivity_v3> {
public:
    double getValue() const;

    void setValue(double value);
};

template <typename T>
void scale(T& object, double multiplicator) {
    object.setValue(object.getValue() * multiplicator);
}

template <typename T>
void square(T& object) {
    object.setValue(object.getValue() * object.getValue());
}

template <typename T>
void setToOpposite(T& object) {
    object.scale(-1);
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    return 0;
}
