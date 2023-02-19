cmake_minimum_required(VERSION 3.21)
project(crutch)

set(CMAKE_CXX_STANDARD 20)

option(ADDRESS_SANITIZER "enable address sanitizer" OFF)

option(DEVELOPER "enable tests" OFF)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_options("-Wall")
    add_compile_options("-Wextra")
    add_compile_options("-Wpedantic")
    add_compile_options("-g")
    add_compile_options("-DON_DEBUG")
    if(ADDRESS_SANITIZER)
        add_compile_options("-fsanitize=address")
        add_link_options("-fsanitize=address")
        add_compile_options("-DON_ADDRESS_SANITIZER")
    else()
        # nothing more
    endif()
else()
    add_compile_options("-Wall")
    add_compile_options("-Wextra")
    add_compile_options("-Wpedantic")
endif()

add_subdirectory(source)

if (DEVELOPER)
    add_subdirectory(test)
endif()

add_subdirectory(third_party)