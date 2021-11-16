#include <iostream>
#include "EXERCISES_for_Object_Oriented_Programming_Section.h"
#include "Custom_solution/Book.h"
#include "Custom_solution/Library.h"
#include "Custom_solution/Librarian.h"

void EXERCISES_for_Object_Oriented_Programming_Section::startExercise() {
    const Book* book = new Book(0, "A", "B", 11);
    const Book* book_2 = new Book(10, "C", "D", 22);
    const Book* book_3 = new Book(20, "E", "F", 33);
//    const Book* book_4 = new Book(*book_3);
//    const Book* book_5 = new Book(*book_3);
    const Book* book_4 = new Book(30, "G", "H", 44);
    const Book* book_5 = new Book(40, "I", "J", 55);

    uint32_t maxAmountOfBooks = 5;
    Library* library = new Library(maxAmountOfBooks);
    library->addBook(*book);
    library->addBook(*book_2);
    library->addBook(*book_3);
    library->addBook(*book_4);
    library->addBook(*book_5);

    library->showBooks();

    Borrower* borrower_1 = new Borrower("John", "Doe", 3);
    Librarian* librarian = new Librarian("Sam", "Smith", 6, *library);

    borrower_1->showBorrowedBooks();

    librarian->lendBook(10, *borrower_1);
    borrower_1->showBorrowedBooks();
    library->showBooks();

    librarian->lendBook(20, *borrower_1);
    borrower_1->showBorrowedBooks();
    library->showBooks();

    borrower_1->returnBorrowedBook(10, *library);
    borrower_1->showBorrowedBooks();
    library->showBooks();

    borrower_1->returnBorrowedBook(20, *library);
    borrower_1->showBorrowedBooks();
    library->showBooks();

    delete book;
    delete book_2;
    delete book_3;
    delete book_4;
    delete book_5;

    delete borrower_1;
    delete librarian;

    delete library;
}
