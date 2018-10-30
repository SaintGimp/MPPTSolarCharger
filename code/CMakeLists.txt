cmake_minimum_required(VERSION 3.3)
project(trinket)

# C++ flags
# TODO: experiment with -fstack-protector-strong 
set(CMAKE_CXX_FLAGS  "${COMMON_FLAGS} -Og -ffunction-sections -fdata-sections -mlong-calls -g3 -Wall -std=gnu++14 -fno-threadsafe-statics -fno-rtti -fno-exceptions -fno-non-call-exceptions -fno-use-cxa-atexit -D__SAMD21E18A__")

# Set the offset for the start of the application to leave room for the bootloader.
# TODO: experiment with -specs=nosys.specs
# -lc -u _printf_float is to add printf float support, costs ~8K in binary size
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wl,--section-start=.text=0x2000 -lc -u _printf_float")

# Target built with atmel start configuration
atstart_add_executable(trinket "")

include(source/CMakeLists.txt)

# Target to upload binary using bossac.
add_custom_target(
    upload
    COMMAND bossac --port=/dev/cu.usbmodem1421 -i -d -e -w -R -v ${CMAKE_BINARY_DIR}/trinket.bin
    DEPENDS ${CMAKE_BINARY_DIR}/trinket.bin
)