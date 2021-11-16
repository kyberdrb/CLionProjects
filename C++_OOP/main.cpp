#include <iostream>
#include <cstdint>
#include <cassert>
#include <memory>
#include "1_EXERCISE for Data Structures and Pointers/EXERCISE_for_Data_Structures_and_Pointers.h"
#include "2_EXERCISES for Object Oriented Programming Section/EXERCISES_for_Object_Oriented_Programming_Section.h"

void runExercise_1();

void runExercise_2();

int main() {
//    runExercise_1();
    runExercise_2();

    return 0;
}

void runExercise_1() {
    std::unique_ptr<EXERCISE_for_Data_Structures_and_Pointers> exercise_1(
            new EXERCISE_for_Data_Structures_and_Pointers);
    exercise_1->startExercise();
}

void runExercise_2() {
    std::unique_ptr<EXERCISES_for_Object_Oriented_Programming_Section> exercise_2(
            new EXERCISES_for_Object_Oriented_Programming_Section);
    exercise_2->startExercise();
}
