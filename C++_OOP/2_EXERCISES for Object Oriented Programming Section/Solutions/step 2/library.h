#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include "book.h"

class Library
{
    private:
        int maxAmountOfBooks;
        Book* books;
    public:
        void addBook(Book);
        Book getBook(int);

        Library(int);
        ~Library();

};


#endif // LIBRARY_H_INCLUDED
