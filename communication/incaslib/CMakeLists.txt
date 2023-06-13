if(${CMAKE_SYSTEM_PROCESSOR} MATCHES "x86_64")
    set(incaslib_dir ${CMAKE_CURRENT_SOURCE_DIR}/intel)
    set(incaslib libincas.a)
elseif(${CMAKE_SYSTEM_PROCESSOR} MATCHES "aarch64")
    set(incaslib_dir ${CMAKE_CURRENT_SOURCE_DIR}/arm)
    set(incaslib libincas.a)
endif()

message(STATUS "Configured incaslib: '${incaslib_dir}/${incaslib}'")

target_include_directories(
    MavlinkInterface 
    PUBLIC
        include
)

target_link_directories(
    MavlinkInterface 
    PUBLIC
        ${incaslib_dir}
)

target_link_libraries(
    MavlinkInterface 
    PUBLIC
        ${incaslib}
)

if (CMAKE_TESTING_ENABLED)
    target_include_directories(
        obrttgUnitTests
        PRIVATE
            include
    )

    target_link_directories(
        obrttgUnitTests
        PUBLIC
            ${incaslib_dir}
    )

    target_link_libraries(
        obrttgUnitTests
        PUBLIC
            ${incaslib}
    )
endif()