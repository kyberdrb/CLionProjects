#pragma once

#include <vector>
#include <memory>

// Forward declarations speed up compile times.
// To speed up compilation times, we can use Interface Segregation Principle.

// Prefer forward declaring a class to including a header file with that class wherever possible.

// When you include a header file you introduce a dependency that will cause your code to be recompiled whenever the header file changes.
// If your header file includes other header files, any change to those files will cause any code that includes your header to be recompiled.

// So, normally you forward declare in the Header file
// and #include in the .cpp file where you will use the members of the forward declared class.

// Forward declared class will only produce a compile error if you attempt to call any methods on a forward declared class.

class Forward;  // forward declared type is an incomplete type for the class in which the type is forward declared
                // Compilation succeeds even when the 'Forward.h' is not present in the build.

class Master {
private:
    // Declare a member to be a pointer or a reference to the incomplete type
    Forward* attributeByPointer;
    Forward& attributeByReference;

    // Use incomplete type as a template argument
    std::unique_ptr<Forward> uniquePtr;

    // Declare a member to be a container of poiners or values of incomplete type
    std::vector<Forward> containerOfValues;
    std::vector<Forward*> containerOfValuesPointers;

public:
    // Declare functions or methods which accepts/return incomplete types by values/pointers/references
    // but without using its members:
    void parameterByValue(Forward forward);
    Forward returnByValue();

    void parameterByPointer(Forward* forward);
    Forward* returnByPointer();

    void parameterByReference(Forward& forward);
    Forward& returnByReference();

    void declaredAcceptByPointer(Forward* forward) {}
    Forward* declaredReturnByPointer() {}

    void declaredAcceptByReference(Forward& forward) {}
    Forward& declaredReturnByReference() {}
};