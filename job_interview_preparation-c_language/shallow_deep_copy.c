//
// Created by laptop on 11/29/22.
//

#include "shallow_deep_copy.h"

#include "delimiter.h"
#include "string_factory.h"

#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void test_shallow_copy_for_stack_allocated_instance() {
    hydro_metheorological_indicators_t hydroMetheorologicalIndicatorsOnStack;

    // constructor/initialization
    hydroMetheorologicalIndicatorsOnStack.amountOfCarbonDioxideInAtmosphereIn_ppm = 417.31;
    hydroMetheorologicalIndicatorsOnStack.soilQuality = 'B';
    hydroMetheorologicalIndicatorsOnStack.rainfallIn_mm = 0.51;
    hydroMetheorologicalIndicatorsOnStack.warnings = NONE;

    uint8_t currentWeatherLength = 29;
    hydroMetheorologicalIndicatorsOnStack.currentWeather = create_empty_string(currentWeatherLength);
    strcpy(hydroMetheorologicalIndicatorsOnStack.currentWeather, "cloudy");

    // print original and copy passed by value and by pointer
    printf("%s: %p\n", "Original - address:", (void *) &hydroMetheorologicalIndicatorsOnStack);
    printf("%s\n", "Original - passed by address");
    printStructPassedByPointer(&hydroMetheorologicalIndicatorsOnStack);
    printf("%s\n", "Original - passed by value");
    printStructPassedByValue(hydroMetheorologicalIndicatorsOnStack);

    // create a shallow copy on stack based off the original instance
    hydro_metheorological_indicators_t hydroMetheorologicalIndicatorsOnStackShallowCopy = hydroMetheorologicalIndicatorsOnStack;
    
    printf("%s: %p\n", "Shallow copy - address:", &hydroMetheorologicalIndicatorsOnStackShallowCopy);
    printf("%s\n", "Shallow copy - passed by address - before modification");
    printStructPassedByPointer(&hydroMetheorologicalIndicatorsOnStackShallowCopy);
    printf("%s\n", "Shallow copy - passed by value - before modification");
    printStructPassedByValue(hydroMetheorologicalIndicatorsOnStackShallowCopy);

    printf("\n");
    
    printf("%s\n", "Modify all basic type member variables of the copy except the reference member variable to prove that the primitive data types are copied deeply");

    modifyBasicMemberVariablesOfInstancePassedByValue(hydroMetheorologicalIndicatorsOnStackShallowCopy);

    printf("%s\n", "Shallow copy - after modification - copy passed to the modification function by value - all changes are lost");
    printStructPassedByPointer(&hydroMetheorologicalIndicatorsOnStackShallowCopy);
    printf("%s\n", "Original - left as is");
    printStructPassedByPointer(&hydroMetheorologicalIndicatorsOnStack);

    printf("\n");

    modifyBasicMemberVariablesOfInstancePassedByAddress(&hydroMetheorologicalIndicatorsOnStackShallowCopy);

    printf("%s\n", "Shallow copy - after modification - passing to the modification function by address/pointer - all changes persisted");
    printStructPassedByPointer(&hydroMetheorologicalIndicatorsOnStackShallowCopy);
    printf("%s\n", "Original - left as is");
    printStructPassedByPointer(&hydroMetheorologicalIndicatorsOnStack);

    printf("\n");

    printf("%s\n", "Modify the content of the reference variable in the shallow copy to prove that the references are shared among the original and its copies - shared resource");

    modifyContentOfReferenceMemberVariableOfInstancePassedByValue(hydroMetheorologicalIndicatorsOnStackShallowCopy);

    printf("%s\n", "Shallow copy - after modification - copy passed to the modification function by value - the changes to the reference variable are preserved");
    printStructPassedByPointer(&hydroMetheorologicalIndicatorsOnStackShallowCopy);
    printf("%s\n", "Original - the reference variable changed too - the resource is shared");
    printStructPassedByPointer(&hydroMetheorologicalIndicatorsOnStack);

    printf("\n");

    modifyContentOfReferenceMemberVariableOfInstancePassedByAddress(&hydroMetheorologicalIndicatorsOnStackShallowCopy);

    printf("%s\n", "Shallow copy - after modification - copy passed to the modification function by address/pointer/reference - the changes to the reference variable are preserved");
    printStructPassedByPointer(&hydroMetheorologicalIndicatorsOnStackShallowCopy);
    printf("%s\n", "Original - the reference variable changed too - the resource is shared");
    printStructPassedByPointer(&hydroMetheorologicalIndicatorsOnStack);

    printf("\n");

    // destroy inner state of the original
    destroy_inner_state(&hydroMetheorologicalIndicatorsOnStack);

    printf("%s\n", "Original - passed by address");
    printStructPassedByPointer(&hydroMetheorologicalIndicatorsOnStack);

    // printing the reference variable of the copy would result in undefined behavior
