#include <iostream>
#include "library.h"
#include "book.h"

using namespace std;


int main()
{

    const Book book1("Arkadiusz Wlodarczyk", "C++ course", 2009);
    const Book book2("Wioletta Kozik", "JAVA course", 2016);
    const Book book3("Adrian Szuszkiewicz", "C# course", 2002);

    Library library(5);

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);

    library.showBooks();


    return 0;
}
