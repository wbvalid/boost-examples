cmake_minimum_required(VERSION 3.13)
project(boost-example)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(getopts opts/getopts.cpp)
target_link_libraries(getopts boost_program_options)
