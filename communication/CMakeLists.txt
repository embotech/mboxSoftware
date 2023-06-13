find_package(Threads)

add_library(MavlinkInterface STATIC)

add_subdirectory(incaslib)

target_sources(
    MavlinkInterface 
    PRIVATE
        src/mavlink_interface.cpp
        src/mavlink_tools.cpp
)

target_include_directories(
    MavlinkInterface 
    PUBLIC
        include
        ${CMAKE_SOURCE_DIR}/obrttg/include
        ${CMAKE_SOURCE_DIR}/codegen/otherFiles/include
        ${CMAKE_SOURCE_DIR}/logging/include
        ${CMAKE_SOURCE_DIR}/dependencies/msgpack-c/include
)


target_link_libraries(
    MavlinkInterface 
    PUBLIC  
        MboxUtils
        MboxLogger
        MboxInputParser
        messageThread
        Threads::Threads
        rt
)

if (CMAKE_TESTING_ENABLED)
    target_include_directories(
        obrttgUnitTests
        PRIVATE
            tests
            include
            tests/include
    )
    target_sources(
        obrttgUnitTests
        PUBLIC
            src/mavlink_interface.cpp
            src/mavlink_tools.cpp
            tests/mavlink_tools_test.cpp
            tests/src/mock_onboard_computer.cpp
            tests/mavlink_interface_test.cpp
    )
    target_link_libraries(
        obrttgUnitTests
            PUBLIC  
            Threads::Threads
    )
endif()
