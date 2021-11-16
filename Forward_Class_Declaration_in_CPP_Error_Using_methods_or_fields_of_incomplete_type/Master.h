#pragma once

class Forward;

class Master {
private:
    // Use member functions or member variables of the incomplete type
    // In this situation we need to include the header with the class, instead of forward declaring the class.
    // Compilation fails even when the 'Forward.h' is not present in the build.

    Forward* variableByPointer;
    Forward& variableByReference;

public:
    void functionUsingPointer() {
        variableByPointer->someMethod();    // error: invalid use of incomplete type ‘class Forward’
        variableByPointer->someField;       // error: invalid use of incomplete type ‘class Forward’
    }

    void functionUsingReference() {
        variableByReference.someMethod();   // error: invalid use of incomplete type ‘class Forward’
        variableByPointer->someField;       // error: invalid use of incomplete type ‘class Forward’
    }
};
