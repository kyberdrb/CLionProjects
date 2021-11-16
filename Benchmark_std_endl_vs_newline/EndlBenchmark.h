#pragma once

#include <ostream>
#include "NewLineBenchmark.h"

class EndlBenchmark : public NewLineBenchmark {
    std::ostream& writeNewLine(std::ostream &os) const override {
        std::endl(os);
        return os;
    }
};