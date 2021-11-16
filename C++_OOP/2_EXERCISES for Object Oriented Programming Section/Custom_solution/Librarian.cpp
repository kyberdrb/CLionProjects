//
// Created by laptop on 7/10/19.
//

#include "Librarian.h"

Librarian::Librarian(
        const std::string &name,
        const std::string &lastName,
        uint_least8_t maxBorrowedBooks,
        Library &library)
        :
        Borrower(
                name,
                lastName,
                maxBorrowedBooks),
        library(library)
        {}

Librarian::~Librarian() {

}

bool Librarian::lendBook(uint_least64_t bookId, Borrower& borrower) {
    Book lentBook = library.removeBookAsIf(bookId);
    borrower.borrowBook(lentBook);
    return true;
}

bool Librarian::acceptReturnedBook(Book returnedBook) {
    library.addBook(returnedBook);
    return true;
}
