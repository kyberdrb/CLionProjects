#include <iostream>
#include <memory>

// std::weak_ptr: Example: https://en.cppreference.com/w/cpp/memory/weak_ptr

std::weak_ptr<int> globalWeakPtr;

void observe() {
    std::cout << "use_count = " << globalWeakPtr.use_count() << std::endl;

    if (auto sharedPtr = globalWeakPtr.lock()) {
        std::cout << *sharedPtr << std::endl;
        return;
    }

    std::cout << "globalWeakPtr has expired" << std::endl;
}

int main() {
    {
        std::shared_ptr<int> shPtr = std::make_shared<int>(42);
        globalWeakPtr = shPtr;
        observe();
    }

    observe();

    return 0;
}
