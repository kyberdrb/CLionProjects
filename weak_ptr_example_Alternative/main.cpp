#include <iostream>
#include <memory>
#include <cassert>

// The Cherno: SMART POINTERS in C++ (std::unique_ptr, std::shared_ptr, std::weak_ptr): https://www.youtube.com/watch?v=UOB7-B2MfwA

struct Entity {
    Entity() {
        std::cout << "Entity Created" << std::endl;
    }

    ~Entity() {
        std::cout << "Entity Destroyed" << std::endl;
    }

    void print() const {
        std::cout << "Entity is here" << std::endl;
    }
};

int main() {
    {
        std::weak_ptr<Entity> weakEntity;
        std::cout << "\tweakEntity: ref_count: " << weakEntity.use_count() << std::endl;

        {
            std::shared_ptr<Entity> anotherEntity = std::make_shared<Entity>();
            std::cout << "\tanotherEntity: ref_count: " << anotherEntity.use_count() << std::endl;
            std::cout << "\tweakEntity: ref_count: " << weakEntity.use_count() << std::endl;

            weakEntity = anotherEntity;

            std::cout << "\tanotherEntity): ref_count: " << anotherEntity.use_count() << std::endl;
            std::cout << "\tweakEntity: ref_count: " << weakEntity.use_count() << std::endl;
            anotherEntity->print();
        }

        assert(weakEntity.lock() == nullptr);
        assert(weakEntity.expired());
    }

    return 0;
}
