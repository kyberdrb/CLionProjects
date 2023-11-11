//
// Created by laptop on 10/15/23.
//

#include "Singleton.h"

#include <iostream>
#include <sstream>

// Static member variable initialization
std::unique_ptr<Singleton> Singleton::instance = nullptr;

Singleton& Singleton::getInstance() {
    // Lazy initialization: create the instance on the first access
    if (!instance) {
        std::cout << instance.get() << ": getInstance(): Singleton instance is being created...\n";
        instance = std::make_unique<Singleton>();
        std::cout << instance.get() << ": getInstance(): Singleton instance created." << '\n';;
    }
    return *instance;
}

Singleton::Singleton() :
    _value("<default_value>")
{
    std::cout << this << ": Constructor: Singleton instance created.\n";
}

Singleton& Singleton::getInstance(std::string value) {
    // Lazy initialization: create the instance on the first access
    if (!instance) {
        struct SingletonImpl : public Singleton {
            SingletonImpl(std::string value) : Singleton(std::move(value)) {}
            // no need to declare the destructor of base class Singleton as virtual,
            //  or overriding it here in the derived class,
            //  because derived class has no intrinsic state, i.e. no attributes
        };
        std::cout << instance.get() << ": getInstance(): Singleton instance is being created...\n";
        instance = std::make_unique<SingletonImpl>(std::move(value));
        std::cout << instance.get() << ": getInstance(): Singleton instance created with value '" << instance->_value << "'" << '\n';
    }
    return *instance;
}

Singleton::Singleton(std::string value) :
    _value(std::move(value))
{
    std::cout << this << ": Constructor: Singleton instance created with value '" << this->_value << "'\n";
}

void Singleton::printTextSynchronously() {
    // Synchronize access to the std::cout when function 'printTextSynchronously' is called from multiple threads
    //  Comment out to see the multithreading bug: overlapping outputs on multithreaded printing on terminal
    std::lock_guard<std::mutex> lock(this->_mutex);

    std::cout << instance.get() << ": Singleton is printing text synchronously.\n";
}

void Singleton::printTextAsynchronously() {
    // Showcase a bug of a multithreading function access:
    //  overlapping outputs on multithreaded printing on terminal
    std::cout << instance.get() << ": Singleton is printing text without synchronization.\n";
}

std::string Singleton::getValue() const {
    std::stringstream message{};
    message << instance.get() << ": " << this->_value;
    return message.str();
}

Singleton::~Singleton() {
    std::cout << instance.get() << ": Singleton instance destroyed.\n";
}
