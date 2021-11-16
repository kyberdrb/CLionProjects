#ifndef C___OOP_LIBRARIAN_H
#define C___OOP_LIBRARIAN_H


#include "Book.h"
#include "Library.h"
#include "Borrower.h"

class Librarian : public Borrower {
public:
    Librarian(
            const std::string &name,
            const std::string &lastName,
            uint_least8_t maxBorrowedBooks,
            Library& library);

    virtual ~Librarian();

    bool lendBook(uint_least64_t bookId, Borrower& borrower);

    bool acceptReturnedBook(Book returnedBook);

private:
    Library& library;
};


#endif //C___OOP_LIBRARIAN_H
