#include "Fridge.h"
#include "Engine.h"

class Fridge::FridgeImpl {  // Hide dependencies behind implementation class - Compilation Firewall - shorten compilation time
    std::unique_ptr<Engine> engine;  // dependency of the Fridge class

public:
    FridgeImpl() : engine(std::make_unique<Engine>()) {}

    void coolDown() {
        std::cout << "Cooling down - implementation" << std::endl;
        engine->start();
    }
};

Fridge::Fridge() : pimpl(new FridgeImpl) {}

Fridge::~Fridge() = default;    // The destructor also needs to be defined, otherwise the linker reports an error: undefined reference to `Fridge::~Fridge()'

void Fridge::coolDown() {
    std::cout << "Preparing to cool down - level of indirection" << std::endl;
    pimpl->coolDown();
}