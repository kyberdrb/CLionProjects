cmake_minimum_required(VERSION 3.15)
project(NeuralNetworks)

set(CMAKE_CXX_STANDARD 14)

add_executable(NeuralNetworks main.cpp NeuronIdPool.h SingleNeuron.h NeuralLayer.h Neurons.h)