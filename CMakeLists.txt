
cmake_minimum_required(VERSION 3.15)

project(Wasm)

set(EXECUTABLE_NAME yoga)
set(CMAKE_VERBOSE_MAKEFILE 0)
set(CMAKE_CXX_STANDARD 17)

option(JS_ONLY "Compiles to native JS (No WASM)" OFF)

include_directories(include)

file(GLOB SOURCES src/*.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/public")
add_executable(${EXECUTABLE_NAME} ${SOURCES})

if(JS_ONLY)
    message(STATUS "Setting compilation target to native JavaScript")
    set(CMAKE_EXECUTABLE_SUFFIX ".js")
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES LINK_FLAGS "-s EXPORTED_FUNCTIONS='[_main]'")
else()
    message(STATUS "Setting compilation target to WASM")
    set(CMAKE_EXECUTABLE_SUFFIX ".js")
    set_target_properties(${EXECUTABLE_NAME} PROPERTIES LINK_FLAGS "-s WASM=1 -s BINARYEN_METHOD='native-wasm' -s EXPORTED_FUNCTIONS='[_main]'")
endif()