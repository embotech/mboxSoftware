add_library(CodegenObrttgMvm STATIC)

file(GLOB GNC_MVM_SOURCES ${GNC_MVM_REF}*.c)

target_sources(
    CodegenObrttgMvm
    PRIVATE
        ${GNC_MVM_SOURCES}
)

target_include_directories(
    CodegenObrttgMvm
    PRIVATE
)

target_include_directories(
    CodegenObrttgMvm
    PUBLIC 
        .
)

target_link_libraries(
    CodegenObrttgMvm
    PRIVATE
        CodegenObrttgCommon
        CodegenObrttgRTLogging
)

if (CMAKE_TESTING_ENABLED)

    target_sources(
        obrttgUnitTests
        PRIVATE
            ${GNC_MVM_SOURCES}
    )

    target_include_directories(
        obrttgUnitTests
        PRIVATE
            .
    )

endif()