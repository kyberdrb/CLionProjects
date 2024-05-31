#include <iostream>

#include <memory>

class Base {
public:
    void nonvirtualFunctionNotOverridenButHidden() {
        std::cout << "Base::nonvirtualFunctionNotOverridenButHidden()" << std::endl;
    }

    virtual void virtualFunctionMarkedAsVirtual() {
        std::cout << "Base::virtualFunctionMarkedAsVirtual()" << std::endl;
    }

    virtual void virtualFunctionMarkedAsOverride() {
        std::cout << "Base::virtualFunctionMarkedAsOverride()" << std::endl;
    }

    virtual void pureVirtualFunctionMarkedAsVirtual() = 0;
    virtual void pureVirtualFunctionMarkedAsOverride() = 0;
    virtual void pureVirtualFunctionMarkedAsVirtualOverride() = 0;
    virtual void pureVirtualFunctionMarkedAsFinal() = 0;

    virtual void virtualFunctionNotMarkedAsOverride() {
        std::cout << "Base: defining a non-virtual function in the Base class is allowed, as in any class" << std::endl;
    }

    // When the destructor in the Base class is not marked as 'virtual',
    //  then the destructor of Derived class(es) don't get called.
    //  If (any of) the derived class has some dynamically allocated internal state,
    //  it will result in a memory leak.
    //  Therefore, if we want to deallocate all of the dynamically allocated memory,
    //  we need to mark the Base class destructor as 'virtual'
    //~Base() = default;

    // When the Base class destructor is marked as virtual
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void nonvirtualFunctionNotOverridenButHidden() {
        std::cout << "Derived::nonvirtualFunctionNotOverridenButHidden(): function hiding: hides the one of the base class" << std::endl;
    }

    virtual void virtualFunctionMarkedAsVirtual() {
        std::cout << "Derived::virtualFunctionMarkedAsVirtual()" << std::endl;
    }

    void virtualFunctionMarkedAsOverride() override {
        std::cout << "Derived::virtualFunctionMarkedAsOverride()" << std::endl;
    }

    virtual void pureVirtualFunctionMarkedAsVirtual() {
        std::cout << "Derived::pureVirtualFunctionMarkedAsVirtual()" << std::endl;
    };

    void pureVirtualFunctionMarkedAsOverride() override {
        std::cout << "Derived::pureVirtualFunctionMarkedAsVirtual()" << std::endl;
    };

    virtual void pureVirtualFunctionMarkedAsVirtualOverride() override{
        std::cout << "Derived::pureVirtualFunctionMarkedAsVirtual()" << std::endl;
    };

    void pureVirtualFunctionMarkedAsFinal() final {
        std::cout << "Derived::pureVirtualFunctionMarkedAsVirtual()" << std::endl;
    };

    // If the function is defined in the Base class as (pure) virtual,
    //  and then redefined in the Derived class without any modifier - nor 'virtual', nor 'override', nor 'final',
    //  the function call from the Base type will still be forwarded to the Derived class,
    //  despite missing 'virtual'/'override'/'final' marking.
    //  The 'virtual'/'override'/'final' marking is there only for informational/formal purposes, to indicate the developer/the reader of the code,
    //  that the function is being (re)defined in the Derived class.
    //  The 'virtual'/'override'/'final' marking for the function in the Derived class make sense for the compiler
    //  only when the function is marked as 'virtual' in the Base class.
    void virtualFunctionNotMarkedAsOverride() {
        std::cout << "Derived: defining a non-virtual function in the Base class is allowed, as in any class" << std::endl;
    }

    //void virtualFunctionNotMarkedAsOverride() override {
    //    std::cout << "Overriding a non-virtual function is not allowed: error: ‘void Derived::virtualFunctionNotMarkedAsOverride()’ marked ‘override’, but does not override" << std::endl;
    //}

private:
    uint32_t* dynamicallyAllocatedMember = new uint32_t{1234};
    uint32_t number{42};

public:
    ~Derived() {
        std::cout << "Derived: Destructing dynamically allocated internal state" << std::endl;
        delete this->dynamicallyAllocatedMember;
    }

//    ~Derived() override {
//        std::cout << "Derived: Destructing dynamically allocated internal state" << std::endl;
//        delete dynamicallyAllocatedMember;
//    }
};

// Base: no internal state + nonvirtual destructor
class BaseWithNonvirtualDestructor {
public:
    BaseWithNonvirtualDestructor() {
        std::cout << "BaseWithNonvirtualDestructor: Constructor" << std:: endl;
    }

