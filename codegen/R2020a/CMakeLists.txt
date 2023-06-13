add_library(CodegenObrttgRTLogging STATIC)

target_sources(
    CodegenObrttgRTLogging
    PRIVATE
        rtw/c/src/rt_logging.c
)

target_include_directories(
    CodegenObrttgRTLogging
    PRIVATE
        rtw/c/src
        extern/include
        simulink/include
        ../commonFiles
)

if (CMAKE_TESTING_ENABLED)

    target_sources(
        obrttgUnitTests
        PRIVATE
            rtw/c/src/rt_logging.c
    )

    target_include_directories(
        obrttgUnitTests
        PRIVATE
            extern/include
            rtw/c/src
            rtw/c/src/ext_mode/common
            simulink/include
    )

endif()
