target_sources(trinket    
    PRIVATE
        "${CMAKE_CURRENT_LIST_DIR}/main.cpp"
    PUBLIC
        "${CMAKE_CURRENT_LIST_DIR}/version.h"
)

target_include_directories(trinket PUBLIC "${CMAKE_CURRENT_LIST_DIR}")

#include(${CMAKE_CURRENT_LIST_DIR}/containers/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/console/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/systick/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/blinky/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/containers/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/adc/CMakeLists.txt)
include(${CMAKE_CURRENT_LIST_DIR}/current_monitor/CMakeLists.txt)
