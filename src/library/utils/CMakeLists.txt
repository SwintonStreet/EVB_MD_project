add_library(utils)

target_include_directories(utils PUBLIC include)

target_sources(utils
    PRIVATE
        src/defaultFileAccess.cc
        src/logger.cc
        src/readlib.cc
)

add_subdirectory(testSrc)
