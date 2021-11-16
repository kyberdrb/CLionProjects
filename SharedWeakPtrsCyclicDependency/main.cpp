#include <memory>

struct SharedHouseWithPersistentCyclicDependency {
    std::shared_ptr<SharedHouseWithPersistentCyclicDependency> neighbor;
};

void cyclicDependencyWithSEGFAULT() {
    auto house1 = std::make_shared<SharedHouseWithPersistentCyclicDependency>();
    auto house2 = std::make_shared<SharedHouseWithPersistentCyclicDependency>();

    // Create cyclic dependency
    house1->neighbor = house2;
    house2->neighbor = house1;
};

struct SharedHouseWithDestructableCyclicDependency {
    std::weak_ptr<SharedHouseWithDestructableCyclicDependency> neighbor;
};


void cyclicDependencyWithCleanup() {
    auto house3 = std::make_shared<SharedHouseWithDestructableCyclicDependency>();
    auto house4 = std::make_shared<SharedHouseWithDestructableCyclicDependency>();

    // Create cyclic dependency
    house3->neighbor = house4;
    house4->neighbor = house3;
};

struct House
{
    std::shared_ptr<House> neighbour;
};

void invokeSegfault() {
    std::shared_ptr<House> house1;
    std::shared_ptr<House> house2;
    house1->neighbour = house2;
    house2->neighbour = house1;
}

int main() {
    cyclicDependencyWithSEGFAULT();
    cyclicDependencyWithCleanup();
//    invokeSegfault();   // dangerous
    return 0;
}