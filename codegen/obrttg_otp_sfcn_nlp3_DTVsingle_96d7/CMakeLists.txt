add_subdirectory(solver)

add_library(CodegenObrttgOptimalTrajectoryPlanner STATIC)

file(GLOB GNC_OTP_SOURCES ${GNC_OTP_REF}*.c)

target_sources(
    CodegenObrttgOptimalTrajectoryPlanner
    PRIVATE
        ${GNC_OTP_SOURCES}
)

target_include_directories(
    CodegenObrttgOptimalTrajectoryPlanner
    PUBLIC
        .
)

target_link_libraries(
    CodegenObrttgOptimalTrajectoryPlanner
    PUBLIC 
        ${OTP_NAME}
        CodegenObrttgCommon
        CodegenObrttgRTLogging
)

if (CMAKE_TESTING_ENABLED)
    target_sources(
        obrttgUnitTests
        PRIVATE
            ${GNC_OTP_SOURCES}
    )
    target_include_directories(
        obrttgUnitTests
        PRIVATE
           . 
           solver
    )
endif()
