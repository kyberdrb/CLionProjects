//
// Created by laptop on 7/10/19.
//

#ifndef C___OOP_USER_H
#define C___OOP_USER_H


#include <string>

class User {
private:
    std::string name;
    std::string lastName;

public:
    User(const std::string &name, const std::string &lastName);

    virtual ~User();

    const std::string &getName() const;

    const std::string &getLastName() const;
};


#endif //C___OOP_USER_H
