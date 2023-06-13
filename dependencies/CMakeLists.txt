add_subdirectory(message_thread)

if (CMAKE_TESTING_ENABLED)
    # If testing is enabled, add tests
    target_include_directories(
        obrttgUnitTests
        PRIVATE
            message_thread/include
            msgpack-c/include
    )
endif()