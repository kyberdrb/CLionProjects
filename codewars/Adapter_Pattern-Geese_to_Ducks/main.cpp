#include "Goose.h"
#include "GooseToIDuckAdapter.h"

int main() {
    Goose goose;
    GooseToIDuckAdapter adapter(goose);
    std::cout << goose.Honk();
    std::cout << " : ";
    std::cout << adapter.Quack() << std::endl;

    return 0;
}