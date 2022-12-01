//
// Created by laptop on 11/29/22.
//

#ifndef SHALLOW_DEEP_COPY_H
#define SHALLOW_DEEP_COPY_H

#include <stdint.h>

typedef enum warnings {
    NONE,
    ICING,
    FROST,
    WIND,
    HEAT
} warnings_t;

typedef struct hydro_metheorological_indicators {
    double amountOfCarbonDioxideInAtmosphereIn_ppm;
    char soilQuality;
    float rainfallIn_mm;
    warnings_t warnings;
    char* currentWeather;
} hydro_metheorological_indicators_t;

// constructors
//hydro_metheorological_indicators_t createShallowCopyByValue();
//hydro_metheorological_indicators_t* createDeepCopyByPointer();

void test_shallow_and_deep_copy_for_stack_allocated_instance();

// 'static' function - private function of the translation unit - a function visible only in this translation unit and hidden from outside
static void test_deep_copy_for_stack_allocated_instance();

//void test_shallow_and_deep_copy_for_heap_allocated_instance();

void printStructPassedByValue(hydro_metheorological_indicators_t hmi);
void printStructPassedByPointer(const hydro_metheorological_indicators_t* const hmi);

void modifyBasicMemberVariablesOfInstancePassedByValue(hydro_metheorological_indicators_t hmi);
void modifyBasicMemberVariablesOfInstancePassedByAddress(hydro_metheorological_indicators_t* hmi);

void modifyContentOfReferenceMemberVariableOfInstancePassedByValue(hydro_metheorological_indicators_t hmi);
void modifyContentOfReferenceMemberVariableOfInstancePassedByAddress(hydro_metheorological_indicators_t* hmi);

void reallocateReferenceMemberVariableOfInstancePassedByValue(hydro_metheorological_indicators_t hmi);
void reallocateReferenceMemberVariableOfInstancePassedByAddress(hydro_metheorological_indicators_t* hmi);

// destructors
void destroy_reference_variables_in_inner_state(hydro_metheorological_indicators_t* const hmi);
void destroy(const hydro_metheorological_indicators_t* hmi);

#endif
