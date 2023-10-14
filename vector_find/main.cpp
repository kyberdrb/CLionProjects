#include "Device.h"

#include "Item.h"
#include "Laptop.h"
#include "Phone.h"

#include <iostream>

#include <algorithm>
#include <vector>

void vector_find_integer();
void vector_find_custom_class();
void vector_find_polymorphic_class();

int main() {
    vector_find_integer();
    vector_find_custom_class();
    vector_find_polymorphic_class();
    return 0;
}

void vector_find_integer() {
    std::vector<uint32_t> numbers;

    numbers.emplace_back(2);
    numbers.emplace_back(0);
    numbers.emplace_back(0);
    numbers.emplace_back(1);

    // error: no matching function for call to 'find(std::vector<unsigned int>::iterator, std::vector<unsigned int>::iterator, int)'
    //  solved by including <algorithm>
    auto lookedUpNumberIterator = std::find(numbers.begin(), numbers.end(), 1);
    auto occurences = std::count(numbers.begin(), numbers.end(), 1);

    std::cout << "Is number " << 1 << " present? ";

    std::string result = "No";
    bool isNumberPresent = lookedUpNumberIterator != numbers.end();
    if (isNumberPresent) {
        result = "Yes";
    }

    std::cout << result << " " << occurences << " times" << '\n';

    uint32_t lookedForNumber = 0;
    //std::find(numbers.begin(), numbers.end(), lookedForNumber);
    isNumberPresent = std::find(numbers.begin(), numbers.end(), lookedForNumber) != numbers.end();
    occurences = std::count(numbers.begin(), numbers.end(), lookedForNumber);

    std::cout << "Is number " << lookedForNumber << " present? ";

    result = "No";
    if (isNumberPresent) {
        result = "Yes";
    }

    std::cout << result << " " << occurences << " times" << '\n';
}

void vector_find_custom_class() {
    std::vector<std::unique_ptr<Device>> devices;
    devices.emplace_back(std::make_unique<Device>(2));
    devices.emplace_back(std::make_unique<Device>(1));
    devices.emplace_back(std::make_unique<Device>(3));
    devices.emplace_back(std::make_unique<Device>(1));

    auto searchedDevice = std::make_unique<Device>(1);

    // if during compilation appears message
    //   error: no match for 'operator==' (operand types are 'std::unique_ptr<Device>' and 'const Device')
    //  overload 'operator=='
    auto foundDevice = std::find(devices.begin(), devices.end(), *searchedDevice);
    auto occurences = std::count(devices.begin(), devices.end(), *searchedDevice);

    bool isDeviceFound = foundDevice != devices.end();

    std::cout << "Is device " << *searchedDevice << " present? ";

    std::string result = "No";
    if (isDeviceFound) {
        result = "Yes";
    }

    std::cout << result << " " << occurences << " times" << '\n';

    std::sort(devices.begin(), devices.end());
}

void vector_find_polymorphic_class() {
    std::vector<std::unique_ptr<Item>> items;
    items.emplace_back(std::make_unique<Phone>("Edge"));
    items.emplace_back(std::make_unique<Phone>("Xperia"));
    items.emplace_back(std::make_unique<Laptop>("Latitude"));
    items.emplace_back(std::make_unique<Laptop>("ProBook"));

    std::unique_ptr<Item> searchedItem = std::make_unique<Phone>("Edge");
    auto searchedItemIterator = std::find(items.begin(), items.end(), *searchedItem);
    auto occurences = std::count(items.begin(), items.end(), *searchedItem);

    std::cout << "Is item '" << *searchedItem << "' present? ";

    std::string result = "No";
    if (searchedItemIterator != items.end()) {
        result = "Yes";
    }

    std::cout << result << " " << occurences << " times" << '\n';

    searchedItem = std::make_unique<Laptop>("Latitude");
    searchedItemIterator = std::find(items.begin(), items.end(), *searchedItem);
    occurences = std::count(items.begin(), items.end(), *searchedItem);

    std::cout << "Is item '" << *searchedItem << "' present? ";

    result = "No";
    if (searchedItemIterator != items.end()) {
        result = "Yes";
    }

    std::cout << result << " " << occurences << " times" << '\n';

    searchedItem = std::make_unique<Phone>("Latitude"); // intentionally mistaking the polymorphic type
    searchedItemIterator = std::find(items.begin(), items.end(), *searchedItem);
    occurences = std::count(items.begin(), items.end(), *searchedItem);

    std::cout << "Is item '" << *searchedItem << "' present? ";

    result = "No";
    if (searchedItemIterator != items.end()) {
        result = "Yes";
    }

    std::cout << result << " " << occurences << " times" << '\n';

    std::sort(items.begin(), items.end());
}
