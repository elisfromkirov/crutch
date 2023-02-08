add_executable(crutch_tests)

file(GLOB_RECURSE CRUTCH_TESTS_INCLUDE *.hpp)
file(GLOB_RECURSE CRUTCH_TESTS_SOURCE *.cpp)

target_include_directories(crutch_tests
    PUBLIC
        .
)

target_sources(crutch_tests
    PUBLIC
        ${CRUTCH_TESTS_INCLUDE}
    PRIVATE
        ${CRUTCH_TESTS_SOURCE}
    )

target_link_libraries(crutch_tests
    PUBLIC
        crutch
    )