#include <iostream>
#include <map>
#include "simpleSingletonDatabase/SingletonDatabase.h"

int main() {
    std::string cityName{"Tokyo"};
    std::string population{SingletonDatabase::get().getPopulation("Tokyo")};
    std::cout   << cityName << " has " << population << " citizens" << "\n";

    return 0;
}