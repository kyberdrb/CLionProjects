#ifndef BOOK_H_INCLUDED
#define BOOK_H_INCLUDED

#include <iostream>

class Book
{
    private:
        std::string title;
        std::string author;
        int publicationYear;
        int bookId;
    public:
        static int numberOfBooks;
        std::string getTitle() const;
        std::string getAuthor() const;
        int getPublicationYear() const;
        int getBookId() const;

        Book(std::string, std::string, int);
        Book();
        ~Book();
};


#endif // BOOK_H_INCLUDED
