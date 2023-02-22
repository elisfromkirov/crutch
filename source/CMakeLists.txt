add_library(wheel)

file(GLOB_RECURSE wheel_INCLUDE *.hpp)
file(GLOB_RECURSE wheel_SOURCE *.cpp)

target_include_directories(wheel
    PUBLIC
        .
    )

target_sources(wheel
    PUBLIC
        ${wheel_INCLUDE}
    PRIVATE
        ${wheel_SOURCE}
    )