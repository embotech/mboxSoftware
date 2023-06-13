add_library(MboxUtils STATIC)

target_include_directories(
    MboxUtils 
    PUBLIC
        include    
)

target_sources(
    MboxUtils 
    PRIVATE
        src/watchdog.cpp
)


# If testing is enabled, add tests folder
if(CMAKE_TESTING_ENABLED)
    target_sources(
        obrttgUnitTests
        PRIVATE
            tests/mimap_test.cpp
            tests/watchdog_test.cpp
            tests/src/struct_comparator.cpp
            src/obrttg_types_utils.cpp
            src/watchdog.cpp
    )
    target_include_directories(
        obrttgUnitTests
        PRIVATE
            include
            tests/include
    )
endif()
