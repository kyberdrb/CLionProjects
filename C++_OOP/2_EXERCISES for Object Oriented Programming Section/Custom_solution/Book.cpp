#include <iostream>
#include <utility>
#include "Book.h"

Book::Book() {
    this->title = "";
    this->author = "";
    this->publicationYear = 0;
}

Book::Book(
        uint_least64_t bookId,
        const std::string &title,
        const std::string &author,
        uint_fast8_t publicationYear)
        :
        bookId(bookId),
        title(title),
        author(author),
        publicationYear(publicationYear) {}

Book::Book(const Book &copiedBook) {
    this->bookId = copiedBook.bookId;
    this->title = copiedBook.title;
    this->author = copiedBook.author;
    this->publicationYear = copiedBook.publicationYear;
}

const Book& Book::operator=(const Book& sourceBook)
{
    Book tempBook(sourceBook);
    swap(tempBook);
    return *this;
}

void Book::swap(Book& other)
{
     std::swap(bookId, other.bookId);
     std::swap(title, other.title);
     std::swap(author, other.author);
     std::swap(publicationYear, other.publicationYear);
}

const std::string &Book::getTitle() const {
    return title;
}

const std::string &Book::getAuthor() const {
    return author;
}

uint_fast8_t Book::getPublicationYear() const {
    return publicationYear;
}

uint_least64_t Book::getId() {
    return bookId;
}