    ~BaseWithNonvirtualDestructor() {
        std::cout << "BaseWithVirtualDestructor: Destructor" << std::endl;
    };
    //~BaseWithNonvirtualDestructor() = default;
    //~BaseWithNonvirtualDestructor() = 0; // clang-tidy: '~BaseWithNonvirtualDestructor' is not virtual and cannot be declared pure; GCC 14: error: initializer specified for non-virtual method ‘BaseWithNonvirtualDestructor::~BaseWithNonvirtualDestructor()’

};

// Derived: dynamically allocated internal state + undefined/implicitly defined destructor
class DerivedFromBaseWithNonvirtualImplicitDestructor : public BaseWithNonvirtualDestructor {
public:
    DerivedFromBaseWithNonvirtualImplicitDestructor() : BaseWithNonvirtualDestructor() {
        std::cout << "DerivedFromBaseWithNonvirtualImplicitDestructor: Constructor" << std:: endl;
    }

private:
    uint32_t* dynamicallyAllocatedVariable = new uint32_t{2468};
};

// Derived: dynamically allocated internal state + nonvirtual destructor
class DerivedFromBaseWithNonvirtualDestructorWithNonvirtualDestructor : public BaseWithNonvirtualDestructor {
public:
    DerivedFromBaseWithNonvirtualDestructorWithNonvirtualDestructor() : BaseWithNonvirtualDestructor() {
        std::cout << "DerivedFromBaseWithNonvirtualDestructorWithNonvirtualDestructor: Constructor" << std:: endl;
    }

private:
    uint32_t* dynamicallyAllocatedVariable = new uint32_t{2468};

public:
    ~DerivedFromBaseWithNonvirtualDestructorWithNonvirtualDestructor() {
        std::cout << "~DerivedFromBaseWithNonvirtualDestructorWithNonvirtualDestructor: Destructing dynamically allocated internal state" << std::endl;
        delete this->dynamicallyAllocatedVariable;
    }
};

// Derived: dynamically allocated internal state + virtual destructor
class DerivedFromBaseWithNonvirtualDestructorWithVirtualDestructor : public BaseWithNonvirtualDestructor {
public:
    DerivedFromBaseWithNonvirtualDestructorWithVirtualDestructor() : BaseWithNonvirtualDestructor() {
        std::cout << "DerivedFromBaseWithNonvirtualDestructorWithVirtualDestructor: Constructor" << std:: endl;
    }

private:
    uint32_t* dynamicallyAllocatedVariable = new uint32_t{2468};

public:
    virtual ~DerivedFromBaseWithNonvirtualDestructorWithVirtualDestructor() {
        std::cout << "~DerivedFromBaseWithNonvirtualDestructorWithVirtualDestructor: Destructing dynamically allocated internal state" << std::endl;
        delete this->dynamicallyAllocatedVariable;
    }
};

// Derived: dynamically allocated internal state + override destructor
//class DerivedFromBaseWithNonvirtualDestructorWithOverridenDestructor : public BaseWithNonvirtualDestructor {
//public:
//    DerivedFromBaseWithNonvirtualDestructorWithOverridenDestructor() : BaseWithNonvirtualDestructor() {
//        std::cout << "DerivedFromBaseWithNonvirtualDestructorWithOverridenDestructor: Constructor" << std:: endl;
//    }
//
//private:
//    uint32_t* dynamicallyAllocatedVariable = new uint32_t{2468};
//
//public:
//    ~DerivedFromBaseWithNonvirtualDestructorWithOverridenDestructor() override { // Only virtual member functions can be marked 'override': error: ‘DerivedWithOverridenDestructor::~DerivedWithOverridenDestructor()’ marked ‘override’, but does not override
//        std::cout << "~DerivedWithDestructor: Destructing dynamically allocated internal state" << std::endl;
//        delete this->dynamicallyAllocatedVariable;
//    }
//};

// Derived: dynamically allocated internal state + final destructor
//class DerivedFromBaseWithNonvirtualDestructorWithFinalDestructor final : public BaseWithNonvirtualDestructor {
//public:
//    DerivedFromBaseWithNonvirtualDestructorWithFinalDestructor() : BaseWithNonvirtualDestructor() {
//        std::cout << "DerivedFromBaseWithNonvirtualDestructorWithFinalDestructor: Constructor" << std:: endl;
//    }
//
//private:
//    uint32_t* dynamicallyAllocatedVariable = new uint32_t{2468};
//
//public:
//    ~DerivedFromBaseWithNonvirtualDestructorWithFinalDestructor() final { // Only virtual member functions can be marked 'final': error: ‘DerivedWithFinalDestructor::~DerivedWithFinalDestructor()’ marked ‘final’, but is not virtual
//        std::cout << "~DerivedWithDestructor: Destructing dynamically allocated internal state" << std::endl;
//        delete this->dynamicallyAllocatedVariable;
//    }
//};

