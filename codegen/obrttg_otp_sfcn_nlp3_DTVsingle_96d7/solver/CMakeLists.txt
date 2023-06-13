# Gather solvers source code
file(GLOB MIN_FUEL_SOLVER_SRC ./${MIN_FUEL_SOLVER_NAME}*.c)
file(GLOB MIN_ERROR_SOLVER_SRC ./${MIN_ERROR_SOLVER_NAME}*.c)

# Define directory of the solver static library
if (${CMAKE_SYSTEM_PROCESSOR} MATCHES "x86_64")
    set(SOLVER_LIB_DIRECTORY "gnu_x86_64")
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "aarch64")
    set(SOLVER_LIB_DIRECTORY "rpi_aarch72")
else()
    message(SEND_ERROR "No OTP solver available for target system ${CMAKE_SYSTEM_PROCESSOR}.")
endif()
message(STATUS "Configured solver directory ${SOLVER_LIB_DIRECTORY}")

add_library(${OTP_NAME} STATIC)

target_sources(
    ${OTP_NAME}
    PRIVATE
        ${OTP_NAME}_parser_wrapper.c
        ${OTP_NAME}_x0_generator_wrapper.c
        obrttg_initial_guess.c
        ${OTP_NAME}_solver_wrapper.c
        ${OTP_NAME}_postprocessor_wrapper.c
        ${MIN_FUEL_SOLVER_SRC}
        ${MIN_ERROR_SOLVER_SRC}
)

target_include_directories(
    ${OTP_NAME}
    PUBLIC
        .   
)

target_link_directories(
    ${OTP_NAME}
    PUBLIC 
        ${SOLVER_LIB_DIRECTORY}
)

target_link_libraries(
    ${OTP_NAME}
    PRIVATE
        CodegenObrttgCommon
        CodegenObrttgRTLogging
        ${MIN_FUEL_SOLVER_NAME}    
        ${MIN_ERROR_SOLVER_NAME}
)

if (CMAKE_TESTING_ENABLED)
    target_sources(
        obrttgUnitTests
        PRIVATE
            ${OTP_NAME}_parser_wrapper.c
            ${OTP_NAME}_x0_generator_wrapper.c
            obrttg_initial_guess.c
	        ${OTP_NAME}_solver_wrapper.c
            ${OTP_NAME}_postprocessor_wrapper.c
            ${MIN_FUEL_SOLVER_SRC}
            ${MIN_ERROR_SOLVER_SRC}
    )

    target_link_directories(
        obrttgUnitTests
        PRIVATE
            ${SOLVER_LIB_DIRECTORY}
    )

    target_link_libraries(
        obrttgUnitTests
        PRIVATE
            ${MIN_FUEL_SOLVER_NAME}    
            ${MIN_ERROR_SOLVER_NAME}
    )
endif()
