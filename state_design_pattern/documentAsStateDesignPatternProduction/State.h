//
// Created by AndrejŠišila on 3/30/2023.
//

#pragma once

#include <iosfwd>

namespace production {
    class Document;

    class State {
    public:
        explicit State(Document& document) :
                _document(document)
        {}

        virtual void publish() = 0;
        virtual void returnDocAfterReview() = 0;
        virtual void expire() = 0;

        virtual ~State() = default;

        friend std::ostream& operator<<(std::ostream& out, const State& state);

    protected:
        virtual void streamOutputOperator(std::ostream& out) const = 0;

        Document& _document;
    };

    inline std::ostream& operator<<(std::ostream& out, const State& state) {
        state.streamOutputOperator(out);
        return out;
    }
}
