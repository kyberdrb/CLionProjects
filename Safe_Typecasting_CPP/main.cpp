#include <iostream>
#include <typeinfo>
#include <memory>

using std::cout;
using std::endl;

// Safe Typecasting in C++ / 'instanceof' operator in C++:
// - https://stackoverflow.com/questions/500493/c-equivalent-of-javas-instanceof/25231384#25231384
// - https://stackoverflow.com/questions/500493/c-equivalent-of-javas-instanceof/500495#500495
// - https://stackoverflow.com/questions/500493/c-equivalent-of-javas-instanceof/25231384#25231384
// Print variable type in C++: https://stackoverflow.com/questions/81870/is-it-possible-to-print-a-variables-type-in-standard-c/81913#81913

enum ClassType {
    BASE,
    DERIVED,
    ANOTHER_DERIVED,
    DEEP_DERIVED
};

class Base {
public:
    explicit Base(ClassType type) : type(type) {}

    virtual ~Base() = default;
    virtual void doSomething() = 0;

    ClassType getType() const {
        return type;
    }

private:
    Base() : type(ClassType::BASE) {}

    ClassType type;
};

class Derived : public Base {
public:
    using Base::Base;   // use constructor forwarding to call Base class constructor from the DeepDerived class

    Derived() : Base(ClassType::DERIVED) {}

    ~Derived() override = default;

    void doSomething() override {
        cout << "derived is doing something..." << endl;
    }

    void derivedSpecialFunction() {
        cout << "doing something special in derived" << endl;
    }

    ClassType getType() const {
        return ClassType::DERIVED;
    }
};

class AnotherDerived : public Base {
public:
    AnotherDerived() : Base(ClassType::ANOTHER_DERIVED) {}

    void doSomething() override {
        cout << "doing something..." << endl;
    }
};

class DeepDerived : public Derived {
public:
    DeepDerived() : Derived(ClassType::DEEP_DERIVED) {}

    void doSomething() override {
        cout << "deep derived is doing something..." << endl;
    }

    void deepDerivedSpecialFunction() {
        cout << "doing something special in deep derived" << endl;
    }
};

class Something {};

class TypeCaster {
public:
    static bool typecastToDerivedWithSafetyCheck(Base* instance) {
        if(Derived* castedInstance = dynamic_cast<Derived*>(instance)) {
            // old was safely casted to Derived
            castedInstance->doSomething();
            return true;
        }
        return false;
    }
};

template<typename Base, typename T>
inline bool instanceof(const T*) {
    return std::is_base_of<Base, T>::value;
}

template<typename Base, typename T>
inline bool instanceof_polymorphic(const T *ptr) {
    return dynamic_cast<const Base*>(ptr) != nullptr;
}

int main() {
    Base* derived = new Derived;
    bool wasTypecastSuccessful = TypeCaster::typecastToDerivedWithSafetyCheck(derived);
    cout << "Was typecast successful? Base->Derived:        " << wasTypecastSuccessful << endl;

    Base* anotherDerived = new AnotherDerived;
    wasTypecastSuccessful = TypeCaster::typecastToDerivedWithSafetyCheck(anotherDerived);
    cout << "Was typecast successful? Base->AnotherDerived: " << wasTypecastSuccessful << endl;

    DeepDerived* deep = new DeepDerived;

    cout << endl;

    Something something;

    cout << typeid(derived).name() << endl;
    cout << typeid(anotherDerived).name() << endl;
    cout << typeid(deep).name() << endl;
    cout << typeid(something).name() << endl;
    cout << (typeid(derived).name() == typeid(derived).name()) << endl;
    cout << (typeid(derived).name() == typeid(anotherDerived).name()) << endl;
    cout << (typeid(derived).name() == typeid(deep).name()) << endl;

    cout << endl;

    // Polymorphism without RTTI, i.e. dynamic_cast
    if(derived->getType() == DERIVED) {
        cout << "derived is an instance of type Derived" << endl;
        Derived* derivedTemp = static_cast<Derived*>(derived);
        derivedTemp->derivedSpecialFunction();
    }

    if(!derived->getType() == BASE) {
        cout << "derived is not an instance of type Base" << endl;
    }

    std::unique_ptr<Base> deepDerived(new DeepDerived);

    if(deepDerived->getType() == DEEP_DERIVED) {
        cout << "deep derived is an instance of type Derived or DeepDerived" << endl;
        DeepDerived* deepDerivedTemp = static_cast<DeepDerived*>(deepDerived.get());
        deepDerivedTemp->deepDerivedSpecialFunction();
    }

    cout << endl;

    if (instanceof<Base>(derived)) {
        cout << "Base is the base class for derived" << endl;
    }

    if (!instanceof<Derived>(derived)) {
        cout << "Derived is not the base class for derived" << endl;
    }

    //if (instanceof<Base>(something)) { }    // compilation error: no matching function call

    if (instanceof_polymorphic<Derived>(derived)) {
        cout << "derived is an instance of type Derived" << endl;
    }

    cout << endl;

    if (instanceof_polymorphic<Base>(deepDerived.get())) {
        cout << "deep derived is an instance of type Base" << endl;
    }

    if (instanceof_polymorphic<Derived>(deepDerived.get())) {
        cout << "deep derived is an instance of type Derived" << endl;
    }

    if (instanceof_polymorphic<DeepDerived>(deepDerived.get())) {
        cout << "deep derived is an instance of type DeepDerived" << endl;
    }

    // Error in the 'instanceof_polymorphic' function:
    // - error: cannot dynamic_cast ‘ptr’ (of type ‘const class Something*’) to type ‘const class Base*’ (source type is not polymorphic)
//    if (!instanceof_polymorphic<Base>(&something)) {
//        cout << "Something is not of a base class Base" << endl;
//    }

    delete deep;
    delete derived;
    delete anotherDerived;

    return 0;
}
