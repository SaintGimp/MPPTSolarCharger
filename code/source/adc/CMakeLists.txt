target_sources(trinket
    PRIVATE
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/adc_single_shot.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/adc_single_shot.h"
)

target_include_directories(trinket PUBLIC "${CMAKE_CURRENT_LIST_DIR}")