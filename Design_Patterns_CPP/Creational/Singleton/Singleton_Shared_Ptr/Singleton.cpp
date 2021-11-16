#include "Singleton.h"

Singleton& Singleton::getInstance() {
    static std::shared_ptr<Singleton> instance(new Singleton);
    return *instance.get();
}

std::string Singleton::use() {
    return "Singleton working...";
}
