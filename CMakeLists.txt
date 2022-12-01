cmake_minimum_required(VERSION 3.23)
project(aoc2022)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost 1.40 COMPONENTS program_options REQUIRED)
add_subdirectory(lib/scnlib)
include_directories(${Boost_INCLUDE_DIR} include)
add_executable(out ${CMAKE_CURRENT_BINARY_DIR}/../main.cpp)
target_link_libraries(out scn::scn)