//    printf("%s\n", "Shallow copy - passed by address");
//    printStructPassedByPointer(&hydroMetheorologicalIndicatorsOnStackShallowCopy);

    printf("\n%s\n%s\n%s\n\n",
           "Reference attribute in original instance had been deallocated and set to NULL (to sanitize dangling pointer).",
           "Sanitize dangling pointer in reference member variable in shallow copy, i.e. all shallow copies,",
           "to prevent undefined behavior by deallocating an already deallocated pointer - a dangling pointer.");
    hydroMetheorologicalIndicatorsOnStackShallowCopy.currentWeather = NULL;

    printf("%s\n", "Shallow copy - passed by address");
    printStructPassedByPointer(&hydroMetheorologicalIndicatorsOnStackShallowCopy);

    // destroy inner state of the shallow copy
    printf("\n");
    destroy_inner_state(&hydroMetheorologicalIndicatorsOnStackShallowCopy);
    printf("\n");

    printf("%s\n", "Shallow copy - passed by address");
    printStructPassedByPointer(&hydroMetheorologicalIndicatorsOnStackShallowCopy);

    print_delimiter();
}

void printStructPassedByValue(hydro_metheorological_indicators_t hmi) {
    printf("%s %p: %.2f  |  %s %p: %c  |  %s %p: %.2f  |  %s %p: %d  |  %s %p; %p: %s\n",
           "CO2:",
           &(hmi.amountOfCarbonDioxideInAtmosphereIn_ppm),
           hmi.amountOfCarbonDioxideInAtmosphereIn_ppm,

           "soilQuality:",
           &(hmi.soilQuality),
           hmi.soilQuality,

           "rainfallIn_mm:",
           &hmi.rainfallIn_mm,
           hmi.rainfallIn_mm,

           "warnings:",
           &hmi.warnings,
           hmi.warnings,

           "currentWeather:",
           &hmi.currentWeather,
           hmi.currentWeather,
           hmi.currentWeather);
}

void printStructPassedByPointer(const hydro_metheorological_indicators_t* const hmi) {
    printf("%s %p: %.2f  |  %s %p: %c  |  %s %p: %.2f  |  %s %p: %d  |  %s %p; %p: ",
           "CO2:",
           &hmi->amountOfCarbonDioxideInAtmosphereIn_ppm,
           hmi->amountOfCarbonDioxideInAtmosphereIn_ppm,

           "soilQuality:",
           &hmi->soilQuality,
           hmi->soilQuality,

           "rainfallIn_mm:",
           &(hmi->rainfallIn_mm),
           hmi->rainfallIn_mm,

           "warnings:",
           &hmi->warnings,
           hmi->warnings,

           "currentWeather:",
           &hmi->currentWeather,
           hmi->currentWeather);

    // Ommit dereferencing the string to the output when pointer is set to NULL
    bool stringHadBeenDeallocatedOrNotAllocatedAtAll = hmi->currentWeather == NULL;
    if (stringHadBeenDeallocatedOrNotAllocatedAtAll) {
        printf("%s\n", "<deallocated/not allocated>");
        return;
    }

    printf("%s\n", hmi->currentWeather);
}

void modifyBasicMemberVariablesOfInstancePassedByValue(hydro_metheorological_indicators_t hmi) {
    hmi.amountOfCarbonDioxideInAtmosphereIn_ppm = 326.42;
    hmi.soilQuality = 'A';
    hmi.rainfallIn_mm = 1.72;
    hmi.warnings = ICING;

    printf("%s\n", "Inside modifying function - Modifying copy of the instance passed to the parameter by value - inner state of a copied parameter instance");
    printStructPassedByPointer(&hmi);
}

