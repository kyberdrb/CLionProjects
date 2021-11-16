#include <iostream>
#include <vector>

enum Relationship_Type {
    parent,
    child,
    sibling
};

struct Person {
    std::string name;
};

struct Relationship {
    const Person& firstPerson;
    const Person& secondPerson;
    const Relationship_Type relationshipType;

    Relationship(
            const Person &firstPerson,
            const Relationship_Type relationshipType,
            const Person &secondPerson)
            :
            firstPerson(firstPerson),
            relationshipType(relationshipType),
            secondPerson(secondPerson) {}
};
// abstraction of a low-level module for higher-levels modules
// Dependency Inversion Principle (DIP) states that:
// 1. High-level modules should not depend on low-level modules.
//    Both should depend on abstractions.
// 2. Abstractions should not depend on details.
//    Details should depend on abstractions.
struct Relationship_Browser {
    virtual std::vector<Person> find_all_children_of(const std::string& name) const = 0;
    virtual void add_parent_and_child(const Person& parent, const Person& child) = 0;
    virtual ~Relationship_Browser() = default;
};

// low-level module
struct Relationships : Relationship_Browser {
    std::vector<Relationship*> relations;

    void add_parent_and_child(const Person& parent, const Person& child) override {
        relations.emplace_back(new Relationship(parent, Relationship_Type::parent, child));
        relations.emplace_back(new Relationship(child, Relationship_Type::child, parent));
    }

    ~Relationships() override {
        for (const auto& relation : relations) {
            delete relation;
        }
    }

    std::vector<Person> find_all_children_of(const std::string &name) const override {
        std::vector<Person> result;
        for (const auto& relation : relations) {
            if (relation->firstPerson.name == name && relation->relationshipType == Relationship_Type::parent) {
                result.emplace_back(relation->secondPerson);
            }
        }
        return result;
    }
};

// high-level module
struct Research {
    void find(const Relationship_Browser& relationshipBrowser) {
        auto people = relationshipBrowser.find_all_children_of("John");
        for (const auto& child : people) {
            std::cout << child.name << " is John's child" << std::endl;
        }
    }
};

int main() {
    Person parent_1{"John"}, parent_2{"Greg"};
    Person child_1{"Chris"}, child_2{"Matt"}, child_3{"Frank"};

    Relationships relationships;
    relationships.add_parent_and_child(parent_1, child_1);
    relationships.add_parent_and_child(parent_1, child_2);
    relationships.add_parent_and_child(parent_2, child_3);

    Research().find(relationships);

    std::cout << std::endl;

    Relationship_Browser* const relations = new Relationships();

    relations->add_parent_and_child(parent_1, child_1);
    relations->add_parent_and_child(parent_1, child_2);
    relations->add_parent_and_child(parent_2, child_3);

    Research().find(*relations);

    delete relations;

    return 0;
}