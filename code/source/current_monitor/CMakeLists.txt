target_sources(trinket
    PRIVATE
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/ina260.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/ina260.h"
)

target_include_directories(trinket PUBLIC "${CMAKE_CURRENT_LIST_DIR}")