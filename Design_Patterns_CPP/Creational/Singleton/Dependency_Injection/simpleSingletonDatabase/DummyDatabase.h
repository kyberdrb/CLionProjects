//
// Created by laptop on 8/1/19.
//

#ifndef DEPENDENCY_INJECTION_DUMMYDATABASE_H
#define DEPENDENCY_INJECTION_DUMMYDATABASE_H

#include <string>
#include <map>
#include "Database.h"

class DummyDatabase : public Database {
    std::map<std::string, int> capitals;

public:
    DummyDatabase() {
        capitals["alpha"] = 1;
        capitals["beta"] = 2;
        capitals["gamma"] = 3;
    }

    int getPopulation(const std::string &cityName) override {
        return capitals[cityName];
    }
};

#endif //DEPENDENCY_INJECTION_DUMMYDATABASE_H
