//
// Created by laptop on 7/6/19.
//

#include "EXERCISE_for_Data_Structures_and_Pointers.h"

#include <iostream>
#include <cstdint>
#include <cassert>

struct Book{
    std::string title;
    std::string author;
    uint_fast8_t publicationYear;
};

const uint32_t AMOUNT_OF_BOOKS = 1;

void printBooks(Book* const);

void loadBookData(Book* const book);

void EXERCISE_for_Data_Structures_and_Pointers::startExercise() {
    Book* const books = new Book[AMOUNT_OF_BOOKS];

    loadBookData(books);
    printBooks(books);

    delete []books;
}

void loadBookData(Book* const books) {
    for (int bookIndex = 0; bookIndex < AMOUNT_OF_BOOKS; bookIndex++) {
        std::cout << "Enter book's title:" << std::endl;
        std::cin >> books[bookIndex].title;

        std::cout << "Enter book's author:" << std::endl;
        std::cin >> books[bookIndex].author;

        std::cout << "Enter book's publication year:" << std::endl;
        std::cin >> books[bookIndex].publicationYear;
    }
}

void printBooks(Book* const books) {
    for (int bookIndex = 0; bookIndex < AMOUNT_OF_BOOKS; bookIndex++) {
        std::cout <<
                  books[bookIndex].title << "; " <<
                  books->author << "; " <<
                  books->publicationYear << std::endl;
    }

}

