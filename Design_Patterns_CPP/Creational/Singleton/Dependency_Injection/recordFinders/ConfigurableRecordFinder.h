//
// Created by laptop on 8/1/19.
//

#ifndef DEPENDENCY_INJECTION_CONFIGURABLERECORDFINDER_H
#define DEPENDENCY_INJECTION_CONFIGURABLERECORDFINDER_H

#include <vector>
#include <string>
#include "../simpleSingletonDatabase/Database.h"

struct ConfigurableRecordFinder {
    Database& db;

    int totalPopulation(std::vector<std::string> names) {
        int result = 0;

        for (const auto& name : names) {
            result += db.getPopulation(name);
        }

        return result;
    }
};

#endif //DEPENDENCY_INJECTION_CONFIGURABLERECORDFINDER_H
