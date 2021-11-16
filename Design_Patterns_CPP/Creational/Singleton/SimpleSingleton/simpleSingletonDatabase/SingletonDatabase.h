//
// Created by laptop on 8/1/19.
//

#ifndef SINGLETON_SINGLETONDATABASE_H
#define SINGLETON_SINGLETONDATABASE_H


#include <string>
#include <map>
#include <fstream>
#include <iostream>

class SingletonDatabase {
private:
    std::map<std::string, std::string> capitals;

    SingletonDatabase();

public:
    SingletonDatabase(const SingletonDatabase&) = delete;
    void operator=(const SingletonDatabase&) = delete;

    static SingletonDatabase& get();
    std::string getPopulation(const std::string& cityName);
};


#endif //SINGLETON_SINGLETONDATABASE_H
