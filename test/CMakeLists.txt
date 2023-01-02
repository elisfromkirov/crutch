add_executable(crutch_test)

file(GLOB_RECURSE CRUTCH_TESTS_INCLUDES *.hpp)
file(GLOB_RECURSE CRUTCH_TESTS_SOURCES *.cpp)

message(${CRUTCH_TESTS_SOURCES})

target_sources(crutch_test
    PUBLIC
        ${CRUTCH_TESTS_SOURCES}
    PRIVATE
        ${CRUTCH_TESTS_SOURCES}
    )

target_link_libraries(crutch_test
    PUBLIC
        crutch
    )