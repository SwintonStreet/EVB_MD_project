find_package(GTest 1.12.1 REQUIRED)

add_library(testing INTERFACE)

target_include_directories(testing INTERFACE include)

target_link_libraries(testing
    INTERFACE
    config
    loops
    reader
    systemObjects
    utils
    gmock_main
    gtest_main)
