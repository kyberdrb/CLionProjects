//
// Created by laptop on 7/10/19.
//

#include <iostream>
#include "Borrower.h"
#include "Librarian.h"

Borrower::Borrower(
        const std::string &name,
        const std::string &lastName,
        uint_least8_t maxBorrowedBooks)
        :
        User(name, lastName),
        maxBorrowedBooks(maxBorrowedBooks)
{
    borrowedBooks = new Book[maxBorrowedBooks];
    currentAmountOfBorrowedBooks = 0;
}

Borrower::~Borrower() {
    delete[] borrowedBooks;
}

bool Borrower::returnBorrowedBook(uint_least64_t bookId, Library &library) {
    Book matchingBook;
    // Find book with matching bookId
    for (int bookIndex = 0; bookIndex < currentAmountOfBorrowedBooks; bookIndex++) {
        matchingBook = borrowedBooks[bookIndex];
        if (bookId == matchingBook.getId()) {
            break;
        }
    }

    // Remove the book from the borrowers list && reorder books
    Book returnedBook;
    for (int bookIndex = 0; bookIndex < currentAmountOfBorrowedBooks; bookIndex++) {
         returnedBook = borrowedBooks[bookIndex];
        if (bookId == returnedBook.getId()) {
            borrowedBooks[bookIndex]= borrowedBooks[currentAmountOfBorrowedBooks - 1];
            currentAmountOfBorrowedBooks--;

        }
    }

    library.addBook(returnedBook);

    return true;
}

void Borrower::showBorrowedBooks() {
    std::cout << "Borrower: " << this->getLastName() << ", " << this->getName() << std::endl;
    std::cout << "Borrowed books" << std::endl;

    for (int borrowedBookIndex = 0; borrowedBookIndex < currentAmountOfBorrowedBooks; borrowedBookIndex++) {
        std::cout << borrowedBooks[borrowedBookIndex].getId() << "; ";
        std::cout << borrowedBooks[borrowedBookIndex].getTitle() << "; ";
        std::cout << borrowedBooks[borrowedBookIndex].getAuthor() << "; ";
        std::cout << (unsigned) borrowedBooks[borrowedBookIndex].getPublicationYear() << std::endl;
    }




    std::cout << std::endl;
}

bool Borrower::borrowBook(Book borrowedBook) {
    borrowedBooks[currentAmountOfBorrowedBooks] = borrowedBook;
    currentAmountOfBorrowedBooks++;
    return true;
}
