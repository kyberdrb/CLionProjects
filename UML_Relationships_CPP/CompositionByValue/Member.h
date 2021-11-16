#pragma once

struct Member {
    int number;
    double otherNumber;

    Member(int number, double otherNumber) :
        number(number), otherNumber(otherNumber)
    {}

    Member(const Member& source) :
        Member(source.number, source.otherNumber)
    {
        if (&source == this) return;

        std::cout << "Member: Copy constructor" << std::endl;
    }

    Member& operator=(const Member& source) {
        std::cout << "Member: Copy assignment operator" << std::endl;
        if (&source == this) return *this;

        this->number = source.number;
        this->otherNumber = source.otherNumber;

        return *this;
    }

    Member(Member&& source) :
        number(source.number),
        otherNumber(source.otherNumber)
    {
        std::cout << "Member: Move constructor" << std::endl;
        source.number = 0;
        source.otherNumber = 0;
    }

    Member& operator=(Member&& source) {
        std::cout << "Member: Move assignment operator" << std::endl;

        this->number = source.number;
        this->otherNumber = source.otherNumber;

        source.number = 0;
        source.otherNumber = 0;

        return *this;
    }

    //Member createMember() {
    //    return Member(0, 0);
    //}

    ~Member() {
        std::cout << "Member: Destructor" << std::endl;
    }
};
