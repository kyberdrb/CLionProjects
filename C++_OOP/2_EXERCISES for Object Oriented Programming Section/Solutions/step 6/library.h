#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include "book.h"
#include "user.h"

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

        friend void Librarian::lendBook(Library&, Borrower&, int);

        Library(int);
        ~Library();
};


#endif // LIBRARY_H_INCLUDED
