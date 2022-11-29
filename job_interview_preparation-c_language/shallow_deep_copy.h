//
// Created by laptop on 11/29/22.
//

#ifndef SHALLOW_DEEP_COPY_H
#define SHALLOW_DEEP_COPY_H

#include <stdint.h>

typedef struct hydro_metheorological_indicators {
    double amountOfCarbonDioxideInAtmosphereIn_ppm;
    char soilQuality;
    float rainfallIn_mm;
    char* currentWeather;
} hydro_metheorological_indicators_t;

// constructors
hydro_metheorological_indicators_t createShallowCopyByValue();
hydro_metheorological_indicators_t* createDeepCopyByPointer();

void test_shallow_copy_for_stack_allocated_instance();
void test_deep_copy_for_stack_allocated_instance();
void test_shallow_copy_for_heap_allocated_instance();
void test_deep_copy_for_heap_allocated_instance();

void printShallowCopyPassedByValue(hydro_metheorological_indicators_t hmi);
void printOriginalPassedByPointer(const hydro_metheorological_indicators_t* const hmi);

void modifyInstanceByValue(hydro_metheorological_indicators_t hmi);
void modifyInstanceByPointer(hydro_metheorological_indicators_t* hmi);

// destructors
void destroy(const hydro_metheorological_indicators_t* const hmi);

#endif
