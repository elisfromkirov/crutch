cmake_minimum_required(VERSION 3.21)
project(wheels)

include(cmake/build_options.cmake)
include(cmake/compile_options.cmake)

add_subdirectory(source)

if(BUILD_WITH_TEST)
    add_subdirectory(test)
endif()

add_subdirectory(third_party)