#include <iostream>

using std::cout;
using std::endl;

// Covariance: https://stackoverflow.com/questions/1260757/when-is-c-covariance-the-best-solution/1300608#1300608

class IPart {
public:
    virtual ~IPart() = default;
};

class IThing {
public:
    virtual ~IThing() = default;
    virtual IPart* part() = 0;
};

class AFooPart : public IPart {
public:
    void doThis() {
        cout << "doing this foo" << endl;
    }
};

class AFooThing : public IThing {
public:
    AFooPart* part() override {
        return new AFooPart;
    }
};

class ABarPart : public IPart {
public:
    void doThat() {
        cout << "doing that bar" << endl;
    }
};

class ABarThing : public IThing {
public:
    ABarPart* part() override {
        return new ABarPart;
    }
};

int main() {
    AFooThing* pFooThing = new AFooThing;
//    static_cast<AFooPart*>(pFooThing->part())->doThis();    // memory leak
//    pFooThing->part()->doThis();    // memory leak
    IPart* pFooPart = pFooThing->part();
    static_cast<AFooPart*>(pFooPart)->doThis(); // static_cast works on downcasting when the derived class has no member variables
    dynamic_cast<AFooPart*>(pFooPart)->doThis();

    IThing* pBarThing = new ABarThing;
    IPart* pBarPart = pBarThing->part();
    dynamic_cast<ABarPart*>(pBarPart)->doThat();

    delete pBarPart;
    delete pBarThing;

    delete pFooPart;
    delete pFooThing;
    return 0;
}
