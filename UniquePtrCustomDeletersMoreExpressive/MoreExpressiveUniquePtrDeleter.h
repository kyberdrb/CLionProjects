#pragma once

#include <memory>
#include <iostream>

namespace util {

    template <typename T>
    void doDelete(const T* pointer) {
        delete pointer;
    }

    template <typename T>
    void doNotDelete(const T* pointer) {}

    template <typename T>
    using CustomUniquePtr = std::unique_ptr<const T, void(*)(const T*)>;

    template <typename T>
    auto makeConstUnique(const T* pointer) {
        return CustomUniquePtr<T>(pointer, doDelete<T>);
    }

    void specificFunctionToFreeComputer(const Computer* pointer) {
        std::cout << "Freeing a namespaced computer into  the spaaaaaace..." << std::endl;
    }

    template <>
    auto makeConstUnique(const Computer* pointer) {
        return CustomUniquePtr<Computer>(pointer, specificFunctionToFreeComputer);
    }

    template <typename T>
    auto makeConstUniqueDoNotDelete(const T* pointer) {
        return CustomUniquePtr<T>(pointer, doNotDelete<T>);
    }
}