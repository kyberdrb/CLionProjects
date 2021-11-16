//
// Created by laptop on 8/1/19.
//

#ifndef SINGLETON_SINGLETONDATABASE_H
#define SINGLETON_SINGLETONDATABASE_H


#include <string>
#include <map>
#include <fstream>
#include <iostream>
#include "Database.h"

class SingletonDatabase : public Database {
private:
    std::map<std::string, int> capitals;

    SingletonDatabase();

public:
    SingletonDatabase(const SingletonDatabase&) = delete;
    void operator=(const SingletonDatabase&) = delete;

    static SingletonDatabase& get();
    int getPopulation(const std::string& cityName) override;
};


#endif //SINGLETON_SINGLETONDATABASE_H
