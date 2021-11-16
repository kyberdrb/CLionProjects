//
// Created by laptop on 7/31/19.
//

#ifndef OPEN_CLOSED_PRINCIPLE_SPECIFICATION_H
#define OPEN_CLOSED_PRINCIPLE_SPECIFICATION_H


template <typename T>
struct Specification {
    virtual bool is_statisfied(T* item) = 0;
};


#endif //OPEN_CLOSED_PRINCIPLE_SPECIFICATION_H
