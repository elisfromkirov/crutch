cmake_minimum_required(VERSION 3.21)
project(crutch)

set(CMAKE_CXX_STANDARD 20)

option(ADDRESS_SANITIZER "enable address sanitizer" OFF)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options("-Wall")
    add_compile_options("-Wextra")
    add_compile_options("-Wpedantic")
    add_compile_options("-g")
    if(ADDRESS_SANITIZER)
        add_compile_options("-fsanitize=address")
        add_link_options("-fsanitize=address")
    else()
        # nothing more
    endif()
else()
    add_compile_options("-Wall")
    add_compile_options("-Wextra")
    add_compile_options("-Wpedantic")
endif()

add_subdirectory(source)
add_subdirectory(test)
add_subdirectory(third_party)