add_executable(Factory_Unique_Ptr)
target_sources(
        Factory_Unique_Ptr

        PRIVATE
        main.cpp
        shapes/ShapeFactory.cpp
        shapes/ShapeFactory.h
        shapes/ShapeType.h
        shapes/Shape.h
        shapes/Circle.h
        shapes/Square.h
        shapes/NullShape.h
)

add_library(Factory_Unique_Ptr_library)
set_target_properties(Factory_Unique_Ptr_library PROPERTIES LINKER_LANGUAGE CXX)
target_sources(
        Factory_Unique_Ptr_library

        PRIVATE
        shapes/ShapeFactory.cpp

        PUBLIC
        shapes/ShapeFactory.h
        shapes/ShapeType.h
        shapes/Shape.h
        shapes/Circle.h
        shapes/Square.h
        shapes/NullShape.h
)

target_include_directories(
        Factory_Unique_Ptr_library

        PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}
)
