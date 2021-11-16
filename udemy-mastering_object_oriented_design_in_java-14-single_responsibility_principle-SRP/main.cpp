#include <string>
#include <iostream>
#include <vector>

class Employee {
public:
    Employee() :
        id(-1),
        name("John Doe"),
        department("free"),
        working(true)
    {};

    Employee(
            long id,
            std::string name,
            std::string department,
            bool working)
        :
        id(id),
        name(std::move(name)),
        department(std::move(department)),
        working(working)
    {};

    void printEmployeeDetailReportXML() const {
        std::cout <<
            "<" << "id" << ">" << id << "<" << "/" << "id" << ">" << "\n" <<
            "<" << "name" << ">" << name << "<" << "/" << "name" << ">" << "\n" <<
            "<" << "department" << ">" << department << "<" << "/" << "department" << ">" << "\n" <<
            "<" << "working" << ">" << working << "<" << "/" << "working" << ">";
        std::cout << std::endl;
    }

    void printEmployeeDetailReportCSV() const {
        std::cout <<
            id << ";" <<
            "\"" << name << "\"" << ";" <<
            "\"" << department << "\"" << ";" <<
            working;
        std::cout << std::endl;
    }

    void saveEmployeeToDatabase() {
        employees.push_back(this);
    }

    void terminateEmployee() {}

private:
    long id;
    std::string name;
    std::string department;
    bool working;

    std::vector<Employee*> employees;   // employee instance is alone, each employee know only about himself,
                                        // why would he know about all other employees within himself as well?
                                        // and how they would be destroyed?
                                        // ok. time for refactoring.
};

int main() {
    Employee e;
    e.printEmployeeDetailReportXML();
    std::cout << std::endl;
    e.printEmployeeDetailReportCSV();

    return 0;
}
