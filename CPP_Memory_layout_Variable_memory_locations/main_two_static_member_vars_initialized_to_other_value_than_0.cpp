class foo {
    static float globalNumber;
    static char anotherGlobalNumber;
};

float foo::globalNumber = 1;
char foo::anotherGlobalNumber = -1;

int main() {
    return 0;
}
