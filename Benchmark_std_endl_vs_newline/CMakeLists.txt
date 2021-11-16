cmake_minimum_required(VERSION 3.14)
project(Benchmark_std_endl_vs_newline)

set(CMAKE_CXX_STANDARD 17)

add_executable(Benchmark_std_endl_vs_newline main.cpp EndlBenchmark.h NewlineCharBenchmark.h NewLineBenchmark.h Benchmarker.h)