#include "book.h"

int Book::numberOfBooks = 0;

std::string Book::getTitle() const
{
    return this->title;
}

std::string Book::getAuthor() const
{
    return this->author;
}

int Book::getPublicationYear() const
{
    return this->publicationYear;
}

int Book::getBookId() const
{
    return this->bookId;
}

Book::Book(const Book& bookToCopy)
{
    this->title = bookToCopy.getTitle();
    this->author = bookToCopy.getAuthor();
    this->publicationYear = bookToCopy.getPublicationYear();
    this->bookId = Book::numberOfBooks++;
}

Book::Book(std::string author, std::string title, int publicationYear)
{
    this->author = author;
    this->title = title;
    this->publicationYear = publicationYear;
    this->bookId = numberOfBooks++;
}

Book::Book()
{

}

Book::~Book()
{

}
