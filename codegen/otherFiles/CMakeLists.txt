add_library(MboxInputParser STATIC)

target_sources(
    MboxInputParser
    PRIVATE
        src/obrttg_input_parser.cpp
)

target_include_directories(
    MboxInputParser
    PUBLIC
        include
)

add_library(MboxParametersLoader STATIC)

target_sources(
    MboxParametersLoader 
    PRIVATE
        src/obrttg_parameters_loader.cpp
)

target_include_directories(
    MboxParametersLoader 
    PUBLIC
        include
        dependencies/nlohmann
)

target_compile_definitions(
    MboxParametersLoader 
    PRIVATE MBOX_PARAMS_N_WAYPOINTS=3
    PRIVATE MBOX_PARAMS_DIM_WAYPOINTS=6
    
)

if (CMAKE_TESTING_ENABLED)

    target_sources(
        obrttgUnitTests
        PRIVATE
            src/obrttg_input_parser.cpp
            src/obrttg_parameters_loader.cpp
            tests/obrttg_input_parser_test.cpp
            tests/obrttg_parameters_loader_test.cpp
    )

    target_include_directories(
        obrttgUnitTests
        PRIVATE
            include
            dependencies/nlohmann
    )

    target_compile_definitions(
        obrttgUnitTests
        PRIVATE MBOX_PARAMS_N_WAYPOINTS=3
        PRIVATE MBOX_PARAMS_DIM_WAYPOINTS=6
    )

    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/tests/test_params.json ${CMAKE_BINARY_DIR}/test_params.json COPYONLY)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/tests/test_params_error.json ${CMAKE_BINARY_DIR}/test_params_error.json COPYONLY)

endif()