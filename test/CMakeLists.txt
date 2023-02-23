add_executable(wheels_tests)

file(GLOB_RECURSE WHEELS_TESTS_INCLUDE *.hpp)
file(GLOB_RECURSE WHEELS_TESTS_SOURCE *.cpp)

target_include_directories(wheels_tests
    PUBLIC
        .
)

target_sources(wheels_tests
    PUBLIC
        ${WHEELS_TESTS_INCLUDE}
    PRIVATE
        ${WHEELS_TESTS_SOURCE}
    )

target_link_libraries(wheels_tests
    PUBLIC
        wheels
    )