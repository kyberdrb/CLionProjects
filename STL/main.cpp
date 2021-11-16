#include <utility>
#include <iostream>
#include <vector>

void exercise_vector();
void exercise_2d_vector();
void exercise_list();
void exercise_map();
void exercise_map_objects_as_value();
void exercise_map_objects_as_key();
void exercise_multimap();
void exercise_set();
void exercise_stack_and_queue();
void exercise_sorting_vectors_deque_friend();
void exercise_complex_datatypes();

int main() {
//    exercise_vector();
//    exercise_2d_vector();
//    exercise_list();
//    exercise_map();
//    exercise_map_objects_as_value();
//    exercise_map_objects_as_key();
//    exercise_multimap();
//    exercise_set();
//    exercise_stack_and_queue();
//    exercise_sorting_vectors_deque_friend();
    exercise_complex_datatypes();

    return 0;
}

class Chair {
private:
    std::string name;
    std::string color;

public:
    Chair(std::string name, std::string color)
            :
            name(std::move(name)), color(std::move(color)) {}

    const std::string &getName() const {
        return name;
    }

    const std::string &getColor() const {
        return color;
    }
};

void exercise_vector() {
    std::vector<Chair *> chairs;

    chairs.emplace_back(new Chair("Oldskor", "yellow"));
    chairs.emplace_back(new Chair("Jäärvinnen", "blue"));
    chairs.emplace_back(new Chair("Smaak", "red"));

    for (const auto &chair : chairs) {
        std::cout << chair->getName() << " | " << chair->getColor() << std::endl;
    }

    for (Chair *const chair : chairs) {
        delete chair;
    }
}

void exercise_2d_vector() {
    typedef std::vector< std::vector<int> > vector2d;
    uint_fast32_t numOfRows = 3;
    uint_fast32_t numOfColumns = 4;
    uint_fast32_t initValue = 7;
    vector2d grid(numOfRows, std::vector<int>(numOfColumns, initValue));

    grid[1].emplace_back(8);

    for (int row = 0; row < grid.size(); row++) {
        for (int column = 0; column < grid[row].size(); ++column) {
            std::cout << grid[row][column] << "\t" << std::flush;
        }
        std::cout << std::endl;
    }
}

#include <list>
void exercise_list() {
    std::list<int> numbers;

    numbers.emplace_back(1);
    numbers.emplace_back(2);
    numbers.emplace_back(3);
    numbers.emplace_front(0);

    std::list<int>::iterator it = numbers.begin();
    it++;
    numbers.insert(it, 100);
    std::cout << "Element: " << *it << std::endl;

    std::list<int>::iterator eraseIt = numbers.begin();
    eraseIt++;
    eraseIt = numbers.erase(eraseIt);
    std::cout << "Element to be erased: " << *it << std::endl;

    it = numbers.begin();
    while (it != numbers.end()) {
        if (*it == 2) {
            numbers.insert(it, 1234);
        }

        if (*it == 1) {
            it = numbers.erase(it);
        } else {
            it++;
        }
    }

    for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        std::cout << *it << std::endl;
    }
}

#include <map>
#include <algorithm>

void exercise_map() {
    std::map<std::string, int> ages;

    ages["Mike"] = 40;
    ages["Raj"] = 20;
    ages["Vicky"] = 30;
    ages["Mike"] = 70;

    std::pair<std::string, int> pairToAdd("Peter", 100);
    ages.insert(pairToAdd);

    ages.insert(std::pair<std::string, int>("Robin", 99));

    ages.insert(std::make_pair("Guy", 50));

    std::cout << ages["Raj"] << std::endl;

    if (ages.find("Sue") == ages.end()) {
        std::cout << "Element not found" << std::endl;
    }

    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        std::cout << it->first << " --- " << it->second << std::endl;
    }

    std::cout << std::endl;

    for (std::map<std::string, int>::iterator it = ages.begin(); it != ages.end(); it++) {
        std::pair<std::string, int> age = *it;
        std::cout << age.first << " ... " << age.second << std::endl;
    }
}

class Person {
private:
    std::string name;
    uint_fast32_t age;

public:
    Person(): name(""), age(0) {}

    Person(std::string name, uint_fast32_t age)
            :
            name(std::move(name)), age(age) {}

    Person(const Person& otherPerson) {
        this->name = otherPerson.name;
        this->age = otherPerson.age;
    }

    void print() const {
        std::cout << this->name << "; " << this->age << std::flush;
    }

    bool operator< (const Person& otherPerson) const {
        return
            this->name < otherPerson.name ||
            this->age < otherPerson.age;
    }
};

void exercise_map_objects_as_value() {
    std::map<int, Person> people;

    people[2] = Person("Mike", 40);
    people[4] = Person("Raj", 20);
    people[7] = Person("Vicky", 30);

    people.insert(std::make_pair(9, Person("Bob", 45)));
    people.insert(std::make_pair(9, Person("Sue", 24)));

    for (auto it = people.begin(); it != people.end(); it++) {
        std::cout << it->first << " | ";
        it->second.print();
    }
}

void exercise_map_objects_as_key() {
    std::map<Person, int> people;

    people[Person("Mike", 40)] = 400;
    people[Person("Mike", 444)] = 123;
    people[Person("Raj", 20)] = 200;
    people[Person("Sue", 30)] = 300;

    for (auto it = people.begin(); it != people.end(); it++) {
        std::cout << it->second << " | ";
        it->first.print();
        std::cout << std::endl;
    }

}

