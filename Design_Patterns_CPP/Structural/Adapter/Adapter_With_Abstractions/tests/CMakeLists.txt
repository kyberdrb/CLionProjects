add_executable(unit_tests ExampleTestSuite.cpp)

target_link_libraries(
        unit_tests
        gtest_main
        Adapter_With_Abstractions_library
)

add_test(
        NAME
            unit
        COMMAND
            ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}
)