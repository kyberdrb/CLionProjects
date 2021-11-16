class foo {
    const static int globalNumber;
};

const int foo::globalNumber = 1;

int main() {
    return 0;
}
