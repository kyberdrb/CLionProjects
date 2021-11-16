#include <iostream>

template <typename T>
class crtp {
public:
    T& underlying() {
        return static_cast<T&>(*this);  // error when calling a method in a base class of the Sensitivity class
    }

    T const& underlying() const {
        return static_cast<T const&>(*this);
    }
};

template <typename T>
class Scale : public crtp<T>{
public:
    void scale(double multiplicator) {
        this->underlying().setValue(this->underlying().getValue() * multiplicator);
    }
};

template <typename T>
class Square : public crtp<T> {
public:
    void square() {
        this->underlying().setValue(this->underlying.getValue() * this->underlying.getValue());
    }
};

class Sensitivity : public Scale<Sensitivity>, public Square<Sensitivity> {
//class Sensitivity : virtual public Scale<Sensitivity>, virtual public Square<Sensitivity> { // even virtual inheritance doesn't help when calling a method from the base clsses
    int value{};

public:
    double getValue() const {
        return value;
    }

    void setValue(double value) {
        this->value = value;
    }
};

int main() {
    Sensitivity s;
    s.getValue();
    s.setValue(5);
    //s.scale(3); // error: ‘crtp<Sensitivity>’ is an ambiguous base of ‘Sensitivity’
    //s.square(); // error: ‘crtp<Sensitivity>’ is an ambiguous base of ‘Sensitivity’ - there is no easy solution, even virtual inheritance for Sensitivity base classes doesn't help
    //s.underlying(); // totally confused with this; even here the virtual inheritance isn't effective
    return 0;
}
