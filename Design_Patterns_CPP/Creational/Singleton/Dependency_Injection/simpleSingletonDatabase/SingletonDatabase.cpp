//
// Created by laptop on 8/1/19.
//

#include "SingletonDatabase.h"

SingletonDatabase::SingletonDatabase() {
    std::cout << "Initializing database..." << std::endl;

    std::ifstream ifs("capitals.txt");

    std::string cityName{};
    std::string population{};

    while (getline(ifs, cityName)) {
        getline(ifs, population);
        capitals[cityName] = std::stol(population, nullptr,10);
    }

    ifs.close();
}

SingletonDatabase &SingletonDatabase::get() {
    static SingletonDatabase db;
    return db;
}

int SingletonDatabase::getPopulation(const std::string &cityName) {
    return capitals[cityName];
}
