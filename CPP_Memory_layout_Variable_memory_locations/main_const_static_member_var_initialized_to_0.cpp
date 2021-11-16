class foo {
    const static int globalNumber;
};

const int foo::globalNumber = 0;

int main() {
    return 0;
}
