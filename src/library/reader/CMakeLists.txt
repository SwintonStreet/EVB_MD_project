add_library(reader)

target_include_directories(reader PUBLIC include)

target_sources(reader
    PRIVATE
    src/intraMolReader.cc
    src/keyWord.cc
    src/keyWordReader.cc
    src/keyWordVec.cc
    src/molReader.cc
    src/templatMolFile
    src/xyzReader.cc
)

target_link_libraries(reader
    PRIVATE
    config
    systemObjects
    utils
)

add_subdirectory(testSrc)
