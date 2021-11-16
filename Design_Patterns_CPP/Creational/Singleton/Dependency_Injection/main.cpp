#include <iostream>
#include <map>
#include "simpleSingletonDatabase/SingletonDatabase.h"
#include "simpleSingletonDatabase/DummyDatabase.h"
#include "recordFinders/ConfigurableRecordFinder.h"
#include "recordFinders/SingletonRecordFinder.h"

void runUnitTest();

void runIntegrationTest();

int main() {
    std::string cityName{"Tokyo"};
    int population{SingletonDatabase::get().getPopulation("Tokyo")};
    std::cout  << cityName << " has " << population << " citizens" << "\n";

    // TODO link google test framework
    // TODO move all tests to google test
    std::cout << std::endl;
    runIntegrationTest();

    std::cout << std::endl;
    runUnitTest();

    return 0;
}

void runIntegrationTest() {
    SingletonRecordFinder rf;
    std::vector<std::string> cities{"Seoul", "Mexico City"};
    int totalPopulation = rf.totalPopulation(cities);
    std::cout << "Expected: " << (17500000 + 17400000) << "; " << "Got: " << totalPopulation << std::endl;
}

void runUnitTest() {
    DummyDatabase db;
    ConfigurableRecordFinder rf{db};
    int totalPopulation = rf.totalPopulation(std::vector<std::string>{"alpha", "gamma"});
    std::cout << "Expected: 4; " << "Got: " << totalPopulation << std::endl;
}
