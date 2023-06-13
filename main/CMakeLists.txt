add_executable(mbox-obrttg-software)

target_sources(
    mbox-obrttg-software
    PRIVATE
        mbox_obrttg_software.cpp)

target_include_directories(
    mbox-obrttg-software
    PRIVATE
        obrttg/include
        communication/include
)

target_link_libraries(
    mbox-obrttg-software
    PUBLIC
        Obrttg
        Threads::Threads
        build_hash
)

add_executable(mbox-comm-check)

target_sources(
    mbox-comm-check
    PRIVATE
        mbox_comm_check.cpp
)

target_include_directories(
    mbox-comm-check
    PRIVATE
        ${CMAKE_SOURCE_DIR}/communication/include
)

target_link_libraries(
    mbox-comm-check
    PRIVATE
        MavlinkInterface
)