// Base: no internal state + virtual destructor
class BaseWithVirtualDestructor {
public:
    BaseWithVirtualDestructor() {
        std::cout << "BaseWithVirtualDestructor: Constructor" << std::endl;
    }

    virtual ~BaseWithVirtualDestructor() {
        std::cout << "BaseWithVirtualDestructor: Destructor" << std::endl;
    };
    //virtual ~BaseWithVirtualDestructor() = 0;       // might be also pure virtual...
    //virtual ~BaseWithVirtualDestructor() = default; // or 'default', but for showcasing the destructor call is defined explicitly
};

// Derived: dynamically allocated internal state + undefined/implicitly defined destructor
class DerivedFromBaseWithVirtualDestructorWithImplicitDestructor : public BaseWithVirtualDestructor {
public:
    DerivedFromBaseWithVirtualDestructorWithImplicitDestructor() : BaseWithVirtualDestructor() {
        std::cout << "DerivedFromBaseWithVirtualDestructorWithImplicitDestructor: Constructor" << std:: endl;
    }

private:
    uint32_t* dynamicallyAllocatedVariable = new uint32_t{2468};
};

// Derived: dynamically allocated internal state + nonvirtual destructor
class DerivedFromBaseWithVirtualDestructorWithNonvirtualDestructor : public BaseWithVirtualDestructor {
private:
    uint32_t* dynamicallyAllocatedVariable = new uint32_t{2468};

public:
    ~DerivedFromBaseWithVirtualDestructorWithNonvirtualDestructor() {
        std::cout << "~DerivedFromBaseWithVirtualDestructorWithNonvirtualDestructor: Destructing dynamically allocated internal state" << std::endl;
        delete this->dynamicallyAllocatedVariable;
    }
};

// Derived: dynamically allocated internal state + virtual destructor
class DerivedFromBaseWithVirtualDestructorWithVirtualDestructor : public BaseWithVirtualDestructor {
private:
    uint32_t* dynamicallyAllocatedVariable = new uint32_t{2468};

public:
    virtual ~DerivedFromBaseWithVirtualDestructorWithVirtualDestructor() {
        std::cout << "~DerivedFromBaseWithVirtualDestructorWithVirtualDestructor: Destructing dynamically allocated internal state" << std::endl;
        delete this->dynamicallyAllocatedVariable;
    }
};

// Derived: dynamically allocated internal state + override destructor
class DerivedFromBaseWithVirtualDestructorWithOverridenDestructor : public BaseWithVirtualDestructor {
private:
    uint32_t* dynamicallyAllocatedVariable = new uint32_t{2468};

public:
    ~DerivedFromBaseWithVirtualDestructorWithOverridenDestructor() override { // Only virtual member functions can be marked 'override': error: ‘DerivedWithOverridenDestructor::~DerivedWithOverridenDestructor()’ marked ‘override’, but does not override
        std::cout << "~DerivedFromBaseWithVirtualDestructorWithOverridenDestructor: Destructing dynamically allocated internal state" << std::endl;
        delete this->dynamicallyAllocatedVariable;
    }
};

// Derived: dynamically allocated internal state + final destructor
class DerivedFromBaseWithVirtualDestructorWithFinalDestructor final : public BaseWithVirtualDestructor { // Class with destructor marked 'final' cannot be inherited from
private:
    uint32_t* dynamicallyAllocatedVariable = new uint32_t{2468};

public:
    ~DerivedFromBaseWithVirtualDestructorWithFinalDestructor() final { // Only virtual member functions can be marked 'final': error: ‘DerivedWithFinalDestructor::~DerivedWithFinalDestructor()’ marked ‘final’, but is not virtual
        std::cout << "~DerivedFromBaseWithVirtualDestructorWithFinalDestructor: Destructing dynamically allocated internal state" << std::endl;
        delete this->dynamicallyAllocatedVariable;
    }
};

