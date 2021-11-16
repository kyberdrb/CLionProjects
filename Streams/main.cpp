#include <iostream>

using namespace std;

int main_57();
int main_58();
int main_59_60();
int main_60();
int main_61();
int main_62();
int main_63();
int main_64();
int main_65();
int main_66();
int main_67();
int main_68();
int main_69();
void writing_text_files();
void reading_text_files();
void parsing_text_files();
void parseLineElements(stringstream &lineStream);
void parseLine(ifstream &input);
void structs_and_padding();
void savePerson(const string &fileName);

int main()
{
//    main_57();
//    main_58();
//    main_59_60();
//    main_60();
//    main_61();
//    main_62();
//    main_63();
//    main_64();
//    main_65();
//    main_66();
//    main_67();
//    main_68();
//    main_69();

//    writing_text_files();
//    reading_text_files();
//    parsing_text_files();
    structs_and_padding();

    return 0;
}

// 57_SOURCE-Streams-what-is-input-and-output

// TOPIC: STREAM
// PUT IN from a keyboard - source (entrance)
// PUT OUT to the file - destination (exit)
int main_57()
{

    int a;

    cin >> a;

    cout << a;
    return 0;
}

// 58_C-SOURCE-CODE-for-How-to-open-and-close-files
#include <iostream>
#include <fstream>
#include <cstring>

int main_58()
{
    fstream myFileHandler;

    // File is created in path "cmake-build-debug/test.txt"
    myFileHandler.open("test.txt", ios::out);

    // try-catch doesn't catch the case when the file doesn't exist
    cerr << "Error " << errno << ": " << strerror(errno);

    if (myFileHandler.is_open()) {
        std::cout << "File opened properly" << std::endl;
        myFileHandler << "a line of text";
        myFileHandler.close();
    }

    return 0;
}

// 59_60_C-SOURCE-CODE-for-File-opening-modes
#include <iostream>
#include <fstream>



int main_59_60()
{
    fstream file;

    file.open("sample.txt", ios::app);

    /*
        ios::in - INPUT - READING
        ios::out - OUTPUT - WRITE TO FILE, if there is no file then create it, if there is a file then truncate it (remove content) unless it occurs with ios::in flag
        ios::trunc - TRUNCATE - it is truncating the file (cutting everything inside)
        ios::ate - At The End - sets pointer at the end of file - the place of pointer can be changed in that mode, it's possible to read and write in that mode
        ios::app - Append - the content is added at the end of file (it's not possible to remove content nor adding something in other place than the end of file)
        ios::binary - opens the file as a binary file

    */

    /*
        DEFAULT MODE (FLAGS)
        fstream - ios::out | ios::in
        ifstream - ios::in
        ofstream - ios::out
    */


    if (file.is_open())
    {
        file << "sample text\n";
        file << "sample text\n";

    }
    else
        cout << "The file hasn't been opened properly";


    return 0;
}

// 61_C-SOURCE-CODE-for-Reading-Position-Pointer
#include <iostream>
#include <fstream>



int main_61()
{
    /*
        tellg - tell get - tell where is the reading pointer
        seekg - seek get - set reading pointer at specified position


        seekg(how_many_bytes_from_the_flag_place, flag);

        possible flags:
        ios::beg - (begin) set from the begin (default)
        ios::end - set from the end
        ios::cur - (current) set from current place
    */

    fstream file;

    file.open("sample.txt", ios::in | ios::binary);

    if (file.is_open())
    {
        string buffer;

        file.seekg(0, ios::end);

        streampos sizeOfFile = file.tellg();

        file.seekg(0);

        cout << "The size of the file is " << sizeOfFile << " bytes" << endl;
        do
        {
            file >> buffer;

            cout << buffer << endl;
        }while (!file.eof());

        if ((file.rdstate() ^ ifstream::eofbit) == 0)
        {
            file.clear();
            cout << file.tellg() << endl;
            file >> buffer;

            cout << buffer << endl;
            //set indicator of place in file to some other place
            // some other operations on file
        }

    }
    else
        cout << "The file couldn't be opened properly" << endl;

    return 0;
}

// 62_C-SOURCE-CODE-for-writing-position-pointer
#include <iostream>
#include <fstream>



