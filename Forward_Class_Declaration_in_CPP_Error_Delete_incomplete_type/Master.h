#pragma once

#include <vector>

class Forward;

class Master {
private:
    // Delete address of instance for an incomplete type
    // In this situation we need to include the header with the class, instead of forward declaring the class.
    // Compilation fails even when the 'Forward.h' is not present in the build.

    std::vector<Forward> container;

public:
    void deleteInstanceOfIncompleteType(Forward* forward) {
        delete forward;     // Deleting pointer to incomplete type 'Forward' may cause undefined behavior
                            // See "Messages" (Alt + 0) for these messages:
                            //  warning: possible problem detected in invocation of delete operator: [-Wdelete-incomplete]
                            //  warning: ‘forward’ has incomplete type
                            //  note: neither the destructor nor the class-specific operator delete will be called,
                            //   even if they are declared when the class is defined

        // From the C++ standard: 5.3.5/5:
        // "If the object being deleted has incomplete class type at the point of deletion and the complete class has a
        // non-trivial destructor or a deallocation function, the behavior is undefined."
        // e.g gcc 4.2.1 errors out and reports a note: neither the destructor nor the class-specific operator delete
        // will be called, even if they are declared when the class is defined.
    }
};
