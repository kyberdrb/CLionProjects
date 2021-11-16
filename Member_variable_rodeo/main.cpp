#include <iostream>
#include <cassert>

// Address of static member in a Class: https://stackoverflow.com/questions/32509820/address-of-static-member-in-a-class

class directM {
    int a;
    int b;

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
};

int main() {
    directM dm(10, 20);
    dm.show();

    dm = 13;
    dm.show();

    *(int*) (&dm) = 15; // reinterpret cast in C
    dm.show();

    *(reinterpret_cast<int*>(&dm)) = 17;    // reinterpret cast in C++
    dm.show();

    *( (int*)&dm + 1) = 22;
    dm.show();

    *( (int*)(&dm) + 1) = 23;
    std::cout << "(int*)(&dm) + 1 =\t" << (int*)(&dm) + 1 << std::endl;
    dm.show();

    std::cout << std::endl;
//    *(int*)((int*)(&dm + 1)) = 25;  // *** stack smashing detected ***: terminated
    std::cout << "undefined behavior (stack smashing or SIGABRT)...\n"
                 "rewriting memory outside the program boundaries:\n"
                 "\t(int*)((int*)(&dm + 1))\t" << (int*)((int*)(&dm + 1)) << std::endl;
    assert((int*)((int*)(&dm + 1)) != (int*)( ( (int*)(&dm)) + 1)); // ...(&dm + 1)... means move by the size of dm, not int
    std::cout << std::endl;

    *(int*)( ( (int*)(&dm)) + 1) = 27;
    std::cout << "(int*)( ( (int*)(&dm)) + 1)\t" << (int*)( ( (int*)(&dm) ) + 1 ) << std::endl;
    dm.show();

    *(int*)(int*)(int*)( ( (int*)(&dm) + 1)) = 29;
    dm.show();

    std::cout << std::endl;

    std::cout << "&dm =\t" << &dm << std::endl;
    std::cout << "sizeof(dm) =\t" << sizeof(dm) << std::endl;
    std::cout << "sizeof(dm.a) =\t" << sizeof(*(int*)(&dm)) << std::endl;
    std::cout << "dm.a =\t" << *(int*)(&dm) << std::endl;
    std::cout << "sizeof(dm.b) =\t" << sizeof(*(int*)(&dm) + 1) << std::endl;
    std::cout << "dm.b =\t" << *(int*)((int*)(&dm) + 1) << std::endl;
    std::cout << "dm =\t" << dm << std::endl;

    return 0;
}
