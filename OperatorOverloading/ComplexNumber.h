//
// Created by laptop on 7/21/19.
//

#ifndef OPERATOROVERLOADING_COMPLEXNUMBER_H
#define OPERATOROVERLOADING_COMPLEXNUMBER_H

#include <ostream>

namespace complex {

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber(double real, double imaginary);

    ComplexNumber(const ComplexNumber&);

    ComplexNumber& operator=(const ComplexNumber&);

    ComplexNumber operator*() const;

    double getReal() const;

    double getImaginary() const;
};

std::ostream &operator<<(std::ostream &os, const ComplexNumber &number);
ComplexNumber operator+(const ComplexNumber&, const ComplexNumber&);
ComplexNumber operator+(const ComplexNumber&, double);
ComplexNumber operator+(double decimal, const ComplexNumber& cnum);
bool operator==(const ComplexNumber&, const ComplexNumber&);
bool operator!=(const ComplexNumber&, const ComplexNumber&);

}

#endif //OPERATOROVERLOADING_COMPLEXNUMBER_H
