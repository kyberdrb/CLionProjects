#include <iostream>
#include <memory>
#include <functional>

// https://www.fluentcpp.com/2017/08/29/custom-deleters/

class Instructions {
public:
    virtual std::unique_ptr<Instructions> clone() const = 0;
    virtual ~Instructions() = default;
};

class Blueprint : public Instructions {
public:
    std::unique_ptr<Instructions> clone() const {
        return std::unique_ptr<Instructions>(new Blueprint(*this));
    }
};

class Sketch : public Instructions {
public:
    std::unique_ptr<Instructions> clone() const {
        return std::unique_ptr<Instructions>(new Sketch(*this));
    }
};

class House {
    std::unique_ptr<Instructions> instructions;

public:
    explicit House(std::unique_ptr<Instructions> instructions) :
        instructions(std::move(instructions)){}

    House(const House& house) :
        instructions(house.instructions->clone()) {}
};

enum class BuildingMethod {
    FROM_SKETCH,
    FROM_BLUEPRINT
};

class InvalidBuildMethod : public std::exception {
public:
    const char *what() const noexcept override {
        return exception::what();
    }
};

void deleteInstructions(Instructions* instructions) {
    delete instructions;
}

void doNotDeleteInstructions(Instructions* instructions) {}

House buildHouse(BuildingMethod method) {
    //using InstructionsUniquePtr = std::unique_ptr<Instructions, void(*)(Instructions*)>;
    //using InstructionsUniquePtr = std::unique_ptr<Instructions, std::function<void(Instructions*)>>;

    if (method == BuildingMethod::FROM_SKETCH) {
        //return House(std::unique_ptr<Instructions>(new Sketch()));  // without deleter

        //return House(std::unique_ptr<Instructions, void(*)(Instructions*)>(new Sketch, deleteInstructions));
        //return House(InstructionsUniquePtr(new Sketch, deleteInstructions));
    }

    if (method == BuildingMethod::FROM_BLUEPRINT) {
        return House{std::make_unique<Blueprint>()};
        //return House{std::make_unique<Blueprint, deleteInstructions>()};
    }

    throw InvalidBuildMethod();
}

int main() {
    auto blueprint = std::make_unique<Blueprint>();
    //auto house = std::make_unique<House>(blueprint);    // Fails on custom deleter

    auto house = buildHouse(BuildingMethod::FROM_BLUEPRINT);    // OK

    return 0;
}