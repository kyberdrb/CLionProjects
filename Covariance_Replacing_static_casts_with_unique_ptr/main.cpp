#include <iostream>
#include <memory>

using std::cout;
using std::endl;

// Covariance - Refactored to unique pointers with covariance: https://stackoverflow.com/questions/1260757/when-is-c-covariance-the-best-solution/1300608#1300608

class IPart {
public:
    virtual ~IPart() = default;
};

template <typename DerivedPart, typename BasePart>
class IThing {
public:
    virtual ~IThing() = default;

    std::unique_ptr<DerivedPart> part() {
        return std::unique_ptr<DerivedPart>(static_cast<DerivedPart*>(this->part_impl()));
    }

private:
    virtual BasePart* part_impl() = 0;
};

class AFooPart : public IPart {
public:
    void doThis() {
        cout << "doing this foo" << endl;
    }
};

class AFooThing : public IThing<AFooPart, IPart> {
private:
    AFooPart* part_impl() override {
        return new AFooPart;
    }
};

class ABarPart : public IPart {
public:
    void doThat() {
        cout << "doing that bar" << endl;
    }
};

class ABarThing : public IThing<ABarPart, IPart> {
private:
    ABarPart* part_impl() override {
        return new ABarPart;
    }
};

int main() {
    std::unique_ptr<AFooThing> pFooThing = std::make_unique<AFooThing>();
    pFooThing->part()->doThis();

    auto pBarThing = std::make_unique<ABarThing>();
    pBarThing->part()->doThat();

    return 0;
}
