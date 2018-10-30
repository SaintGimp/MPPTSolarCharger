target_sources(trinket
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/blinky.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/blinky.h"
)

target_include_directories(trinket PUBLIC "${CMAKE_CURRENT_LIST_DIR}")