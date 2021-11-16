//
// Created by laptop on 7/25/19.
//

#ifndef CPP_11_NEW_FEATURES_CHECK_H
#define CPP_11_NEW_FEATURES_CHECK_H


#include <string>

class Check {
public:
    bool operator()(std::string& word) {
        return word.size() == 5;
    }
};


#endif //CPP_11_NEW_FEATURES_CHECK_H
