#include <iostream>

#include "Device.h"

#include "Item.h"
#include "Phone.h"

#include <algorithm>
#include <cstdint>
#include <memory>
#include <vector>

void vector_find_integer();
void vector_find_custom_class();

int main() {
    vector_find_integer();
    vector_find_custom_class();

    std::vector<std::unique_ptr<Item>> items;
    items.emplace_back(std::make_unique<Phone>("Edge"));
    items.emplace_back(std::make_unique<Phone>("Xperia"));
    items.emplace_back(std::make_unique<Phone>("Latitude"));
    items.emplace_back(std::make_unique<Phone>("ProBook"));

    std::unique_ptr<Item> searchedItem = std::make_unique<Phone>("Edge");
    auto itemReturnedFromSearch = std::find(items.begin(), items.end(), *searchedItem);
    // TODO occurences

    // TODO evaluation
    if (itemReturnedFromSearch != items.end()) {

    }

    // TODO sort + overloading less-than-operator

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
    //std::find(numbers.begin(), numbers.end(), 1);

    uint32_t lookedForNumber = 0;
    //std::find(numbers.begin(), numbers.end(), lookedForNumber);
    bool isNumberPresent = std::find(numbers.begin(), numbers.end(), lookedForNumber) != numbers.end();
    auto occurences = std::count(numbers.begin(), numbers.end(), lookedForNumber);

    std::cout << "Is number " << lookedForNumber << " present? ";

    std::string result = "No";
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
    std::cout << isDeviceFound << '\n';

    std::cout << "Is device " << *searchedDevice << " present? ";

    std::string result = "No";
    if (isDeviceFound) {
        result = "Yes";
    }

    std::cout << result << " " << occurences << " times" << '\n';

    std::sort(devices.begin(), devices.end());
}
