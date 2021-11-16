//
// Created by laptop on 7/21/19.
//

#include <iostream>
#include "ComplexNumber.h"
#include "ComplexNumberExercise.h"

namespace complex {

    ComplexNumber::ComplexNumber(
            double real, double imaginary)
            :
            real(real), imaginary(imaginary) {}

    std::ostream& operator<<(std::ostream &os, const ComplexNumber &cnum) {
        os << cnum.getReal() << " + " << cnum.getImaginary() << "i";
        return os;
    }

    ComplexNumber operator+(const ComplexNumber& cnum1, const ComplexNumber& cnum2) {
        double sumReal = cnum1.getReal() + cnum2.getReal();
        double sumImaginary = cnum1.getImaginary() + cnum2.getImaginary();
        return ComplexNumber(sumReal, sumImaginary);
    }

    ComplexNumber operator+(const ComplexNumber& cnum, double decimal) {
        return ComplexNumber(cnum.getReal() + decimal, cnum.getImaginary());
    }

    ComplexNumber operator+(double decimal, const ComplexNumber& cnum) {
        return ComplexNumber(cnum.getReal() + decimal, cnum.getImaginary());
    }

    bool operator==(const ComplexNumber& cnum1, const ComplexNumber& cnum2) {
        bool realEqual = cnum1.getReal() == cnum2.getReal();
        bool imaginaryEqual = cnum1.getImaginary() == cnum2.getImaginary();
        return realEqual && imaginaryEqual;
    }

    bool operator!=(const ComplexNumber& cnum1, const ComplexNumber& cnum2) {
    //    bool realDifferent = cnum1.getReal() != cnum2.getReal();
    //    bool imaginaryDifferent = cnum1.getImaginary() != cnum2.getImaginary();
    //    return realDifferent && imaginaryDifferent;
        return !operator==(cnum1, cnum2);
    }

    ComplexNumber::ComplexNumber(const ComplexNumber &otherCnum) {
        std::cout << "Copying via copy ctor" << std::endl;
        this->real = otherCnum.real;
        this->imaginary = otherCnum.imaginary;
    }

    ComplexNumber& ComplexNumber::operator=(const ComplexNumber &otherCnum) {
        std::cout << "Copying via assignment operator '='" << std::endl;
        this->real = otherCnum.real;
        this->imaginary = otherCnum.imaginary;
        return *this;
    }

    double ComplexNumber::getReal() const {
        return real;
    }

    double ComplexNumber::getImaginary() const {
        return imaginary;
    }

    ComplexNumber ComplexNumber::operator*() const {
        return ComplexNumber(this->getReal(), -(this->getImaginary()));
    }

}

