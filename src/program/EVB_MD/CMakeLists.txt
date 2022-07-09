add_executable(EVB_MD src/main.cc)

target_link_libraries(EVB_MD
    PRIVATE
    utils
    systemObjects
    reader
    loops
)
