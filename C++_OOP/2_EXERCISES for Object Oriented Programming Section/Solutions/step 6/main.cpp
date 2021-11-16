#include <iostream>
#include <conio.h>
#include <cstdlib>
#include "library.h"
#include "book.h"
#include "user.h"

using namespace std;


int main()
{
    const Book book1("Arkadiusz Wlodarczyk", "C++ course", 2009);
    const Book book2("Wioletta Kozik", "JAVA course", 2016);
    const Book book3("Adrian Szuszkiewicz", "C# course", 2002);
    const Book book4 = book3;
    const Book book5 = book3;
    const Book book6 = book3;

    Library library(5);
    Librarian librarian("Foo", "Bar", 5);
    Borrower borrower("Edek", "Czytacz", 5);

    library.addBook(book1);
    library.addBook(book2);
    library.addBook(book3);
    library.addBook(book4);
    library.addBook(book6);

    int position;
    char choice;

    while (true)
    {
        library.showBooks();
        borrower.showBooks();
        cout << "Would you like to Borrow - B/b or Return - R/r: ";
		cin >> choice;

        switch(choice)
        {
        case 'b':
        case 'B':
            {
                cout << "Which book would you like to rent, POSITION IN LIBRARY: ";
                cin >> position;
                librarian.lendBook(library, borrower, position);
                break;
            }
        case 'r':
        case 'R':
            {
                cout << "Which book would you like to return, POSITION IN USER: ";
                cin >> position;
                borrower.returnBook(library, position);
                break;
            }
		default:
			break;
        }
        system("cls");
    }
    return 0;
}
