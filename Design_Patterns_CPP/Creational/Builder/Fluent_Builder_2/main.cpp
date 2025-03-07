#include "FluentBuilder.h"

#include <chrono>
#include <iostream>
#include <print>

int main() {
    auto somethingFluentToBuild = FluentBuilder::create()
        .withNumber(2)
        .withText("Stack Builder is awesome");

    auto start = std::chrono::steady_clock::now();
    std::cout << "std::cout: " << somethingFluentToBuild << '\n';
    auto end = std::chrono::steady_clock::now();
    auto executionTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::println("std::cout (execution time): {}", executionTime);

    start = std::chrono::steady_clock::now();
    std::println("std::print: {}", somethingFluentToBuild.str());
    end = std::chrono::steady_clock::now();
    executionTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::println("std::print (execution time): {}", executionTime);

    std::println("");

    // Compiles, but segfaults
    // auto somethingUniquelyFluentToBuild = FluentBuilder::createUnique();
    // auto wup = std::move(somethingUniquelyFluentToBuild)
    //         ->addSomethingUnique(4)
    //         ->addSomethingElseUnique("Builder is awesome");

    // Doesn't compile: operator '->' discards 'rvalue' qualifiers transforming 'rvalue' refs into 'lvalue' refs
    //  Returning unique_ptr is valid, but chaining unique_ptr pointers is ill-formed, as it requires moving ownership back and forth while requiring owning the instance by the client and the built instance at the same time, which would require double deletion
    // auto somethingUniquelyFluentToBuild = std::move(FluentBuilder::createUnique());
    //         ->addSomethingUnique(4)
    //         ->addSomethingElseUnique("Builder is awesome");

    auto somethingUniquelyFluentToBuild = FluentBuilder::createUnique() // auto will first start with unique_ptr...
        ->withUniqueNumber(4) // ...then will convert to lvalue reference...
        .withUniqueText("Unique Builder is awesome"); // ...and stays as lvalue reference

    start = std::chrono::steady_clock::now();
    std::cout << "std::cout: " << somethingUniquelyFluentToBuild << '\n';
    end = std::chrono::steady_clock::now();
    executionTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::println("std::cout (execution time): {}", executionTime);

    start = std::chrono::steady_clock::now();
    std::println("std::print: {}", somethingUniquelyFluentToBuild.str());
    end = std::chrono::steady_clock::now();
    executionTime = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::println("std::print (execution time): {}", executionTime);

    return 0;
}