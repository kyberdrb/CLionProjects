#pragma once

class Forward;

class Master {
    Forward attributeByValue;   // Declaration of object member variable by value in a class.
                                // error: field ‘attributeByValue’ has incomplete type ‘Forward’
                                // In this situation we need to include the header with the class, instead of forward declaring the class.
                                // Compilation fails even when the 'Forward.h' is not present in the build.
};
