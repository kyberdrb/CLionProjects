#include <iostream>

using namespace std;

struct book
{
    string author;
    string title;
    int publicationYear;
};

void setBook(book&);
void showBook(book);

int main()
{
    book book1, book2, book3;

    setBook(book1);
    setBook(book2);
    setBook(book3);


    showBook(book1);
    showBook(book2);
    showBook(book3);
    return 0;
}

void setBook(book &bookToSet)
{
    cout << "Who is the author of the book: ";
    getline(cin, bookToSet.author);
    cout << "What is the title of the book: ";
    getline(cin, bookToSet.title);
    cout << "In what year was the book published: ";
    cin >> bookToSet.publicationYear;
    cin.ignore();
}
void showBook(book bookToShow)
{
    cout << endl << bookToShow.author <<  " " << bookToShow.title <<  " " << bookToShow.publicationYear << endl;
}
