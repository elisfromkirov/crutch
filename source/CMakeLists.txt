add_library(crutch)

file(GLOB_RECURSE CRUTCH_INCLUDE *.hpp)
file(GLOB_RECURSE CRUTCH_SOURCE *.cpp)

target_include_directories(crutch
    PUBLIC
        .
    )

target_sources(crutch
    PUBLIC
        ${CRUTCH_INCLUDE}
    PRIVATE
        ${CRUTCH_SOURCE}
    )