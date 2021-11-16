//
// Created by laptop on 8/1/19.
//

#ifndef DEPENDENCY_INJECTION_DATABASE_H
#define DEPENDENCY_INJECTION_DATABASE_H

class Database {
public:
    virtual int getPopulation(const std::string& cityName) = 0;
};

#endif //DEPENDENCY_INJECTION_DATABASE_H
