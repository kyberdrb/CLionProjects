class foo {
    const static float globalNumber;
    const static int anotherGlobalNumber;
};

const float foo::globalNumber = 0;
const int foo::anotherGlobalNumber = 0;

int main() {
    return 0;
}
