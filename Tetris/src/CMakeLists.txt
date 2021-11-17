add_executable(Tetris)
target_sources(
    Tetris

    PRIVATE
    main.cpp Game.cpp Game.h ConstructionSite.cpp ConstructionSite.h Brick.cpp Brick.h
)

add_library(tetris_library)
target_sources(
    tetris_library

    PRIVATE
    Game.cpp ConstructionSite.cpp Brick.cpp

    PUBLIC
    Game.h ConstructionSite.h Brick.h
)

target_include_directories(
    tetris_library

    PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)
