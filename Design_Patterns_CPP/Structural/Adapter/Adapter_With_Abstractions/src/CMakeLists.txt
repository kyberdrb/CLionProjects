add_executable(Adapter_With_Abstractions main.cpp target/AbstractPlug.h target/Plug.h adaptee/AbstractSwitchBoard.h adaptee/SwitchBoard.cpp adaptee/SwitchBoard.h adapter/Adapter.h target/Plug.cpp adapter/Adapter.cpp)

add_library(Adapter_With_Abstractions_library)
target_sources(
        Adapter_With_Abstractions_library
        PRIVATE
        adaptee/SwitchBoard.cpp target/Plug.cpp

        PUBLIC
        target/AbstractPlug.h target/Plug.h adaptee/AbstractSwitchBoard.h adaptee/SwitchBoard.h adapter/Adapter.h
)

target_include_directories(
        Adapter_With_Abstractions_library
        PUBLIC
            ${CMAKE_CURRENT_LIST_DIR}
)
