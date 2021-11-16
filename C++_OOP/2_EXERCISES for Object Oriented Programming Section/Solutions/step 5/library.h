#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include "book.h"

class Library
{
    private:
        int currentAmountOfBooks;
        int maxAmountOfBooks;
        Book* books;
    public:
        void addBook(const Book&);
        Book& getBook(int);
        void showBooks();

        Library(int);
        ~Library();
};


#endif // LIBRARY_H_INCLUDED
