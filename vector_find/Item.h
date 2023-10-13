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

private:
    std::string _name;
};

inline bool operator==(std::unique_ptr<Item>& item, const Item& anotherItem) {
    return item->getName() == anotherItem.getName();
}
