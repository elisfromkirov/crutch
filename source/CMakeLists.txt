add_library(wheels)

file(GLOB_RECURSE WHEELS_INCLUDE *.hpp)
file(GLOB_RECURSE WHEELS_SOURCE *.cpp)

target_include_directories(wheels
    PUBLIC
        .
    )

target_sources(wheels
    PUBLIC
        ${WHEELS_INCLUDE}
    PRIVATE
        ${WHEELS_SOURCE}
    )