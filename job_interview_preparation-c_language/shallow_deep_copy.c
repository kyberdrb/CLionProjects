//
// Created by laptop on 11/29/22.
//

#include "shallow_deep_copy.h"

#include "delimiter.h"
#include "string_factory.h"

#include <stdio.h>
#include <string.h>

void test_shallow_copy_for_stack_allocated_instance() {
    hydro_metheorological_indicators_t hydroMetheorologicalIndicatorsOnStack;
    hydroMetheorologicalIndicatorsOnStack.amountOfCarbonDioxideInAtmosphereIn_ppm = 417.31;
    hydroMetheorologicalIndicatorsOnStack.soilQuality = 'B';
    hydroMetheorologicalIndicatorsOnStack.rainfallIn_mm = 0.51;

    uint8_t currentWeatherLength = 29;
    hydroMetheorologicalIndicatorsOnStack.currentWeather = create_empty_string(currentWeatherLength);
    strcpy(hydroMetheorologicalIndicatorsOnStack.currentWeather, "cloudy");

    printOriginalPassedByPointer(&hydroMetheorologicalIndicatorsOnStack);
    printShallowCopyPassedByValue(hydroMetheorologicalIndicatorsOnStack);

    destroy_string(hydroMetheorologicalIndicatorsOnStack.currentWeather);

    print_delimiter();
}

void printShallowCopyPassedByValue(hydro_metheorological_indicators_t hmi) {
    printf("%s %p: %.2f  |  %s %p: %c  |  %s %p: %.2f  |  %s %p: %s\n",
           "CO2:",
           &(hmi.amountOfCarbonDioxideInAtmosphereIn_ppm),
           hmi.amountOfCarbonDioxideInAtmosphereIn_ppm,

           "soilQuality:",
           &(hmi.soilQuality),
           hmi.soilQuality,

           "rainfallIn_mm:",
           &hmi.rainfallIn_mm,
           hmi.rainfallIn_mm,

           "currentWeather:",
           hmi.currentWeather,
           hmi.currentWeather);
}

void printOriginalPassedByPointer(const hydro_metheorological_indicators_t* const hmi) {
    printf("%s %p: %.2f  |  %s %p: %c  |  %s %p: %.2f  |  %s %p: %s\n",
           "CO2:",
           &hmi->amountOfCarbonDioxideInAtmosphereIn_ppm,
           hmi->amountOfCarbonDioxideInAtmosphereIn_ppm,

           "soilQuality:",
           &hmi->soilQuality,
           hmi->soilQuality,

           "rainfallIn_mm:",
           &(hmi->rainfallIn_mm),
           hmi->rainfallIn_mm,

           "currentWeather:",
            hmi->currentWeather,
            hmi->currentWeather);
}