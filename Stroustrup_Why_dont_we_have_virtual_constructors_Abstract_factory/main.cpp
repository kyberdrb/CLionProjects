// Bjarne Stroustrup's C++ Style and Technique FAQ: Why don't we have virtual constructors?:
//  http://www.stroustrup.com/bs_faq2.html
//  http://webcache.googleusercontent.com/search?q=cache:BuQbEpwr1-IJ:www.stroustrup.com/bs_faq2.html+&cd=1&hl=de&ct=clnk&gl=sk

struct A {
    virtual ~A() = default;
};
struct B {
    virtual ~B() = default;
};

struct F {
    virtual A* make_an_A() const = 0;
    virtual B* make_an_B() const = 0;
    virtual ~F() = default;
};

struct AX : A {};
struct BX : B {};

struct FX : F {
    AX* make_an_A() const override {
        return new AX;
    }

    BX* make_an_B() const override {
        return new BX;
    }
};

struct AY : A {};
struct BY : B {};

struct FY : F {
    AY* make_an_A() const override {
        return new AY;
    }

    BY* make_an_B() const override {
        return new BY;
    }
};

void user(const F& fac) {
    A* aa = fac.make_an_A();
    B* bb = fac.make_an_B();
    delete bb;
    delete aa;
}

int main() {
    FX fx;
    FY fy;

    user(fx);
    user(fy);

    user(FX());
    user(FY());

    return 0;
}
