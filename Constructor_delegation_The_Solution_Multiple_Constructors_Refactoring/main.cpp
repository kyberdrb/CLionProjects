#include <iostream>
#include <string>

using std::cout;
using std::endl;

// Modern C++ Features – Inherited and Delegating Constructors: Delegating Constructors: https://arne-mertz.de/2015/08/new-c-features-inherited-and-delegating-constructors/

class ResourceHandle {
public:
    virtual ~ResourceHandle() = default;
    virtual std::string describe() const = 0;
};

class ResourceHandle1 : public ResourceHandle {
public:
    ResourceHandle1() = default;

    std::string describe() const override {
        return "Resource Handle 1";
    }
};

class ResourceHandle2 : public ResourceHandle {
public:
    ResourceHandle2() = default;

    std::string describe() const override {
        return "Resource Handle 2";
    }
};

class ResourceSpecifier {
public:
    virtual ~ResourceSpecifier() = default;
    virtual std::string toString() const = 0;
};

class ResourceSpecifier1 : public ResourceSpecifier {
public:
    ResourceSpecifier1() = default;

    explicit ResourceSpecifier1(std::string text) : text(std::move(text)) {}

    std::string toString() const override {
        return "ResourceSpecifier1";
    }

    std::string getText() {
        return text;
    }

    ResourceHandle1* allocResource() const {
        return new ResourceHandle1;
    }

private:
    std::string text;
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

    ResourceHandle2* allocResource() const {
        return new ResourceHandle2;
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

class Logger {
public:
    static void logError(const std::string& message) {
        std::cout << message << std::endl;
    }
};

class TwinResource {
public:
    TwinResource(ResourceSpecifier1* rs1, ResourceSpecifier2* rs2) :
        firstResource(rs1->allocResource()),
        secondResource(rs2->allocResource())
    {
        verifyResourcesAreAllocated(rs1, rs2);
    }

    TwinResource(ResourceSpecifier1* rs1, double aValue)
        : TwinResource(rs1, new ResourceSpecifier2(aValue)) {}

    TwinResource(std::string aName, ResourceSpecifier2* rs2)
        : TwinResource(new ResourceSpecifier1(std::move(aName)), rs2) {}

    ~TwinResource() {
        delete firstResource;
        delete secondResource;
    }

    ResourceHandle1* getFirstResource() const {
        return firstResource;
    }

    ResourceHandle2* getSecondResource() const {
        return secondResource;
    }

private:
    ResourceHandle1* firstResource{};
    ResourceHandle2* secondResource{};

    void verifyResourcesAreAllocated(ResourceSpecifier* rs1, ResourceSpecifier* rs2) {
        if (!firstResource) {
            Logger::logError("ResourceHandle1 allocation failed by: \t" + rs1->toString());
        }
        if (!secondResource) {
            Logger::logError("ResourceHandle2 allocation failed by: \t" + rs2->toString());
        }
        if (!firstResource || !secondResource) {
            throw SomeFatalResourceException();
        }
    }
};

int main() {
    auto* rs1 = new ResourceSpecifier1;
    auto* rs2 = new ResourceSpecifier2;
    cout << rs1->toString() << endl;
    cout << rs2->toString() << endl;
    TwinResource twinResource(rs1, rs2);
    cout << twinResource.getFirstResource()->describe() << endl;
    cout << twinResource.getSecondResource()->describe() << endl;

    cout << endl;

    auto rs1Text = new ResourceSpecifier1("RS1");
    cout << rs1Text->getText() << endl;
    TwinResource twinResourceWithText(rs1Text, rs2);

    cout << endl;

    auto rs2Value = new ResourceSpecifier2(42);
    cout << rs2Value->getValue() << endl;
    TwinResource twinResourceWithValue(rs1, rs2Value);

    delete rs2Value;
    delete rs1Text;
    delete rs2;
    delete rs1;

    return 0;
}
