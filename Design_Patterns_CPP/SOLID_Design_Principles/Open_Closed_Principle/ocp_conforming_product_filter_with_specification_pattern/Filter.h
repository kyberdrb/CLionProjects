//
// Created by laptop on 7/31/19.
//

#ifndef OPEN_CLOSED_PRINCIPLE_FILTER_H
#define OPEN_CLOSED_PRINCIPLE_FILTER_H


#include <vector>
#include "Specification.h"

template <typename T>
struct Filter {
    virtual std::vector<T*> filter(std::vector<T*> items, Specification<T>& spec) = 0;
};


#endif //OPEN_CLOSED_PRINCIPLE_FILTER_H
