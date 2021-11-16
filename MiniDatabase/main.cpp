#include <iostream>
#include <cstdlib>
#include <limits>
#include <fstream>

struct Person {
    std::string name;
    std::string surname;
    short age;
    std::string telephone;
};

Person people[20];
short peopleInDatabase = 0;

void requireEnter();
void addPerson();
void showPeople();
void savePeopleToFile();
void loadPeopleFromFile();
void searchDatabase();
void removePersonFromDatabase();
int main() {

    char test = 0;

    while (test != 27) {
        std::cout << "Number of people in database: " << peopleInDatabase << std::endl;
        std::cout << "Menu" << std::endl;
        std::cout << "1. Add Person" << std::endl;
        std::cout << "2. Show All People" << std::endl;
        std::cout << "3. Save People To File" << std::endl;
        std::cout << "4. Load People From File" << std::endl;
        std::cout << "5. Search For Person" << std::endl;
        std::cout << "6. Remove Person" << std::endl;

        test = std::cin.get();

        switch (test) {
            case '1':
                addPerson();
                break;
            case '2':
                showPeople();
                break;
            case '3':
                savePeopleToFile();
                break;
            case '4':
                loadPeopleFromFile();
                break;
            case '5':
                searchDatabase();
                break;
            case '6':
                removePersonFromDatabase();
                break;
            default:
                system("clear");
                break;
        }

        requireEnter();

        system("clear");
    }

    return 0;
}

void requireEnter() {
    std::cout << "Press <Enter> to continue" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cin.sync();
    std::cin.get();
}

void addPerson() {
    std::cout << "Name: " << std::endl;
    std::cin >> people[peopleInDatabase].name;

    std::cout << "Surname: " << std::endl;
    std::cin >> people[peopleInDatabase].surname;

    std::cout << "Age: " << std::endl;
    std::cin >> people[peopleInDatabase].age;

    std::cout << "Telephone: " << std::endl;
    std::cin >> people[peopleInDatabase].telephone;

    peopleInDatabase++;
}

void showPeople() {
    if (peopleInDatabase > 0) {
        for (int i = 0; i < peopleInDatabase; i++) {
            std::cout << "Person index: " << (i+1) << std::endl;
            std::cout << "Name: " << people[i].name << std::endl;
            std::cout << "Surname: " << people[i].surname << std::endl;
            std::cout << "Age: " << people[i].age << std::endl;
            std::cout << "Telephone: " << people[i].telephone << std::endl;
            std::cout << std::endl;
        }
    } else {
        std::cout << "There is nobody here yet" << std::endl;
    }
}

void savePeopleToFile() {
    std::ofstream file("database.txt");

    if (file.is_open()) {
        file << peopleInDatabase << std::endl;

        for (int i = 0; i < peopleInDatabase; i++) {
            file << people[i].name << std::endl;
            file << people[i].surname << std::endl;
            file << people[i].age << std::endl;
            file << people[i].telephone << std::endl;
        }
        file.close();
    } else {
        std::cout << "Can't save people to database" << std::endl;
    }
}

void loadPeopleFromFile() {
    std::ifstream file("database.txt");

    if (file.is_open()) {
        file >> peopleInDatabase;

        if (peopleInDatabase > 0) {
            int i = 0;
            do {
                file >> people[i].name;
                file >> people[i].surname;
                file >> people[i].age;
                file >> people[i].telephone;
                i++;
            } while (!file.eof());
        }

        std::cout << "People have been loaded successfully" << std::endl;

    } else {
        std::cout << "Can't load people from database" << std::endl;
    }

    file.close();
}

void searchDatabase() {
    if (peopleInDatabase > 0) {
        std::string name = "";

        std::cout << "Type a name of a person to search:" << std::endl;
        std::cin >> name;

        for (int i = 0; i < peopleInDatabase; i++) {
            if (name == people[i].name) {
                std::cout << "Person index: " << (i+1) << std::endl;
                std::cout << "Name: " << people[i].name << std::endl;
                std::cout << "Surname: " << people[i].surname << std::endl;
                std::cout << "Age: " << people[i].age << std::endl;
                std::cout << "Telephone: " << people[i].telephone << std::endl;
                std::cout << std::endl;
            }
        }

    } else {
        std::cout << "There isn't anybody here yet" << std::endl;
    }
}

void removePersonFromDatabase() {
    if (peopleInDatabase > 0) {
        int index = -1;

        std::cout << "Index of a person to remove:" << std::endl;
        std::cin >> index;
        index -= 1;

        if (index < peopleInDatabase) {
            people[index].name = people[peopleInDatabase - 1].name;
            people[index].surname = people[peopleInDatabase - 1].surname;
            people[index].age = people[peopleInDatabase - 1].age;
            people[index].telephone = people[peopleInDatabase - 1].telephone;

            peopleInDatabase--;
        } else {
            std::cout << "There is nobody like that" << std::endl;
        }
    } else {
        std::cout << "There isn't anybody here yet" << std::endl;
    }
}
