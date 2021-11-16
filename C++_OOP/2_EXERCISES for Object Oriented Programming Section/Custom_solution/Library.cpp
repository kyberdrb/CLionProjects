//
// Created by laptop on 7/6/19.
//

#include <iostream>
#include "Library.h"

Library::Library(uint32_t maxAmountOfBooks)
        :
        maxAmountOfBooks(maxAmountOfBooks),
        currentAmountOfBooks(0)
{
    books = new Book[this->maxAmountOfBooks];
}

Library::~Library() {
    delete[] books;
}

bool Library::addBook(const Book &book) {
    if (currentAmountOfBooks < maxAmountOfBooks) {
        books[currentAmountOfBooks] = book;
        currentAmountOfBooks++;
        return true;
    }
    return false;
}

Book &Library::getBook(uint32_t bookIndex) const {
    if (currentAmountOfBooks <= maxAmountOfBooks) {
        return books[bookIndex];
    }
    return books[0];
}

void Library::showBooks() {
    std::cout << "Book ID; Title; Author; Publication year" << std::endl;

    for (int bookIndex = 0; bookIndex < currentAmountOfBooks; bookIndex++) {
        std::cout << getBook(bookIndex).getId() << "; ";
        std::cout << getBook(bookIndex).getTitle() << "; ";
        std::cout << getBook(bookIndex).getAuthor() << "; ";
        std::cout << (unsigned) getBook(bookIndex).getPublicationYear() << std::endl;
    }

    std::cout << std::endl;
}

Book Library::removeBookAsIf(uint32_t bookId) {
    Book currentBook;
    for (int bookIndex = 0; bookIndex < currentAmountOfBooks; bookIndex++) {
        currentBook = getBook(bookIndex);
        if (bookId == currentBook.getId()) {
            // For assigning one element to another
            //  it's needed to overload the assignment operator
            //  copy constructor (optional)
            books[bookIndex] = books[currentAmountOfBooks - 1];
            currentAmountOfBooks--;
            return currentBook;
        }
    }
    throw std::out_of_range("bookID_not_found");
}

