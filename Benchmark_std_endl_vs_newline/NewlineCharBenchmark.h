#pragma once

#include <ostream>

class NewlineCharBenchmark : public NewLineBenchmark {
    std::ostream& writeNewLine(std::ostream &os) const override {
        return os << "\n";
    }
};