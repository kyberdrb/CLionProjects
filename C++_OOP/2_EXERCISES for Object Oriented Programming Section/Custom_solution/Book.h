#ifndef C___OOP_BOOK_H
#define C___OOP_BOOK_H


#include <string>

class Book {
private:
    std::string title;
    std::string author;
    uint_fast8_t publicationYear;
    uint_least64_t bookId;

public:
    Book();

    Book(
            uint_least64_t bookId,
            const std::string &title,
            const std::string &author,
            uint_fast8_t publicationYear);

    Book(const Book& copiedBook);

    const Book& operator=(const Book& sourceBook);

    const std::string &getTitle() const;

    const std::string &getAuthor() const;

    uint_fast8_t getPublicationYear() const;

    uint_least64_t getId();

private:
    void swap(Book& other);

};


#endif //C___OOP_BOOK_H
