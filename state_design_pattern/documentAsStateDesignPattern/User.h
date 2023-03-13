//
// Created by AndrejŠišila on 3/9/2023.
//

#pragma once

#include <string>

class User {
public:
    std::string role;

    friend std::ostream& operator<<(std::ostream& out, const User& user);
};

inline std::ostream& operator<<(std::ostream& out, const User& user) {
    out << user.role;
    return out;
}
