#include "library.h"

void Library::addBook(Book book)
{
    this->books[0] = book;
}
Book Library::getBook(int index)
{
    return books[index];
}
