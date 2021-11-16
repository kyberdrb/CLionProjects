#include <bits/unique_ptr.h>
#include <iomanip>
#include "EndlBenchmark.h"
#include "NewlineCharBenchmark.h"
#include "Benchmarker.h"

int main() {
    const uint_fast32_t COLUMN_WIDTH = 30;
    auto durationEndl = Benchmarker::measureFile("benchmark_endl.txt", EndlBenchmark());
    std::cout << "endl\t\t\t" << durationEndl << std::endl;

    auto durationNewLineChar = Benchmarker::measureFile("benchmark_newline.txt", NewlineCharBenchmark());
    std::cout << "newline char\t" << durationNewLineChar << std::endl;

    std::cout << "'newline character' is ";
    std::cout << std::fixed << std::showpoint << std::setprecision(2);
    std::cout << ((double) durationEndl / durationNewLineChar);
    std::cout << " times faster than 'endl'" << std::endl;
    return 0;
}
