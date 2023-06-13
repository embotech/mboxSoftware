target_sources(
    Obrttg
    PRIVATE 
        src/obrttg.cpp
        src/optimal_trajectory_planner.cpp
        src/obrttg_periodic.cpp
        src/parameters_interface.cpp
        src/mvm_interface.cpp
        src/guidance_interface.cpp
        src/navigation_interface.cpp
        src/otp_interface.cpp
)

target_include_directories(
    Obrttg
    PUBLIC
        include
        ${CMAKE_SOURCE_DIR}/utils/include
)

target_link_libraries(
    Obrttg
    PRIVATE 
        MboxUtils
        MboxLogger
        MboxParametersLoader
        Threads::Threads
)

target_link_libraries(
    Obrttg
    PUBLIC 
        CodegenObrttg
        MavlinkInterface
)

if (CMAKE_TESTING_ENABLED)
    target_include_directories(
        obrttgUnitTests
        PRIVATE
            include
    )
    target_sources(
        obrttgUnitTests
        PUBLIC
            tests/obrttg_test.cpp
            tests/codegen_interface_test.cpp
            src/parameters_interface.cpp
            src/mvm_interface.cpp
            src/guidance_interface.cpp
            src/navigation_interface.cpp
            src/otp_interface.cpp
            src/obrttg.cpp
            src/optimal_trajectory_planner.cpp
            src/obrttg_periodic.cpp
    )
endif()
