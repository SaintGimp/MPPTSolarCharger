target_sources(trinket
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/ringbuffer.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/ringbuffer.h"
)

target_include_directories(trinket PUBLIC "${CMAKE_CURRENT_LIST_DIR}")