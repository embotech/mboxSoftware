# No src folder, this is a header only library
find_package(Threads)

add_library(messageThread INTERFACE)
target_include_directories(messageThread INTERFACE include)
target_link_libraries(messageThread INTERFACE Threads::Threads)

# If testing is enabled, add tests folder
if(CMAKE_TESTING_ENABLED)
    add_subdirectory(tests)
endif()
