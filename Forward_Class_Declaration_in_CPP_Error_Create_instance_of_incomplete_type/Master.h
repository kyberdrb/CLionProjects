#pragma once

#include <vector>
#include <memory>
#include <iostream>

class Forward;

class Master {
private:
    // Create instances of incomplete type
    // In this situation we need to include the header with the class, instead of forward declaring the class.
    // Compilation fails even when the 'Forward.h' is not present in the build.

public:
    void createInstancesOfIncompleteType() {
        Forward value;  // error: aggregate ‘Forward value’ has incomplete type and cannot be defined

        Forward* pointer = new Forward;     // error: invalid use of incomplete type ‘class Forward’
        delete pointer;     // warning: possible problem detected in invocation of delete operator: [-Wdelete-incomplete]
                            // warning: ‘pointer’ has incomplete type
                            // note: neither the destructor nor the class-specific operator delete will be called, even if they are declared when the class is defined

        std::unique_ptr<Forward> anotherUniquePtr = std::make_unique<Forward>();    // error: invalid use of incomplete type ‘class Forward’

        Forward& reference = *(new Forward);    // warning: possible problem detected in invocation of delete operator: [-Wdelete-incomplete]
        delete &reference;  // neither the destructor nor the class-specific operator delete will be called, even if they are declared when the class is defined
    }

    void fillContainer() {
        std::vector<Forward> valueContainer;

        for (int number = 0; number < 3; ++number) {
            valueContainer.push_back(Forward());    // error: invalid use of incomplete type ‘class Forward’
        }

        std::cout << valueContainer.size() << std::endl;
    }
};
