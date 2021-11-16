#include <cstdint>
#include <functional>
#include <iostream>
#include <memory>

class ClassIncompatibleWithClientInterface {     // a class, which we want to wrap
public:
    explicit ClassIncompatibleWithClientInterface(int32_t objectNumber) :
        objectNumber(objectNumber) {}

    void doSomethingElse() {
        std::cout << "Object " << this->objectNumber << ":    " << "doing something else..." << "\n";
    }

private:
    int32_t objectNumber;
};

class ClientInterface {      // an abstract class/interface, from which the Adapter inherits
public:
    virtual void doSomething() = 0;
    virtual ~ClientInterface() = default;
};

class Adapter : public ClientInterface {     // a class, which will wrap the Adaptee
public:
    explicit Adapter(ClassIncompatibleWithClientInterface& adaptee) :
        adaptee(adaptee) {}

    void doSomething() override {
        this->adaptee.get().doSomethingElse();
    }

    void plugOtherInstance(ClassIncompatibleWithClientInterface& adaptee) {
        this->adaptee.get() = adaptee;
    }

private:
    //ClassIncompatibleWithClientInterface& adaptee;  // adaptee in association as a classical reference - non-reassignable reference
    std::reference_wrapper<ClassIncompatibleWithClientInterface> adaptee; // adaptee in association as a reference wrapper - reassignable reference
};

int main() {
    auto instanceIncompatibleWithClientInterface = std::make_unique<ClassIncompatibleWithClientInterface>(1);
    auto adapter = std::make_unique<Adapter>(*instanceIncompatibleWithClientInterface);
    adapter->doSomething();

    auto anotherInstanceIncompatibleWithClientInterface = std::make_unique<ClassIncompatibleWithClientInterface>(2);
    adapter->plugOtherInstance(*anotherInstanceIncompatibleWithClientInterface);
    adapter->doSomething();

    return 0;
}
