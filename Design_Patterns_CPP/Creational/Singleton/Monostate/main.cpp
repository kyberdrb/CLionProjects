#include <iostream>

// Monostate is one way of implementing a singleton.
// Monostate is an ordinary class with only static storage attributes.
// It's a very simple implementation.
// Problems can arise when:
//    - the user or client don't know that the class is a Singleton;
//      a possible solution would be to append 'Monostate' at the end of a class name
//      e.g. "PrinterMonostate"
//    - we want to inherit from a Singleton beacuse
//      static variables are not inherited, only getters and setters is inherited
// Generally a bad idea. It will work, but it won't scale.
class Printer {
    static int id;
public:
    int getId() const { return id; }
    void setId(int value) { id = value; }
};

int Printer::id;

int main() {
    Printer p;
    int id = p.getId();
    std::cout << id << std::endl;

    Printer p2;
    int id2 = p.getId();
    std::cout << id2 << std::endl;
    return 0;
}