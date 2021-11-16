#ifndef C___OOP_LIBRARY_H
#define C___OOP_LIBRARY_H

#include "Book.h"

class Library {
private:
    Book* books;
    uint32_t maxAmountOfBooks;
    uint_fast32_t currentAmountOfBooks;

public:
    Library(uint32_t maxAmountOfBooks);

    ~Library();

    bool addBook(const Book &book);

    Book& getBook(uint32_t bookIndex) const;

    Book removeBookAsIf(uint32_t bookId);

    void showBooks();
};

#endif //C___OOP_LIBRARY_H