int main_62()
{
    /*
        tellp - tell put - tells where is the putting pointer
        seekp - seek put - sets writing (putting) pointer at specified position


        seekp(how_many_bytes_from_the_flag_place, flag);

        possible flags:
        ios::beg - (begin) set from the begin (default)
        ios::end - set from the end
        ios::cur - (current) set from current place
    */

    fstream file;

    file.open("sample.txt", ios::out | ios::binary);

    if (file.is_open())
    {
        string tmp = "this is text about nothing";

        file << tmp;

        cout << file.tellp() << endl;

        file.seekp(0, ios::beg);

        file << "T";
    }
    else
        cout << "The file couldn't be opened properly" << endl;

    return 0;
}
#include <iostream>
#include <fstream>


// 63_SOURCE-CODE-for-Extracting-characters-from-files
int main_63()
{
    /*
        getline(where to store the extracted characters, how many characters should be taken unlles, seperator(delimiter)) - extracts seperators and delete it
        get(where to store the extracted characters, how many characters should be taken unlles, seperator(delimiter)) - doesn't extract seperator
        ignore(how_many_characters_to_extracte AND TO IGNORE THEM, seperator) - extracts characters

        get();
    */

    fstream file;

    file.open("sample.txt", ios::in | ios::binary);

    if (file.is_open())
    {
        char first, second;
        char buffer[50];

        cin >> buffer;

        cout << buffer << endl;
        do
        {
            file.getline(buffer, 50, ' ');

            second = file.get();

            file.ignore(40, '\n');

            cout << buffer << " " << second << ". " << endl;

        } while(!file.eof());



    }
    else
        cout << "The file couldn't be opened properly" << endl;

    return 0;
}

// 64_SOURCE-CODE-for-Comparing-content-of-two-files
#include <iostream>
#include <fstream>
#include "string.h"



bool areFilesEqual(fstream *, fstream *);
int sizeOfFile(fstream *);

int main_64()
{
    /*
        read(where to read, how many bytes to read);
        memcmp it stands memory compare
    */

    fstream file1, file2;

    file1.open("sample.txt", ios::in | ios::binary | ios::ate);
    file2.open("sample2.txt", ios::in | ios::binary | ios::ate);

    if (file1.is_open() && file2.is_open())
    {
        if (areFilesEqual(&file1, &file2))
        {
            cout << "Files are equal";
        }
        else
            cout << "Files are not the same" << endl;

    }
    else
        cout << "The file couldn't be opened properly" << endl;

    return 0;
}
bool areFilesEqual(fstream *a, fstream *b)
{
    int fileSize1 = sizeOfFile(a);
    int fileSize2 = sizeOfFile(b);

    if (fileSize1 == fileSize2)
    {
        int BUFFER_SIZE;

        if(fileSize1 > 1024)
            BUFFER_SIZE = 1024;
        else
            BUFFER_SIZE = fileSize1;

        char *file1buffer = new char[BUFFER_SIZE];
        char *file2buffer = new char[BUFFER_SIZE];

        do
        {
            a->read(file1buffer, BUFFER_SIZE);
            b->read(file2buffer, BUFFER_SIZE);

            if (memcmp(file1buffer, file2buffer, BUFFER_SIZE) != 0)
            {
                cout << "Files are not equal, at least one of the byte was different" << endl;

                delete [] file1buffer;
                delete [] file2buffer;
                return false;
            }
        }while(a->good() && b->good());

        delete [] file1buffer;
        delete [] file2buffer;
        return true;
    }
    else
    {
        cout << "Size of Files are not equal" << endl;
        return false;
    }
}
int sizeOfFile(fstream * file)
{
    file->seekg(0, ios::end);
    int sizeOfFile = file->tellg();
    file->seekg(0, ios::beg);
    return sizeOfFile;
}

// 65_SOURCE-CODE-for-PUT
#include <iostream>
#include <fstream>



int main_65()
{
    /*
        put(character to put on stream)
    */

    string txt = "thistextisconnected";


 /*   for (int i = 0; i < txt.length(); i++)
    {
        cout.put(txt[i]).put(' ');
    }
*/
    fstream file;

    file.open("test.txt", ios::out | ios::binary);
    if (file.is_open())
    {
        char c;
        do
        {
            c = cin.get();

            file.put(c);
        }while(c!='.');
    }
    else
        cout << "Nie udalo sie poprawnie otworzyc pliku" << endl;


    return 0;
}

// 66_SOURCE-CODE-for-PEEK
#include <iostream>

int main_66()
{
    char c = cin.peek();


    if (c > '0' && c < '9')
    {
        int number;

        cin >> number;

        cout << "Number is: " << number << endl;
    }
    else
    {
        string txt;

        cin >> txt;

        cout << "Text is: " << txt << endl;
    }

    return 0;
}

// 67_SOURCE-CODE-FOR-PUTBACK
#include <iostream>

//putback

