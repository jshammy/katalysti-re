cmake_minimum_required(VERSION 3.0.0)
project(katalysti VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)

include_directories(${PROJECT_SOURCE_DIR}/include/*.hpp)
file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(katalysti ${SRC_FILES})