#include <map>
void exercise_multimap() {
    std::multimap<int, std::string> lookup;

    lookup.insert(std::make_pair(30, "Mike"));
    lookup.insert(std::make_pair(10, "Vicky"));
    lookup.insert(std::make_pair(30, "Raj"));
    lookup.insert(std::make_pair(20, "Bob"));

    for (std::multimap<int, std::string>::iterator it = lookup.begin(); it != lookup.end(); it++) {
        std::cout << it->first << " --- " << it->second << std::endl;
    }

    std::cout << std::endl;

    for (std::multimap<int, std::string>::iterator it = lookup.find(20); it != lookup.end(); it++) {
        std::cout << it->first << " --- " << it->second << std::endl;
    }

    std::cout << std::endl;

    std::pair<
            std::multimap<int, std::string>::iterator,
            std::multimap<int, std::string>::iterator> iteratorPair = lookup.equal_range(10);

    for (std::multimap<int, std::string>::iterator it = iteratorPair.first; it != iteratorPair.second; it++) {
        std::cout << it->first << " --- " << it->second << std::endl;
    }

    std::cout << std::endl;

    auto anotherIteratorPair = lookup.equal_range(30);

    for (auto it = anotherIteratorPair.first; it != anotherIteratorPair.second; it++) {
        std::cout << it->first << " --- " << it->second << std::endl;
    }

}

class Test {
private:
    uint_fast32_t id;
    std::string name;

public:
    Test(uint_fast32_t id, const std::string &name) : id(id), name(name) {}

    void print() const{
        std::cout << id << ": " << name << std::flush;
    }

    bool operator< (const Test& otherTest) const {
        return this->id < otherTest.id || this->name < otherTest.name;
    }
};

#include <set>
void exercise_set() {
    std::set<int> numbers;

    numbers.insert(10);
    numbers.insert(10);
    numbers.insert(34);
    numbers.insert(56);

    for (const auto &it : numbers) {
        std::cout << it << std::endl;
    }

    std::cout << std::endl;

    std::set<int>::iterator itFind = numbers.find(34);

    if (itFind != numbers.end()) {
        std::cout << *itFind << std::endl;
    }

    std::cout << std::endl;

    if (numbers.count(10)) {
        std::cout << "Element is present" << std::endl;
    }

    std::cout << std::endl;

    std::set<Test> tests;
    tests.insert(Test(10, "Mike"));
    tests.insert(Test(30, "Joe"));
    tests.insert(Test(30, "Joe"));
    tests.insert(Test(20, "Sue"));

    for (const auto& it: tests) {
        it.print();
        std::cout << std::endl;
    }
}

class Test_2 {
private:
    std::string name;

public:
    Test_2(std::string name) : name(std::move(name)) {}

    ~Test_2() {
//        std::cout << "Object destroyed" << std::endl << std::flush;
    }

    void print() {
        std::cout << this->name << std::endl << std::flush;
    }
};

#include <stack>
#include <queue>
void exercise_stack_and_queue() {
    std::stack<Test_2> testStack;
    testStack.push(Test_2("Mike"));
    testStack.push(Test_2("John"));
    testStack.push(Test_2("Sue"));

    while (testStack.size() > 0) {
        Test_2& test = testStack.top();
        test.print();
        testStack.pop();
    }

    std::cout << std::endl;

    std::queue<Test_2> testQueue;
    testQueue.push(Test_2("Mike"));
    testQueue.push(Test_2("John"));
    testQueue.push(Test_2("Sue"));

    while (testQueue.size() > 0) {
        Test_2& test = testQueue.front();
        test.print();
        testQueue.pop();
    }
}

class Test_3 {
private:
    uint_fast32_t id;
    std::string name;

public:
    Test_3(uint_fast32_t id, std::string name) : id(id), name(std::move(name)) {}

    void print() const {
        std::cout << id << ": " << name << std::flush;
    }

//    bool operator<(const Test_3& otherTest) const {
//        return this->id < otherTest.id || this->name < otherTest.name;
//    }

    friend bool comp(const Test_3& test_a, const Test_3& test_b);
};

bool comp(const Test_3& test_a, const Test_3& test_b) {
    return test_a.name < test_b.name;
}

void exercise_sorting_vectors_deque_friend() {
    std::vector<Test_3> tests;

    tests.emplace_back(Test_3(5, "Mike"));
    tests.emplace_back(Test_3(10, "Sue"));
    tests.emplace_back(Test_3(7, "Raj"));
    tests.emplace_back(Test_3(3, "Wickie"));
    tests.emplace_back(Test_3(3, "Vicky"));

    // Sorting via overridden '<' (less-than) operator
//    std::sort(tests.begin(), tests.end());

    std::sort(tests.begin(), tests.end(), comp);

    for (const auto& test : tests) {
        test.print();
        std::cout << std::endl;
    }
}

void exercise_complex_datatypes() {
    std::map< std::string, std::vector<int> > scores;

    scores["Mike"].push_back(10);
    scores["Mike"].push_back(20);
    scores["Vicky"].push_back(30);

    for (const auto& score : scores) {
        std::string name = score.first;
        std::cout << name << "\t" << std::flush;
        const std::vector<int>& playerScores = score.second;

        for (const auto& player : playerScores) {
            std::cout << player << "\t" << std::flush;
        }

        std::cout << std::endl;
    }
}
