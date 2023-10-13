#include <iostream>

#include <cstdint>
#include <set>

void set_find_integer();

int main() {
    set_find_integer();

    //set_find_custom_object

    return 0;
}

void set_find_integer() {
    std::set<uint32_t> numbers;
    numbers.emplace(2);
    numbers.emplace(1);
    numbers.emplace(3);
    numbers.emplace(0);

    auto lookedUpNumberIterator = numbers.find(1);

    std::cout << "Is the number present? ";

    std::string result = "Yes";
    if (lookedUpNumberIterator == numbers.end() ) {
        result = "No";
    }
    std::cout << result << '\n';

    uint32_t searchedNumber = 1;
    auto searchedNumberIterator = numbers.find(searchedNumber);

    std::cout << "Is the number " << searchedNumber << " present? ";

    std::string anotherResult = "Yes";
    if (lookedUpNumberIterator == numbers.end() ) {
        result = "No";
    }
    std::cout << anotherResult <<'\n';
}
