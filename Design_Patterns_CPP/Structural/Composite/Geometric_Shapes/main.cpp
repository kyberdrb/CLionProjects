#include <iostream>
#include <vector>

class GraphicalObject {
public:
    virtual void draw() = 0;
};

class Circle : public GraphicalObject {
public:
    void draw() override {
        std::cout << "a circle" << std::endl;
    }
};

class Group : public GraphicalObject {
private:
    std::string name;
    std::vector<GraphicalObject*> graphicalObjects;

public:
    Group(std::string name) {
        this->name = std::move(name);
    }

    void draw() override {
        std::cout << name << " contains" << "\n";
        for (auto&& graphicalObject : graphicalObjects) {
            graphicalObject->draw();
        }
    }

    void add(GraphicalObject* graphicalObject) {
        graphicalObjects.emplace_back(graphicalObject);
    }
};

int main() {

    Circle c1, c2, c3, c4, c5, c6;

    Group g1("Group 1");
    g1.add(&c2);
    g1.add(&c3);
    g1.add(&c4);

    Group g2("Group 2");
    g2.add(&g1);
    g2.add(&c5);
    g2.add(&c6);

    std::vector<GraphicalObject*> picture;
    picture.emplace_back(&c1);
    picture.emplace_back(&g1);
    picture.emplace_back(&g2);

    for (auto&& shape : picture) {
        shape->draw();
        std::cout << std::endl;
    }

    return 0;
}