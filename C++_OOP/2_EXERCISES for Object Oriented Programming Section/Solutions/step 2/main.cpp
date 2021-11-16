#include <iostream>
#include "library.h"
#include "book.h"

using namespace std;


int main()
{

    Book book1;

    Library library(5);


    book1.author = "Arkadiusz Wlodarczyk";
    book1.title = "C++ course";
    book1.publicationYear = 2009;

    library.addBook(book1);

    cout << "Author: " << library.getBook(0).author << "  ";
    cout << "Title: " << library.getBook(0).title << "  ";
    cout << "Publication Year: " << library.getBook(0).publicationYear << endl;


    return 0;
}
