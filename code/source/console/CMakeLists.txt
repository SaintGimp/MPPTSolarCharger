target_sources(trinket
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/console_commands.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/console_io.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/console_internal.cpp"
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/console.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/console.h"
        "${CMAKE_CURRENT_LIST_DIR}/console_commands.h"
        "${CMAKE_CURRENT_LIST_DIR}/console_io.h"
)

target_include_directories(trinket PUBLIC "${CMAKE_CURRENT_LIST_DIR}")