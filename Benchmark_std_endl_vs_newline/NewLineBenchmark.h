#pragma once

#include <ostream>

class NewLineBenchmark {
public:
    virtual std::ostream& writeNewLine(std::ostream& os) const = 0;

    friend std::ostream& operator<<(std::ostream& os, const NewLineBenchmark& newLineBenchmark) {
        newLineBenchmark.writeNewLine(os);
        return os;
    }
};