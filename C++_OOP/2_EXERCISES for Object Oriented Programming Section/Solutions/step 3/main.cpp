#include <iostream>
#include "library.h"
#include "book.h"

using namespace std;


int main()
{

    Book book1, book2, book3;

    Library library(5);

    book1.author = "Arkadiusz Wlodarczyk";
    book1.title = "C++ course";
    book1.publicationYear = 2009;

    book2.author = "Wioletta Kozik";
    book2.title = "JAVA course";
    book2.publicationYear = 2016;

    book3.author = "Adrian Szuszkiewicz";
    book3.title = "C# course";
    book3.publicationYear = 2002;

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    library.showBooks();


    return 0;
}
