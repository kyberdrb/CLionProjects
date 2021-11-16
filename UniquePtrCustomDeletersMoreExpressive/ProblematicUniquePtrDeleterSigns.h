#pragma once

#include "Computer.h"
#include "NamespacedComputer.h"

using ComputerConstPtr = std::unique_ptr<Computer, void(*)(const Computer*)>;
void plugIn(ComputerConstPtr computer);

void deleteComputer(const Computer* computer) {
    delete computer;
};

template <typename T>
void deleteSomething(const T* p) {
    delete p;
}

template <typename T>
void doNotDeleteSomthing(const T* p) {}

// Do I need to specify the parameter here when it's not used in the body of the function?
void doNotDeleteComputer(const Computer* computer) {}
