add_library(MboxLogger STATIC)

target_sources(
    MboxLogger
    PRIVATE
        src/log_processor.cpp
        src/msgpack_parse_utils.cpp
)

target_include_directories(
    MboxLogger 
    PUBLIC
        include
        ${CMAKE_SOURCE_DIR}/dependencies/msgpack-c/include
        ${CMAKE_SOURCE_DIR}/obrttg/include
)

if (CMAKE_TESTING_ENABLED)
    # If testing is enabled, add tests
    target_sources(
        obrttgUnitTests
        PUBLIC
            tests/log_processor_test.cpp
            src/log_processor.cpp
            src/msgpack_parse_utils.cpp
    )
    target_include_directories(
        obrttgUnitTests
        PRIVATE
            include
    )
endif()