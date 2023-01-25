add_executable(crutch_test)

file(GLOB_RECURSE CRUTCH_TESTS_INCLUDE *.hpp)
file(GLOB_RECURSE CRUTCH_TESTS_SOURCE *.cpp)

message(${CRUTCH_TESTS_SOURCE})

target_sources(crutch_test
    PUBLIC
        ${CRUTCH_TESTS_INCLUDE}
    PRIVATE
        ${CRUTCH_TESTS_SOURCE}
    )

target_link_libraries(crutch_test
    PUBLIC
        crutch
    )