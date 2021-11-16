add_executable(unit_tests)
target_sources(
        unit_tests

        PRIVATE
        CircleTestSuite.cpp
        SquareTestSuite.cpp
        NullShapeTestSuite.cpp
)

target_link_libraries(
        unit_tests
        gtest_main
        Factory_Unique_Ptr_library
)

add_test(
        NAME unit
        COMMAND ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}
)