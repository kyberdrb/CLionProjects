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
        std::unique_ptr<Entity> entity = std::make_unique<Entity>();
//        std::unique_ptr<Entity> anotherEntity = entity; // cannot copy an unique_ptr: copy ctor and copy assignment operator are deleted in unique_ptr
                                                        // error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = Entity; _Dp = std::default_delete<Entity>]’
        entity->print();

        std::unique_ptr<Entity> anotherEntity = std::move(entity);  // but we can move a unique_ptr - move ownership to somebody else
        anotherEntity->print();

        assert(entity == nullptr);
        if (entity) {
            entity->print();
        }
    }

    return 0;
}
