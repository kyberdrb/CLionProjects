#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include "book.h"

class Library
{
    private:
        Book books[5];
    public:
        void addBook(Book);
        Book getBook(int);


};


#endif // LIBRARY_H_INCLUDED
