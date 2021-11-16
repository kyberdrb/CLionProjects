//
// Created by laptop on 8/1/19.
//

#ifndef DEPENDENCY_INJECTION_SINGLETONRECORDFINDER_H
#define DEPENDENCY_INJECTION_SINGLETONRECORDFINDER_H

#include <vector>
#include <string>
#include "../simpleSingletonDatabase/SingletonDatabase.h"

struct SingletonRecordFinder {
    int totalPopulation(std::vector<std::string> names) {
        int result = 0;

        for (const auto& name : names) {
            result += SingletonDatabase::get().getPopulation(name);
        }

        return result;
    }
};

#endif //DEPENDENCY_INJECTION_SINGLETONRECORDFINDER_H
