class ObjectByValue {};
class OtherThings {};

// Appropriate smart pointer for composition: https://stackoverflow.com/questions/28595337/appropriate-smart-pointer-for-composition/28595486#28595486

struct A {
    ObjectByValue obv;

    virtual ~A() = default;
};

struct B : A {
    OtherThings ot;
};

struct C {
    A& a;

    explicit C(A& a) : a(a) {}
};

int main() {
    {
        static A a;
        C c(a);

        static B b;
        C cc(b);
    }

    return 0;
}
