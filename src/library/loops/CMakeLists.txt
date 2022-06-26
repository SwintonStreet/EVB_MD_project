add_library(loops)

target_include_directories(loops PUBLIC include)

target_sources(loops
    PRIVATE
    src/forceUpdate.cc
    src/mainLoop.cc
    src/systemUpdate.cc
    src/twoBondLoop.cc
)

target_link_libraries(loops
    PRIVATE
    reader
    systemObjects
    utils
)