// Derived: dynamically allocated internal state as unique_ptr + undefined/implicitly defined destructor
class DerivedFromBaseWithNonvirtualDestructorWithUniquePtrMemberVarAndImplicitDestructor : public BaseWithNonvirtualDestructor {
public:
    DerivedFromBaseWithNonvirtualDestructorWithUniquePtrMemberVarAndImplicitDestructor() : BaseWithNonvirtualDestructor() {
        std::cout << "DerivedFromBaseWithNonvirtualDestructorWithUniquePtrMemberVarAndImplicitDestructor: Constructor" << std:: endl;
    }

private:
    std::unique_ptr<uint32_t> dynamicallyAllocatedVariable = std::make_unique<uint32_t>(2468);
};

// Derived: dynamically allocated internal state as unique_ptr + nonvirtual destructor
class DerivedFromBaseWithNonvirtualDestructorWithUniquePtrMemberVarAndNonvirtualDestructor : public BaseWithNonvirtualDestructor {
public:
    DerivedFromBaseWithNonvirtualDestructorWithUniquePtrMemberVarAndNonvirtualDestructor() : BaseWithNonvirtualDestructor() {
        std::cout << "DerivedFromBaseWithNonvirtualDestructorWithUniquePtrMemberVarAndNonvirtualDestructor: Constructor" << std:: endl;
    }

private:
    std::unique_ptr<uint32_t> dynamicallyAllocatedVariable = std::make_unique<uint32_t>(2468);

public:
    ~DerivedFromBaseWithNonvirtualDestructorWithUniquePtrMemberVarAndNonvirtualDestructor() {
        std::cout << "~DerivedFromBaseWithNonvirtualDestructorWithUniquePtrMemberVarAndNonvirtualDestructor: Destructing dynamically allocated internal state as unique_ptr" << std::endl;
    }
};

// Derived: dynamically allocated internal state as unique_ptr + virtual destructor
class DerivedFromBaseWithNonvirtualDestructorWithUniquePtrMemberVarAndVirtualDestructor : public BaseWithNonvirtualDestructor {
public:
    DerivedFromBaseWithNonvirtualDestructorWithUniquePtrMemberVarAndVirtualDestructor() : BaseWithNonvirtualDestructor() {
        std::cout << "DerivedFromBaseWithNonvirtualDestructorWithUniquePtrMemberVarAndVirtualDestructor: Constructor" << std:: endl;
    }

private:
    std::unique_ptr<uint32_t> dynamicallyAllocatedVariable = std::make_unique<uint32_t>(2468);

public:
    virtual ~DerivedFromBaseWithNonvirtualDestructorWithUniquePtrMemberVarAndVirtualDestructor() {
        std::cout << "~DerivedFromBaseWithNonvirtualDestructorWithUniquePtrMemberVarAndVirtualDestructor: Destructing dynamically allocated internal state as unique_ptr" << std::endl;
    }
};

