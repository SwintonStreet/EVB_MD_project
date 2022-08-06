include(CMakeParseArguments)
include(ProcessorCount)

find_package(GTest 1.12.1 REQUIRED)
ProcessorCount(N)

enable_testing()

add_custom_target(tests)

add_custom_command(
    TARGET tests POST_BUILD
    COMMENT "Run tests"
    COMMAND ${CMAKE_CTEST_COMMAND} -C "$<CONFIGURATION>"
                                   --output-on-failure
                                   -j "${N}"
    VERBATIM
)

add_custom_command(
    TARGET tests PRE_BUILD
    COMMENT "Ensure tests are configured"
    COMMAND "${CMAKE_COMMAND}" -B "${CMAKE_BINARY_DIR}"
                               -G${CMAKE_GENERATOR}
                               "${CMAKE_HOME_DIRECTORY}"
    VERBATIM
)

function(add_unit_tests)
    cmake_parse_arguments(
        PARSED_ARGS # prefix of output variables
        "" # list of names of the boolean arguments
           # (only defined ones will be true)
        "PREFIX" # list of names of mono-valued arguments
        "SRCS;DEPS" # list of names of multi-valued arguments
                    # (output variables are lists)
        ${ARGN} # arguments of the function to parse,
                # here we take the all original ones
    )

    add_custom_target(${PARSED_ARGS_PREFIX})
    add_dependencies(tests ${PARSED_ARGS_PREFIX})

    foreach(src ${PARSED_ARGS_SRCS})
        # get the base name
        string(REPLACE "." ";" src_list ${src})
        list(GET src_list 0 src_base)
        set(target "${PARSED_ARGS_PREFIX}-${src_base}")

        add_executable(${target} ${src})
        add_dependencies(${PARSED_ARGS_PREFIX} ${target})

        target_include_directories(${target} PRIVATE ${GTEST_INCLUDE_DIR})
        target_link_libraries(${target}
            PRIVATE
            gtest
            gmock
            gtest_main
            ${PARSED_ARGS_DEPS})

        add_test(NAME "${target}" COMMAND ${target})
    endforeach(src)

endfunction()
