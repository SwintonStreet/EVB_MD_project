add_library(systemObjects)

target_include_directories(systemObjects PUBLIC include)

target_sources(systemObjects
    PRIVATE
    src/atom.cc
    src/evb_system.cc
    src/intraMolBondDefs.cc
    src/molecule.cc
    src/sys.cc
    src/twoAtomBonds.cc
)

target_link_libraries(systemObjects PRIVATE utils)

add_subdirectory(testSrc)
