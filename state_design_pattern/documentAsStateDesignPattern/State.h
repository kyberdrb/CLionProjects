//
// Created by AndrejŠišila on 3/9/2023.
//

#pragma once

//#include "Document.h"
class Document; // Cyclic/Circular dependency / cyclic header include: Document includes State AND State includes Document
                // Using forward declaration of 'Document' instead of include
                //  Forward declaration breaks the cycle and lets the code compile.

#include <iosfwd>

class State {
public:
//    State() = default;

    explicit State(Document& document) :
        _document(document)
    {}

    virtual void publish() = 0;
    virtual void returnDocAfterReview() = 0;
    virtual void expire() = 0;

    virtual ~State() = default;

    Document& _document;

    friend std::ostream& operator<<(std::ostream& out, const State& state);

protected:
    virtual void streamOutputOperator(std::ostream& out) const = 0;
};

inline std::ostream& operator<<(std::ostream& out, const State& state) {
    state.streamOutputOperator(out);
    return out;
}