int main() {
    std::unique_ptr<Base> base{std::make_unique<Derived>()};

    base->nonvirtualFunctionNotOverridenButHidden();

    std::unique_ptr<Derived> derived{std::make_unique<Derived>()};

    derived->nonvirtualFunctionNotOverridenButHidden();

    std::cout << std::endl;

    base->virtualFunctionMarkedAsVirtual();
    derived->virtualFunctionMarkedAsVirtual();

    std::cout << std::endl;

    base->virtualFunctionMarkedAsOverride();
    derived->virtualFunctionMarkedAsOverride();

    std::cout << std::endl;

    base->pureVirtualFunctionMarkedAsVirtual();
    derived->pureVirtualFunctionMarkedAsVirtual();

    std::cout << std::endl;

    base->pureVirtualFunctionMarkedAsOverride();
    derived->pureVirtualFunctionMarkedAsOverride();

    std::cout << std::endl;

    base->pureVirtualFunctionMarkedAsVirtualOverride();
    derived->pureVirtualFunctionMarkedAsVirtualOverride();

    std::cout << std::endl;

    base->pureVirtualFunctionMarkedAsFinal();
    derived->pureVirtualFunctionMarkedAsFinal();

    std::cout << std::endl;

    base->virtualFunctionNotMarkedAsOverride();
    derived->virtualFunctionNotMarkedAsOverride();
    dynamic_cast<Derived*>(base.get())->virtualFunctionNotMarkedAsOverride();
    derived.reset();

    std::cout << std::endl;

    std::cout << "Memory leak test when deallocating dynamically allocated member variable of a derived class\n" << std::endl;

    std::unique_ptr<BaseWithNonvirtualDestructor> baseWithNonvirtualDestructor;

//    baseWithNonvirtualDestructor = std::make_unique<DerivedFromBaseWithNonvirtualImplicitDestructor>(); // Valgrind: Leak_DefinitelyLost: 4 bytes in 1 blocks are definitely lost in loss record 1 of 1 + Mismatched new/delete size value: 1 - Address 0x4e25620 is 0 bytes inside a block of size 8 alloc'd
//    baseWithNonvirtualDestructor.reset(); // Valgrind: MismatchedAllocateDeallocateSize: Mismatched new/delete size value: 1
//    baseWithNonvirtualDestructor = std::make_unique<DerivedFromBaseWithNonvirtualDestructorWithNonvirtualDestructor>(); // Valgrind: Leak_DefinitelyLost: 4 bytes in 1 blocks are definitely lost in loss record 1 of 1 + Mismatched new/delete size value: 1 - Address 0x4e25620 is 0 bytes inside a block of size 8 alloc'd
//    baseWithNonvirtualDestructor.reset(); // Valgrind: MismatchedAllocateDeallocateSize: Mismatched new/delete size value: 1
//    baseWithNonvirtualDestructor = std::make_unique<DerivedFromBaseWithNonvirtualDestructorWithVirtualDestructor>(); // Valgrind: Leak_DefinitelyLost: 4 bytes in 1 blocks are definitely lost in loss record 1 of 1 + Mismatched new/delete size value: 1 - Address 0x4e25620 is 0 bytes inside a block of size 16 alloc'd
//    baseWithNonvirtualDestructor.reset(); // Valgrind: MismatchedAllocateDeallocateSize: Mismatched new/delete size value: 1

    std::cout << std::endl;

    std::unique_ptr<BaseWithVirtualDestructor> baseWithVirtualDestructor;
//    baseWithVirtualDestructor = std::make_unique<DerivedFromBaseWithVirtualDestructorWithImplicitDestructor>(); // Valgrind: Leak_DefinitelyLost: memory leak 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
//    baseWithVirtualDestructor.reset();
    baseWithVirtualDestructor = std::make_unique<DerivedFromBaseWithVirtualDestructorWithNonvirtualDestructor>();
    baseWithVirtualDestructor.reset();
    baseWithVirtualDestructor = std::make_unique<DerivedFromBaseWithVirtualDestructorWithVirtualDestructor>();
    baseWithVirtualDestructor.reset();
    baseWithVirtualDestructor = std::make_unique<DerivedFromBaseWithVirtualDestructorWithOverridenDestructor>();
    baseWithVirtualDestructor.reset();
    baseWithVirtualDestructor = std::make_unique<DerivedFromBaseWithVirtualDestructorWithFinalDestructor>();
    baseWithVirtualDestructor.reset();



    baseWithNonvirtualDestructor.reset();

//    baseWithNonvirtualDestructor = std::make_unique<DerivedFromBaseWithNonvirtualDestructorWithUniquePtrMemberVarAndImplicitDestructor>(); // Valgrind: Leak_DefinitelyLost: 4 bytes in 1 blocks are definitely lost in loss record 1 of 1 + Mismatched new/delete size value: 1 - Address 0x4e258a0 is 0 bytes inside a block of size 8 alloc'd
//    baseWithNonvirtualDestructor.reset(); // Valgrind: MismatchedAllocateDeallocateSize: Mismatched new/delete size value: 1
//    baseWithNonvirtualDestructor = std::make_unique<DerivedFromBaseWithNonvirtualDestructorWithUniquePtrMemberVarAndNonvirtualDestructor>(); // Valgrind: Leak_DefinitelyLost: 4 bytes in 1 blocks are definitely lost in loss record 1 of 1 + Mismatched new/delete size value: 1 - Address 0x4e258a0 is 0 bytes inside a block of size 8 alloc'd
//    baseWithNonvirtualDestructor.reset(); // Valgrind: MismatchedAllocateDeallocateSize: Mismatched new/delete size value: 1
//    baseWithNonvirtualDestructor = std::make_unique<DerivedFromBaseWithNonvirtualDestructorWithUniquePtrMemberVarAndVirtualDestructor>(); // Valgrind: Leak_DefinitelyLost: 4 bytes in 1 blocks are definitely lost in loss record 1 of 1 + Mismatched new/delete size value: 1 - Address 0x4e258a0 is 0 bytes inside a block of size 8 alloc'd
//    baseWithNonvirtualDestructor.reset(); // Valgrind: MismatchedAllocateDeallocateSize: Mismatched new/delete size value: 1


    return 0;
}