void modifyBasicMemberVariablesOfInstancePassedByAddress(hydro_metheorological_indicators_t* hmi) {
    hmi->amountOfCarbonDioxideInAtmosphereIn_ppm = 326.42;
    hmi->soilQuality = 'A';
    hmi->rainfallIn_mm = 1.72;
    hmi->warnings = ICING;

    printf("%s\n", "Inside modifying function - Modifying the instance directly passed to the parameter by address/pointer - inner state of the referred instance inside modifying function");
    printStructPassedByPointer(hmi);
}

void modifyContentOfReferenceMemberVariableOfInstancePassedByValue(hydro_metheorological_indicators_t hmi) {
    // encapsulate to function 'overwrite_currentWeather(char* text)'
    memset(hmi.currentWeather, 0, 30);
    strcpy(hmi.currentWeather, "precipitation");

    printf("%s\n", "Inside modifying function - Modifying the instance directly passed to the parameter by address/pointer - inner state of the referred instance inside modifying function");
    printStructPassedByPointer(&hmi);
}

void modifyContentOfReferenceMemberVariableOfInstancePassedByAddress(hydro_metheorological_indicators_t* hmi) {
    // encapsulate to function 'overwrite_currentWeather(char* text)'
    memset(hmi->currentWeather, 0, 30);
    strcpy(hmi->currentWeather, "rain");

    printf("%s\n", "Inside modifying function - Modifying the instance directly passed to the parameter by address/pointer - inner state of the referred instance inside modifying function");
    printStructPassedByPointer(hmi);
}

void destroy_inner_state(hydro_metheorological_indicators_t* const hmi) {
    if (hmi->currentWeather != NULL) { //
//        destroy_string(&hmi->currentWeather); // used by ineffective 'void destroy_string(char* text);' which only sanitized a copy of the dangling pointer,
                                                // not the original one passed to the function - therefore using another level of indirection: pointer to pointer to char
        destroy_string(&(hmi->currentWeather));
        return;
    }
    
    printf("%s\n", "Either the string has not been allocated yet, or the string has already been deallocated.");
}

//void test_deep_copy_for_stack_allocated_instance() {
//    // constructor
//    hydro_metheorological_indicators_t hydroMetheorologicalIndicatorsOnStack;
//    hydroMetheorologicalIndicatorsOnStack.amountOfCarbonDioxideInAtmosphereIn_ppm = 417.31;
//    hydroMetheorologicalIndicatorsOnStack.soilQuality = 'B';
//    hydroMetheorologicalIndicatorsOnStack.rainfallIn_mm = 0.51;
//
//    uint8_t currentWeatherLength = 29;
//    hydroMetheorologicalIndicatorsOnStack.currentWeather = create_empty_string(currentWeatherLength);
//    strcpy(hydroMetheorologicalIndicatorsOnStack.currentWeather, "cloudy");
//
//    printStructPassedByPointer(&hydroMetheorologicalIndicatorsOnStack);
//    printStructPassedByValue(hydroMetheorologicalIndicatorsOnStack);
//
//    // copy constructor
//    hydro_metheorological_indicators_t hydroMetheorologicalIndicatorsOnStackCopy = hydroMetheorologicalIndicatorsOnStack;
//    printStructPassedByPointer(&hydroMetheorologicalIndicatorsOnStackCopy);
//    printStructPassedByValue(hydroMetheorologicalIndicatorsOnStackCopy);
//
//    // deep copy construction
//    hydroMetheorologicalIndicatorsOnStackCopy.currentWeather = create_empty_string(29);
//    strcpy(hydroMetheorologicalIndicatorsOnStackCopy.currentWeather, "overcast");
//    printStructPassedByPointer(&hydroMetheorologicalIndicatorsOnStackCopy);
//    printStructPassedByValue(hydroMetheorologicalIndicatorsOnStackCopy);
//
//    // destructor
//    destroy_string(hydroMetheorologicalIndicatorsOnStack.currentWeather);
//    destroy_string(hydroMetheorologicalIndicatorsOnStackCopy.currentWeather);
//
//    print_delimiter();
//}