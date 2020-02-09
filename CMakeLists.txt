
cmake_minimum_required(VERSION 3.15)

project(Wasm)

set(EXECUTABLE_NAME yoga)
set(CMAKE_VERBOSE_MAKEFILE 0)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

file(GLOB SOURCES src/*.cpp)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/public")
add_executable(${EXECUTABLE_NAME} ${SOURCES})

message(STATUS "Setting compilation target to WASM")
set(CMAKE_EXECUTABLE_SUFFIX ".js")
set_target_properties(${EXECUTABLE_NAME}
        PROPERTIES LINK_FLAGS "-s WASM=1 -s NO_EXIT_RUNTIME=1 -s BINARYEN_METHOD='native-wasm' -s EXTRA_EXPORTED_RUNTIME_METHODS=['ccall']")
