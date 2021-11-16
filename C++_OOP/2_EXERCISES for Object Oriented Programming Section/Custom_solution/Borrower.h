//
// Created by laptop on 7/10/19.
//

#ifndef C___OOP_BORROWER_H
#define C___OOP_BORROWER_H


#include "User.h"
#include "Book.h"
#include "Library.h"

class Borrower : public User {
private:
    Book* borrowedBooks;
    uint_least8_t maxBorrowedBooks;
    uint_fast8_t currentAmountOfBorrowedBooks;

public:
    Borrower(
            const std::string &name,
            const std::string &lastName,
            uint_least8_t maxBorrowedBooks);

    Borrower (const Borrower&) = delete;

    Borrower& operator = (const Borrower&) = delete;

    virtual ~Borrower();

    bool borrowBook(Book borrowedBook);

    bool returnBorrowedBook(uint_least64_t bookId, Library &library);

    void showBorrowedBooks();
};

#endif //C___OOP_BORROWER_H
