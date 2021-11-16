//
// Created by laptop on 7/21/19.
//

#include <iostream>
#include "ComplexNumberExercise.h"
#include "ComplexNumber.h"

void ComplexNumberExercise::complexNumberExercise() {
    complex::ComplexNumber cnum(2.3, 5.4);
    std::cout << cnum << std::endl << std::flush;

    std::cout << std::endl << std::flush;
    complex::ComplexNumber cnumCopy = cnum;
    std::cout << cnumCopy << std::endl << std::flush;

    std::cout << std::endl << std::flush;
    complex::ComplexNumber cnum2(-3.6, -6.8);
    std::cout << cnum2 << std::endl << std::flush;

    std::cout << std::endl << std::flush;
    cnum = cnum2;
    std::cout << cnum << "; " << cnumCopy << "; " << cnum2 << std::endl << std::flush;

    std::cout << std::endl << std::flush;
    std::cout << cnum + cnumCopy << std::endl << std::flush;

    std::cout << std::endl << std::flush;
    std::cout << 0.5 + cnumCopy + 0.2 << std::endl << std::flush;

    std::cout << std::endl << std::flush;
    complex::ComplexNumber cnum3(3, 2);
    complex::ComplexNumber cnum4(3, 2);

    if (cnum3 == cnum4) {
        std::cout << "Equal" << std::endl;
    } else {
        std::cout << "Different" << std::endl;
    }

    if (cnum != cnum4) {
        std::cout << "Different" << std::endl;
    } else {
        std::cout << "Equal" << std::endl;
    }

    std::cout << std::endl << std::flush;
    complex::ComplexNumber cnum5(2.0, 5.0);
    std::cout << cnum5 << std::endl << std::flush;
    std::cout << *cnum5 << std::endl << std::flush;
    std::cout << (*cnum5 + *complex::ComplexNumber(4, 1)) << std::endl << std::flush;

}
