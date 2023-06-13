file(GLOB GNC_GUIDANCE_SOURCES ${GNC_GUIDANCE_REF}*.c)

add_library(CodegenObrttgGuidance STATIC)

target_sources(
    CodegenObrttgGuidance
    PRIVATE
        ${GNC_GUIDANCE_SOURCES}
)

target_include_directories(
    CodegenObrttgGuidance
    PRIVATE
)

target_include_directories(
    CodegenObrttgGuidance
    PUBLIC 
        .
)

target_link_libraries(
    CodegenObrttgGuidance
    PRIVATE
        CodegenObrttgCommon
        CodegenObrttgRTLogging
)

if (CMAKE_TESTING_ENABLED)
    target_sources(
        obrttgUnitTests
        PRIVATE
            ${GNC_GUIDANCE_SOURCES}
    )

    target_include_directories(
        obrttgUnitTests
        PRIVATE
            .
    )
endif()