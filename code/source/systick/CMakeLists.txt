target_sources(trinket
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/systick.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/systick.h"
)

target_include_directories(trinket PUBLIC "${CMAKE_CURRENT_LIST_DIR}")