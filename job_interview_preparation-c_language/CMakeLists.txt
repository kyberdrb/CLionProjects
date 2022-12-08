cmake_minimum_required(VERSION 3.24)
project(job_interview_preparation_c_language C)

set(CMAKE_C_STANDARD 11)

add_executable(job_interview_preparation_c_language main.c realloc_example.h realloc_example.c string_examples.c string_examples.h struct_examples.c struct_examples.h delimiter.c delimiter.h shallow_deep_copy.c shallow_deep_copy.h string_factory.c string_factory.h algorithm_exercise.c algorithm_exercise.h one_dimensional_array.c one_dimensional_array.h two_dimensional_array.c two_dimensional_array.h)
