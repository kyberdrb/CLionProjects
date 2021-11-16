class foo {
    const static float globalNumber;
    const static int anotherGlobalNumber;
};

const float foo::globalNumber = 1;
const int foo::anotherGlobalNumber = -1;

int main() {
    return 0;
}
