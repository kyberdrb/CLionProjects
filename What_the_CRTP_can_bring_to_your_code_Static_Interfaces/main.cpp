#include <iostream>

template <typename T>
class Amount {
public:
    double getValue() const {
        return static_cast<const T&>(*this).getValue();
    }
};

class Constant42 : public Amount<Constant42> {
public:
    double getValue() const {
        return 42;
    }
};

class Variable : public Amount<Variable> {
    int value;
public:
    double getValue() const {
        return value;
    }

    explicit Variable(int value) : value(value) {}
};

class AmountPrinter {
public:
    template <typename T>
    static void print(Amount<T> const& amount) {
        std::cout << amount.getValue() << std::endl;
    }
};

int main() {
    Constant42 c42;
    AmountPrinter::print(c42);

    Variable v(43);
    AmountPrinter::print(v);

    return 0;
}