int main_67()
{
    char c = cin.get();

    cin.putback(c);
    if (c > '0' && c < '9')
    {
        int number;

        cin >> number;

        cout << "Number is: " << number << endl;
    }
    else
    {
        string txt;

        cin >> txt;

        cout << "Text is: " << txt << endl;
    }

    return 0;
}
#include <iostream>
#include <fstream>


// 68_SOURCE-CODE-FOR-WRITE
int main_68()
{
    /*
        write
    */

    fstream file;

    file.open("sample.txt", ios::out | ios::binary);

    if (file.is_open())
    {
        char sample[] = "sample text";

        cout << sizeof(sample) << endl;

        file.write(sample, 60);
    }
    else
        cout << "I couldnt open the file" << endl;



    return 0;
}

// 69_SOURCE-CODE-FOR-GCOUNT
#include <iostream>
#include <fstream>



int main_69()
{
    /*
        gcount - Getcharacter Count - get count of extracted characters from last extraction operation
    */

    fstream file;

    file.open("sample.txt", ios::in | ios::binary);

    if (file.is_open())
    {
        char buffer[250];
        do
        {
            file.getline(buffer, 250);

            cout << buffer << " " << file.gcount() << endl;
        }while(!file.eof());
    }
    else
        cout << "The file couldn't be opened properly" << endl;

    return 0;
}

#include <fstream>
#include <sstream>

void writing_text_files() {
    std::string outputFileName = "text.txt";

//    ofstream outFile;
//    outFile.open(outputFileName);

    fstream outFile;
    outFile.open(outputFileName, ios::out);

    if (!outFile.is_open()) {
        std::cout << "Coultn't create file " << outputFileName << std::endl;
        return;
    }

    uint_fast32_t lineLimit = 10;
    for (uint_fast32_t lineNumber = 1; lineNumber <= lineLimit; lineNumber++) {
        outFile << lineNumber << "\tsheep" << std::endl;
    }

    outFile.close();
}

void reading_text_files() {
    std::string inFileName = "text_in.txt";

    ofstream outFile(inFileName);
    outFile << "this is a line" << std::endl;
    outFile << "this is another line" << std::endl;
    outFile << "Here's a third line" << std::endl;
    outFile.close();

//    fstream inFile;
//    inFile.open(inFileName, ios::in);

    ifstream inFile;
    inFile.open(inFileName);

    if (!inFile.is_open()) {
        std::cout << "Coultn't open file " << inFileName << std::endl;
        return;
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::cout << line << std::endl;
    }

    inFile.close();
}

void parsing_text_files() {
    std::string fileName = "stats.txt";
    ifstream input;
    input.open(fileName);

    if (!input.is_open()) {
        return;
    }

    parseLine(input);

    input.close();
}

void parseLine(ifstream &input) {
    string line;
    while (getline(input, line)) {
        stringstream lineStream;
        lineStream << line;
        parseLineElements(lineStream);
    }
}

void parseLineElements(stringstream &lineStream) {
    string population;
    string nation;
    uint_fast32_t numberOfCitizens = 0;

    while (getline(lineStream, population, ':')) {
        nation = population;
        lineStream >> ws;
        lineStream >> numberOfCitizens;
        cout << nation << " --- " << numberOfCitizens << endl;
    }
}

// remove struct's padding
//  for easier usage with binary file serialization
#pragma pack(push, 1)

struct Person {
    char name[50];
    int age;
    double weight;
};

// enable padding for the rest of the data structures
#pragma pack(pop)

Person loadPerson(const string &fileName);

void structs_and_padding() {
    std::string fileName = "test.bin";

    savePerson(fileName);
    Person someoneElse = loadPerson(fileName);

    std::cout << someoneElse.name << "; " << someoneElse.age << "; " << someoneElse.weight << std::endl;
}

Person loadPerson(const string &fileName) {
    ifstream inputFile;
    inputFile.open(fileName, ios::binary);

    if (!inputFile.is_open()) {
        cout << "Couln't read file " + fileName << endl;
    }

    Person person = {"Frodo", 220, 0.8};
    inputFile.read(reinterpret_cast<char *>(&person), sizeof(Person));

    inputFile.close();
    return person;
}

void savePerson(const string &fileName) {
    ofstream outputFile;
    outputFile.open(fileName, ios::binary);

    if (!outputFile.is_open()) {
        cout << "Couln't create file " + fileName << endl;
    }

    Person someone = {"Frodo", 220, 0.8};
    outputFile.write(reinterpret_cast<char *>(&someone), sizeof(Person));

    outputFile.close();
}
