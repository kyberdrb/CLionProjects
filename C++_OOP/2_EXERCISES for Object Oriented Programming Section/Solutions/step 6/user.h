#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <string>
#include "book.h"

class Library;

class User
{
protected:
    std::string name;
    std::string lastName;

public:
    std::string getName();
    std::string getLastName();
    User(std::string, std::string);
};

class Borrower: public User
{
protected:
    friend class Librarian;
    int userAmountOfBooks;
    int maxAmountOfBooks;
    Book* booksInPossesion;

public:
    Borrower(std::string, std::string, int);

    ~Borrower();
    Borrower(const Borrower&) = delete;
    Borrower& operator= (const Borrower&) = delete;

    void returnBook(Library&, int);
    Book& getBook(int id);
    void showBooks();
};

class Librarian: public Borrower
{

public:
    Librarian(std::string, std::string, int);
    void lendBook(Library&, Borrower&, int);
};


#endif // USER_H_INCLUDED
