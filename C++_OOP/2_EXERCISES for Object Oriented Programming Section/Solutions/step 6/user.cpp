#include "user.h"

#include "library.h"

std::string User::getName()
{
    return this->name;
}

std::string User::getLastName()
{
    return this->lastName;
}

User::User(std::string name, std::string lastName)
{
    this->name = name;
    this->lastName = lastName;
}

Borrower::Borrower(std::string name, std::string lastName, int maxAmountOfBooks)
        : User (name, lastName)
{
    this->userAmountOfBooks = 0;
    this->maxAmountOfBooks = maxAmountOfBooks;
    booksInPossesion = new Book[maxAmountOfBooks];
}

Borrower::~Borrower()
{
    delete[] booksInPossesion;
}

void Borrower::returnBook(Library& libraryToReturnTo, int position)
{
    if (position < this->userAmountOfBooks && this->userAmountOfBooks > 0)
    {
        libraryToReturnTo.addBook(booksInPossesion[position]);

        for(int i = 0; i < maxAmountOfBooks-1; i++)
        {
            if (i >= position)
                booksInPossesion[i] = booksInPossesion[i+1];
        }
        this->userAmountOfBooks--;
    }
    else
    {
    }
}

Book& Borrower::getBook(int position)
{
    if (position < this->userAmountOfBooks)
    {
        return booksInPossesion[position];
    }
    else
    {
        return booksInPossesion[0];
    }
}

void Borrower::showBooks()
{
    std::cout << getName() << " " << getLastName() << " BOOKS: " << std::endl;
    for (int i = 0; i < userAmountOfBooks; i++)
    {
        std::cout << "BOOK ID: " << getBook(i).getBookId() << "  ";
        std::cout << "POSITION IN USER: " << i << "  ";
        std::cout << "Author: " << getBook(i).getAuthor() << "  ";
        std::cout << "Title: " << getBook(i).getTitle() << "  ";
        std::cout << "Publication Year: " << getBook(i).getPublicationYear() << std::endl;
    }
    std::cout << std::endl;
}

Librarian::Librarian(std::string name, std::string lastName, int maxAmountOfBooks)
        : Borrower(name, lastName, maxAmountOfBooks)
    {}

void Librarian::lendBook(Library& libraryToLendFrom, Borrower& personToLendTo, int position)
{
    if (libraryToLendFrom.currentAmountOfBooks > 0)
    {
        if (personToLendTo.userAmountOfBooks < personToLendTo.maxAmountOfBooks && position < libraryToLendFrom.currentAmountOfBooks)
        {
            personToLendTo.booksInPossesion[personToLendTo.userAmountOfBooks] = libraryToLendFrom.books[position];

            for(int i = 0; i < libraryToLendFrom.maxAmountOfBooks-1; i++)
            {
                if (i >= position)
                    libraryToLendFrom.books[i] = libraryToLendFrom.books[i+1];
            }

            libraryToLendFrom.currentAmountOfBooks--;
            personToLendTo.userAmountOfBooks++;
        }
        else
        {
        }
    }
    else
    {
    }
}


