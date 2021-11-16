#pragma once

#include <cstdint>
#include <chrono>
#include <fstream>
#include <iostream>
#include "NewLineBenchmark.h"

class Benchmarker {
public:
    static auto measureFile(std::string&& fileName, NewLineBenchmark&& newLineBenchmark) {
        std::remove(fileName.c_str());
        std::ofstream file;
        file.open(fileName);

        auto start = std::chrono::high_resolution_clock::now();
        for (uint_fast32_t attempt = 0; attempt < 100000; ++attempt) {
            file << "Hello World";
            file << newLineBenchmark;
        }

        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = stop - start;
        return duration.count();

    }
};