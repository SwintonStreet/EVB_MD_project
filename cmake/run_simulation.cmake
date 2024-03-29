add_custom_target(run_simulation DEPENDS EVB_MD)

add_custom_command(
    TARGET run_simulation
    COMMENT "Run simulation"
    COMMAND ${CMAKE_CURRENT_BINARY_DIR}/../run/RunSimulation ${CMAKE_CURRENT_BINARY_DIR}
    VERBATIM
)
