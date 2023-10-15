//
// Created by laptop on 10/15/23.
//

#pragma once

#include <memory>
#include <mutex>
#include <string>

class Singleton {
public:
    // Functions to access the Singleton instance
    static Singleton& getInstance();
    static Singleton& getInstance(std::string value);

    // Singleton's public member functions
    void doSomething();
    std::string getValue() const;

    // Public destructor for std::make_unique
    ~Singleton();

private:
    // Make std::make_unique a friend to access the private default constructor
    friend std::unique_ptr<Singleton> std::make_unique<Singleton>();

    // Private constructors to prevent direct instantiation
    Singleton();
    explicit Singleton(std::string value);

    // If we declare the destructor as private, we get an error
    //   error: ‘Singleton::~Singleton()’ is private within this context
    //  because std::make_unique needs public access to the destructor
//    ~Singleton() {
//        std::cout << "Singleton instance destroyed." << std::endl;
//    }

    // Private copy and move constructors to prevent cloning and moving
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;

    // Private assignment operators to prevent copying and moving
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    // The unique_ptr to hold the single instance
    static std::unique_ptr<Singleton> instance;

    std::string _value;
    std::mutex _mutex;
};
