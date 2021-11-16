#include <iostream>
#include "cassert"

// Address of static member in a Class: https://stackoverflow.com/questions/32509820/address-of-static-member-in-a-class

class directM {
    int a;
    static int b;

public:
    directM(int aa, int bb) {
        a = aa;
        b = bb;
    }
    void show() {
        std::cout << a << b << std::endl;
    }

    directM& operator=(int number) {
        this->a = number;
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& out, const directM& dm) {
        out << "a:\t" << dm.a << "; b:\t" << dm.b;
        return out;
    }

    static int* getAddressOfB() {
        return &b;
    }
};

int directM::b = -1;

int main() {
    directM dm(10, 20);
    dm.show();

    dm = 13;
    dm.show();

    *(int*) (&dm) = 15; // reinterpret cast in C
    dm.show();

    *(reinterpret_cast<int*>(&dm)) = 17;    // reinterpret cast in C++
    dm.show();

    std::cout << std::endl;
    int* pointerToB = directM::getAddressOfB();
    assert(directM::getAddressOfB() == dm.getAddressOfB());
    std::cout << "directM::b\t" << pointerToB << "\t'data' part of the data section" << std::endl;
    std::cout << "&pointerToB\t" << &pointerToB << "\tstack" << std::endl;

    *pointerToB = 23;

    std::cout << std::endl;

    std::cout << "&dm =\t" << &dm << std::endl;
    std::cout << "sizeof(dm) =\t" << sizeof(dm) << std::endl;
    std::cout << "sizeof(dm.a) =\t" << sizeof(*(int*)(&dm)) << std::endl;
    std::cout << "dm.a =\t" << *(int*)(&dm) << std::endl;
    std::cout << "sizeof(*directM::b) =\t" << sizeof(*directM::getAddressOfB()) << std::endl;
    std::cout << "*directM::b =\t" << *directM::getAddressOfB() << std::endl;
    std::cout << "dm =\t" << dm << std::endl;

    return 0;
}
