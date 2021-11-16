#include "library.h"

void Library::addBook(Book book)
{
    this->books[0] = book;
}
Book Library::getBook(int position)
{
    return books[position];
}

Library::Library(int maxAmountOfBooks)
{
    this->maxAmountOfBooks = maxAmountOfBooks;
    this->books = new Book[maxAmountOfBooks];
}

Library::~Library()
{
    delete[] books;
}
