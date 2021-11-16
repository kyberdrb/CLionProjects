#pragma once

#include <memory>

// PIMPL Idiom
// One big advantage of this idiom is that it breaks compile-time dependencies.
// First, system builds run faster because using a Pimpl can eliminate extra #includes.
// I have worked on projects where converting just a few widely-visible classes to use Pimpls has halved the system’s build time.
// Second, it localizes the build impact of code changes because the parts of a class that reside in the Pimpl can be
// freely changed – that is, members can be freely added or removed – without recompiling client code.
// Because it’s so good at eliminating compilation cascades due to changes in only the now-hidden members, it’s often dubbed a “compilation firewall.”

class Fridge {
    class FridgeImpl;   // all Fridge implementation is in FridgeImpl class. The Fridge class only manages the lifecycle of the pointer 'pimpl' to FridgeImpl class.
                        // FridgeImpl is a forward declared class. All forward declared classes are of incomplete type, but
                        // unique_ptr requires a complete type, therefore, we need to explicitly define destructor for the Fridge class.
                        // The compiler won't do it for us because it's a forward declared class.
                        // See the destructor comment for further info.
    std::unique_ptr<FridgeImpl> pimpl;

public:
    Fridge();
    ~Fridge();      // unique_ptr implementation of PIMPL idiom needs a declaration of the destructor in the client class,
                    // otherwise compiler produces an error
                    //      /usr/include/c++/9.2.0/bits/unique_ptr.h:284:17:   required from ‘std::unique_ptr<_Tp, _Dp>::~unique_ptr() [with _Tp = Fridge::FridgeImpl; _Dp = std::default_delete<Fridge::FridgeImpl>]’
                    //      /home/laptop/CLionProjects/UniquePtrPIMPL_Idiom/UniquePtrPIMPL_Idiom/Fridge.h:5:7:   required from here
                    //      /usr/include/c++/9.2.0/bits/unique_ptr.h:79:16: error: invalid application of ‘sizeof’ to incomplete type ‘Fridge::FridgeImpl’
                    // the unique_ptr needs a destructor in order for it to treat it as a complete type. I didn't even noticed it the first time.
                    // It was in this line
                    //     /usr/include/c++/9.2.0/bits/unique_ptr.h:284:17:   required from ‘std::unique_ptr<_Tp, _Dp>::~unique_ptr() [with _Tp = Fridge::FridgeImpl; _Dp = std::default_delete<Fridge::FridgeImpl>]’
                    // the unique_ptr destructor: ~unique_ptr()
                    // This error relates to a rule in C++ called
                    // Destructor visibility
                    //  There is a rule in C++ that says that deleting a pointer leads to undefined behaviour if:
                    //  - this pointer has type void*, or
                    //  - the type pointed to is incomplete, that is to say is only forward declared, like FridgeImpl in our header file.
                    //  std::unique_ptr happens to check in its destructor if the definition of the type is visible before calling delete. So it refuses to compile and to call delete if the type is only forward declared.

    void coolDown();
};