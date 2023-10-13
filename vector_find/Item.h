//
// Created by laptop on 10/12/23.
//

#pragma once

#include <string>

class Item {
public:
    explicit Item(std::string name) :
        _name(std::move(name))
    {}

    virtual void use() = 0;

    virtual std::string getName() const {
        return this->_name;
    }

    friend std::ostream& operator<<(std::ostream& out, const Item& item);
    friend bool operator<(const std::unique_ptr<Item>& item, const std::unique_ptr<Item>& anotherItem);

private:
    std::string _name;
};

inline bool operator==(std::unique_ptr<Item>& item, const Item& anotherItem) {
    return item->getName() == anotherItem.getName();
}

std::ostream& operator<<(std::ostream& out, const Item& item) {
    out << item._name;
    return out;
}

bool operator<(const std::unique_ptr<Item>& item, const std::unique_ptr<Item>& anotherItem) {
    return item->_name < anotherItem->_name;
}