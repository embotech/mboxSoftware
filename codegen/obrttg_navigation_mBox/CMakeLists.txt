add_library(CodegenObrttgNavigation STATIC)

file(GLOB GNC_NAVIGATION_SOURCES ${GNC_NAVIGATION_REF}*.c)

target_sources(
    CodegenObrttgNavigation
    PRIVATE
        ${GNC_NAVIGATION_SOURCES}
)

target_include_directories(
    CodegenObrttgNavigation
    PUBLIC
        .
)

target_link_libraries(
    CodegenObrttgNavigation
    PRIVATE
        CodegenObrttgCommon
        CodegenObrttgRTLogging
)

if (CMAKE_TESTING_ENABLED)

    target_sources(
        obrttgUnitTests
        PRIVATE
            ${GNC_NAVIGATION_SOURCES}
    )

    target_include_directories(
        obrttgUnitTests
        PRIVATE
            .
    )

endif()