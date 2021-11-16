cmake_minimum_required(VERSION 3.15)
project(Shapes_Templated_factory_CRTP)

set(CMAKE_CXX_STANDARD 14)

add_executable(Shapes_Templated_factory_CRTP main.cpp shapes/Shape.h shapes/square/SquareDimension.cpp shapes/square/SquareDimension.h shapes/square/Square.cpp shapes/square/Square.h shapes/rectangle/RectangleDimension.cpp shapes/rectangle/RectangleDimension.h shapes/rectangle/Rectangle.cpp shapes/rectangle/Rectangle.h shapes/circle/CircleDimension.cpp shapes/circle/CircleDimension.h shapes/circle/Circle.cpp shapes/circle/Circle.h)
