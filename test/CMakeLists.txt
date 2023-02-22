add_executable(wheel_tests)

file(GLOB_RECURSE wheel_TESTS_INCLUDE *.hpp)
file(GLOB_RECURSE wheel_TESTS_SOURCE *.cpp)

target_include_directories(wheel_tests
    PUBLIC
        .
)

target_sources(wheel_tests
    PUBLIC
        ${wheel_TESTS_INCLUDE}
    PRIVATE
        ${wheel_TESTS_SOURCE}
    )

target_link_libraries(wheel_tests
    PUBLIC
        wheel
    )