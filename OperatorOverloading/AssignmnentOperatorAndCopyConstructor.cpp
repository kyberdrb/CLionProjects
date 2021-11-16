//
// Created by laptop on 7/21/19.
//

#include "AssignmnentOperatorAndCopyConstructor.h"
#include "Test.h"

void AssignmnentOperatorAndCopyConstructor::exerciseAssignmentOperator() {
    Test test1(10, "Mike");
    test1.print();

    std::cout << std::endl << std::flush;
    Test test2(20, "Bob");
    // Calls assignment operator '='
    test2 = test1;
    test2.print();

    Test test3;
    // Method chaining
//    test3 = test2 = test1;

    std::cout << std::endl << std::flush;
    test3.operator=(test2);
    test3.print();
}

void AssignmnentOperatorAndCopyConstructor::exerciseCopyConstructor() {
    std::cout << std::endl << std::flush;

    Test test1(10, "Mike");
    // Calls copy constructor
    Test test4 = test1;
    test4.print();

}
