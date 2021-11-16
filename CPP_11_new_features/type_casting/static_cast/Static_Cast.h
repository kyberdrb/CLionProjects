//
// Created by laptop on 7/29/19.
//

#ifndef CPP_11_NEW_FEATURES_STATIC_CAST_H
#define CPP_11_NEW_FEATURES_STATIC_CAST_H


#include "Parent.h"

class Static_Cast {
public:
    void exercise();

private:
    void passLvalueToRvalueParameter(Parent&&);
};


#endif //CPP_11_NEW_FEATURES_STATIC_CAST_H
