#include "Device.h"

#include "Item.h"
#include "Phone.h"
#include "Laptop.h"

#include <iostream>

#include <set>

void set_find_integer();
void set_find_custom_object();
void set_find_polymorphic_instance();

int main() {
    set_find_integer();
    set_find_custom_object();
    set_find_polymorphic_instance();
    return 0;
}

void set_find_polymorphic_instance() {
    std::set<std::unique_ptr<Item>> items;
    items.insert(std::make_unique<Phone>("Edge"));
    items.emplace(std::make_unique<Phone>("Xperia"));
    items.insert(std::make_unique<Laptop>("Latitude"));
    items.emplace(std::make_unique<Laptop>("ProBook"));

    std::unique_ptr<Item> targetItem = std::make_unique<Phone>("Edge");
    auto targetItemIterator = items.find(targetItem);

    std::cout << "Is item '" << *targetItem << "' present? ";

    std::string result = "Yes";
    if (targetItemIterator == items.end() ) {
        result = "No";
    }
    std::cout << result <<'\n';

    targetItem = std::make_unique<Laptop>("Latitude");
    targetItemIterator = items.find(targetItem);

    std::cout << "Is item '" << *targetItem << "' present? ";

    result = "Yes";
    if (targetItemIterator == items.end() ) {
        result = "No";
    }
    std::cout << result <<'\n';

    targetItem = std::make_unique<Phone>("Latitude"); // intentionally mistaking the polymorphic type
    targetItemIterator = items.find(targetItem);

    std::cout << "Is item '" << *targetItem << "' present? ";

    result = "Yes";
    if (targetItemIterator == items.end() ) {
        result = "No";
    }
    std::cout << result <<'\n';
}

void set_find_custom_object() {
    std::set<std::unique_ptr<Device>> devices;
    devices.insert(std::make_unique<Device>(2));
    devices.insert(std::make_unique<Device>(0));
    devices.insert(std::make_unique<Device>(1));

    auto lookedUpDevice = std::make_unique<Device>(1);
    auto iteratorToLookedUpDevice = devices.find(lookedUpDevice);

    std::cout << "Is the device '" << *lookedUpDevice << "' present? ";

    std::string result = "Yes";
    if (iteratorToLookedUpDevice == devices.end() ) {
        result = "No";
    }
    std::cout << result <<'\n';
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
        anotherResult = "No";
    }
    std::cout << anotherResult <<'\n';
}
