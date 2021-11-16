#include <iostream>
#include <string>
#include <sstream>

// Modern C++ Features – Inherited and Delegating Constructors: Delegating Constructors: https://arne-mertz.de/2015/08/new-c-features-inherited-and-delegating-constructors/

class ResourceHandle {
    virtual void noop() {
        static_cast<void>(nullptr);
    }
};

class ResourceHandle1 : public ResourceHandle {
public:
    ResourceHandle1() = default;
};

class ResourceHandle2 : public ResourceHandle {
public:
    ResourceHandle2() = default;
};

class ResourceSpecifier {
public:
    virtual std::string toString() const = 0;
    virtual ~ResourceSpecifier() = default;
};

class ResourceSpecifier1 : public ResourceSpecifier {
public:
    ResourceSpecifier1() = default;

    explicit ResourceSpecifier1(std::string text) {}

    std::string toString() const override {
        return "ResourceSpecifier1";
    }
};

class ResourceSpecifier2 : public ResourceSpecifier {
public:
    ResourceSpecifier2() = default;

    explicit ResourceSpecifier2(double value) : value(value) {}

    std::string toString() const override {
        return "ResourceSpecifier2";
    }

    double getValue() const {
        return value;
    }

private:
    double value{};
};

class SomeFatalResourceException : public std::exception {
public:
    const char *what() const noexcept override {
        return "Some Fatal Resource Exception";
    }
};

class TwinResource {
public:
    TwinResource(ResourceSpecifier1* rs1, ResourceSpecifier2* rs2) :
        firstResource(dynamic_cast<ResourceHandle1*>(allocResource(rs1))),
        secondResource(dynamic_cast<ResourceHandle2*>(allocResource(rs2)))
    {
        verifyResourcesAreAllocated();
    }

    TwinResource(ResourceSpecifier1* rs1, double aValue)
        : TwinResource(rs1, dynamic_cast<ResourceSpecifier2*>(determineResourceSpec2(aValue))) {}

    TwinResource(std::string aName, ResourceSpecifier* rs2)
        : TwinResource(
                dynamic_cast<ResourceSpecifier1*>(determineResourceSpec1(aName)),
                dynamic_cast<ResourceSpecifier2*>(rs2)) {}

    ~TwinResource() {
        delete firstResource;
        delete secondResource;
    }

private:
    ResourceHandle1* firstResource{};
    ResourceHandle2* secondResource{};

    ResourceHandle* allocResource(ResourceSpecifier* rs) {
        if (dynamic_cast<ResourceSpecifier1*>(rs)) {
            return new ResourceHandle1;
        }
        if (dynamic_cast<ResourceSpecifier2*>(rs)) {
            return new ResourceHandle2;
        }
        return nullptr;
    }

    void verifyResourcesAreAllocated() {
        if (!firstResource) {
            logError("ResourceHandle1 allocation failed");
        }
        if (!secondResource)
            logError("ResourceHandle2 allocation failed");
        if (!firstResource || !secondResource) {
            throw SomeFatalResourceException();
        }
    }

    ResourceSpecifier* determineResourceSpec2(double value) {
        return new ResourceSpecifier2(value);
    }

    ResourceSpecifier* determineResourceSpec1(std::string text) {
        return new ResourceSpecifier1(text);
    }

    std::string toString(ResourceSpecifier* rs) {
        std::stringstream rsStream;
        rsStream << rs->toString();
        return rsStream.str();
    }

    void logError(std::string message) {
        std::cout << message << std::endl;
    }
};

int main() {
    ResourceSpecifier1* rs1 = new ResourceSpecifier1;
    ResourceSpecifier2* rs2 = new ResourceSpecifier2;

    TwinResource twinResource(rs1, rs2);

    delete rs1;
    delete rs2;

    return 0;
}
