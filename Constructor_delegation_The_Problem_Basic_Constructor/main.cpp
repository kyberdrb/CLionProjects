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
    std::string toString() const override {
        return "ResourceSpecifier1";
    }
};

class ResourceSpecifier2 : public ResourceSpecifier {
public:
    std::string toString() const override {
        return "ResourceSpecifier2";
    }
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
        if (!firstResource) {
            logError("Resource allocation failed: " + toString(rs1));
        }
        if (!secondResource)
            logError("Resource allocation failed: " + toString(rs2));
        if (!firstResource || !secondResource) {
            throw SomeFatalResourceException();
        }
    }

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
