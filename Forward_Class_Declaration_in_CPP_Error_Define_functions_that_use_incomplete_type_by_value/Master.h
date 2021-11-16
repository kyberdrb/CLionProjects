#pragma once

class Forward;

class Master {
                                                // Define functions or methods using the incomplete type by value
    void acceptByValue(Forward forward) {}      // error: ‘forward’ has incomplete type
    Forward returnByValue() {}                  // error: error: return type ‘class Forward’ is incomplete
                                                // In this situation we need to include the header with the class, instead of forward declaring the class.
                                                // Compilation fails even when the 'Forward.h' is not present in the build.
};
