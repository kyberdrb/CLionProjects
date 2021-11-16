#include <iostream>
#include <memory>

// https://www.fluentcpp.com/2017/09/05/changing-deleters-during-the-life-of-a-unique_ptr/

void deleteEvenNumber(int* number) {
    std::cout << "Deleting even number " << *number << std::endl;
    delete number;
}

void deleteOddNumber(int* number) {
    std::cout << "Deleting odd number " << *number << std::endl;
    delete number;
}

void useCustomDeleterForUniquePtr() {
    using IntDeleter = void(*)(int*);
    using IntUniquePtr = std::unique_ptr<int, IntDeleter>;

    IntUniquePtr p1(new int(42), deleteEvenNumber);
    IntUniquePtr p2(new int(43), deleteOddNumber);

    std::cout << "value of p1\t" << *p1 << std::endl;
    std::cout << "value of p2\t" << *p2 << std::endl;
    std::cout << std::endl;

    std::cout << "Moving p2 into p1 ..." << std::endl;
    p1 = std::move(p2);

    std::cout << "value of p1\t" << *p1 << std::endl;
}

void resetUniquePtrWithoutCustomDeleter() {
    std::cout << "Resetting the unique_ptr ..." << std::endl;

    std::unique_ptr<int> p1(new int(44));
    std::cout << "value of p3\t" << *p1 << std::endl;

    p1.reset(new int(45));
    std::cout << "value of p3 after reset\t" << *p1 << std::endl;
}

void resetUniquePtrWithCustomDeleterWithTheSameDeleter() {
    std::cout << "Resetting the unique_ptr with original deleter ..." << std::endl;

    using IntDeleter = void(*)(int*);
    using IntUniquePtr = std::unique_ptr<int, IntDeleter>;

    IntUniquePtr p1(new int(42), deleteEvenNumber);
    p1.reset(new int(43));
}

void resetUniquePtrWithCustomDeleterWithChangedDeleter() {
    std::cout << "Resetting the unique_ptr with changed deleter ..." << std::endl;

    using IntDeleter = void(*)(int*);
    using IntUniquePtr = std::unique_ptr<int, IntDeleter>;

    IntUniquePtr p1(new int(42), deleteEvenNumber);
    p1 = IntUniquePtr(new int(43), deleteOddNumber);
}

int main() {
    useCustomDeleterForUniquePtr();
    std::cout << std::endl;

    resetUniquePtrWithoutCustomDeleter();
    std::cout << std::endl;

    resetUniquePtrWithCustomDeleterWithTheSameDeleter();
    std::cout << std::endl;

    resetUniquePtrWithCustomDeleterWithChangedDeleter();
    std::cout << std::endl;

    return 0;
}