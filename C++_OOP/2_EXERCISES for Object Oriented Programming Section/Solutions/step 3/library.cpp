#include "library.h"

void Library::addBook(Book book)
{
    if (currentAmountOfBooks < maxAmountOfBooks)
    {
        this->books[currentAmountOfBooks] = book;
        this->currentAmountOfBooks++;
    }
    else
    {

    }
}

Book Library::getBook(int position)
{
    if (position < maxAmountOfBooks)
    {
        return books[position];
    }
    else
    {
        return books[0];
    }
}

void Library::showBooks()
{
    for (int i = 0; i < currentAmountOfBooks; i++)
    {
        std::cout << "POSITION IN LIBRARY: " << i << "  ";
        std::cout << "Author: " << getBook(i).author << "  ";
        std::cout << "Title: " << getBook(i).title << "  ";
        std::cout << "Publication Year: " << getBook(i).publicationYear << std::endl;
    }
}

Library::Library(int maxAmountOfBooks)
{
    this->currentAmountOfBooks = 0;
    this->maxAmountOfBooks = maxAmountOfBooks;
    this->books = new Book[maxAmountOfBooks];
}

Library::~Library()
{
    delete[] books;
}
