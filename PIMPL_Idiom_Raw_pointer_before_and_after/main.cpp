#include <iostream>

#include "Fridge.h"
#include "PIMPL_Fridge/AnotherFridge.h"

// https://www.fluentcpp.com/2017/09/22/make-pimpl-using-unique_ptr/

// Why is PIMPL idiom useful?
// Bscause it speeds up compile times.
// How?
// Because it uses forward declaration of class instead of include directive of a header file with that class.
// So forward declaring a class speeds up the building process than include directive?
// Yes.
// How is that possible?
// Every time we include a header file, the preprocessor opens the header file and replaces the include directive
// with the contents of that header file to the file that includes this header file. With a forward declaration nothing
// like this happens. No header files will be opened and expanded. Forward declaration can be seen as a promise to a
// compiler: "Trust me compiler, I really have a header and an implementation for this class.".
// Then why don't we use forward declarations all the time?
// Because the compiler can use the forward declarations in specific contexts (see "Forward_Class_Declaration_*" projects).
// But whenever we can use the forward declaration, its preferred to the include statement.
// How does it relate to the PIMPL idiom?
// PIMPL idiom relies on forward class or forward type declaration. I use the terms class and type interchangeably
// because the class specifies a type, but a type can be a primitive one instead of a class. Ok, back to the PIMPL
// idiom. When we include a header file in another files in which we use the functionality of that header file,
// every time we modify this header file the compiler recompiles not only the modified header file, but also all the
// clients of this header file, so that they use the changed version of that header file. When we instead forward declare
// an implementation class in the wrapper class, we can modify the implementation class however we want. The compiler
// will only recompile the modified implementation class and the wrapper class will stay untouched. The client code
// will only use the wrapper class, not the implementation class directly. This is similar concept to Adapter or Proxy
// design patterns where we don't access the class directly, but though an abstraction, i.e. another class that the
// client uses. In the PIMPL idiom, the client uses the public interface of the wrapper class. The wrapper class
// uses the implementation class internally. The main advantage of this idiom is that it can improve compile times.
// Disadvantage is that increases the complexity of the program.

int main() {
    std::cout << "Before PIMPL - direct dependency" << std::endl;
    Fridge fridge;
    fridge.coolDown();

    std::cout << std::endl;

    std::cout << "After PIMPL - indirect dependency - driving class wraps implementation class" << std::endl;
    AnotherFridge anotherFridge;
    anotherFridge.coolDown();

    return 0;
}