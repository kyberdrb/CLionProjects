const float globalNumber = 1;
const char anotherGlobalNumber = -1;
int main() {
    const char temp = anotherGlobalNumber;
    return static_cast<int>(globalNumber);
}
