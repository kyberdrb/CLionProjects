//
// Created by laptop on 10/14/23.
//

#pragma once

#include <string>
#include <ostream>

class Item {
public:
    explicit Item(std::string name) :
        _name(std::move(name))
    {}

    friend bool operator<(const std::unique_ptr<Item>& oneItem, const std::unique_ptr<Item>& anotherItem);
    friend std::ostream& operator<<(std::ostream& out, const Item& item);

    virtual ~Item() = default;

private:
    std::string _name;
};

inline bool operator<(const std::unique_ptr<Item>& oneItem, const std::unique_ptr<Item>& anotherItem) {
    return oneItem->_name < anotherItem->_name;
}

inline std::ostream& operator<<(std::ostream& out, const Item& item) {
    out << item._name;
    return out;
}
