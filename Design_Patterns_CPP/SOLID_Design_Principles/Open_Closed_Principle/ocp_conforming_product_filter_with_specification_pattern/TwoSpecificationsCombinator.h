//
// Created by laptop on 7/31/19.
//

#ifndef OPEN_CLOSED_PRINCIPLE_TWOSPECIFICATIONSCOMBINATOR_H
#define OPEN_CLOSED_PRINCIPLE_TWOSPECIFICATIONSCOMBINATOR_H

#include "Specification.h"

template <typename T>
struct TwoSpecificationsCombinator : Specification<T> {
    Specification<T>& first;
    Specification<T>& second;

    TwoSpecificationsCombinator(Specification<T> &first, Specification<T> &second)
            :
            first(first), second(second) {}

    bool is_statisfied(T *item) override {
        return first.is_statisfied(item) && second.is_statisfied(item);
    }
};

#endif //OPEN_CLOSED_PRINCIPLE_TWOSPECIFICATIONSCOMBINATOR_H
