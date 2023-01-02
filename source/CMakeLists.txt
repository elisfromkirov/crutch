add_library(crutch)

file(GLOB_RECURSE CRUTCH_INCLUDES *.hpp)
file(GLOB_RECURSE CRUTCH_INLINE_INCLUDES *.ipp)
file(GLOB_RECURSE CRUTCH_SOURCES *.cpp)

message(${CRUTCH_INCLUDES})
message(${CRUTCH_SOURCES})

target_include_directories(crutch
    PUBLIC
        .
    )

target_sources(crutch
    PUBLIC
        ${CRUTCH_INCLUDES}
        ${CRUTCH_INLINE_INCLUDES}
    PRIVATE
        ${CRUTCH_SOURCES}
    )