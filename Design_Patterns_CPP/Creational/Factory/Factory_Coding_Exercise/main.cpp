#include <iostream>

#include <string>
using namespace std;

struct Person {
    static int id;
    string name;

    Person(const string& person_name) : name(person_name) {
        id++;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& person) {
        os << Person::id << ": " << person.name;
        return os;
    }
};

int Person::id = 0;

class PersonFactory
{
public:
    Person create_person(const string& name)
    {
        return {name};
    }
};

int main() {
    auto person = PersonFactory().create_person("John Doe");
    std::cout << person << std::endl;
    person = PersonFactory().create_person("Jane Doe");
    std::cout << person << std::endl;
    return 0;
}