#include <iostream>
#include <cassert>

template <typename T, template<typename> class crtpType>    // template parameter 'crtpType' is of type template<typename> class
                                                            // It is not a typename, it's an entire template class which has an optional template argument.
                                                            // The 'crtpType' serves only to distinguish types and perform inheritance check for derived classes whether they match.
                                                            // Because the template parameter in crtpType is optional and in this case unused
                                                            // it's called a 'phantom type' or 'phantom template'
class crtp {
    crtp() = default;
    friend crtpType<T>;

public:
    T& underlying() {
        return static_cast<T&>(*this);
    }

    T const& underlying() const {
        return static_cast<T const&>(*this);
    }
};

template <typename T>
class Scale : public crtp<T, Scale> {
public:
    void scale(double multiplicator) {
        this->underlying().setValue(this->underlying().getValue() * multiplicator);   // why do I have to use 'this'?
                                                                                            // see: https://stackoverflow.com/questions/4643074/why-do-i-have-to-access-template-base-class-members-through-the-this-pointer/4643295#4643295
    }
};

template <typename T>
class Square : public crtp<T, Square> {
public:
    using crtp<T, Square>::underlying;  // remove 'this' keyword from calling a method in the templated base class. source: https://stackoverflow.com/questions/4643074/why-do-i-have-to-access-template-base-class-members-through-the-this-pointer/4643091#4643091

    void square() {
        underlying().setValue(underlying().getValue() * this->underlying().getValue());
    }
};

class Sensitivity : public Scale<Sensitivity>, public Square<Sensitivity> {
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
    s.setValue(2);
    assert(s.getValue() == 2);

    s.scale(3);
    assert(s.getValue() == 6);

    s.square();
    assert(s.getValue() == 36);

    return 0;
}
