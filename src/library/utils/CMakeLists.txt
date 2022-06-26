add_library(utils)

target_include_directories(utils PUBLIC include)

target_sources(utils
    PRIVATE
        src/readlib.cc
)
