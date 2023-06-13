add_library(CodegenObrttgCommon STATIC)

target_sources(
    CodegenObrttgCommon
    PRIVATE
        rt_nonfinite.c
        rtGetInf.c
        rtGetNaN.c
)

target_include_directories(
    CodegenObrttgCommon
    PUBLIC 
        .
        ${CMAKE_CURRENT_SOURCE_DIR}/../${MATLAB_RELEASE}/extern/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../${MATLAB_RELEASE}/simulink/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../${MATLAB_RELEASE}/rtw/c/src
)

if (CMAKE_TESTING_ENABLED)
    target_sources(
        obrttgUnitTests
        PRIVATE
            rt_nonfinite.c
            rtGetInf.c
            rtGetNaN.c
    )

    target_include_directories(
        obrttgUnitTests
        PRIVATE
            .
    )
endif()