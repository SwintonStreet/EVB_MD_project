include(CMakeParseArguments)
find_package(GTest 1.12.1 REQUIRED)

enable_testing()

function(add_unit_test)
    cmake_parse_arguments(
        PARSED_ARGS # prefix of output variables
        "" # list of names of the boolean arguments (only defined ones will be true)
        "" # list of names of mono-valued arguments
        "SRCS;DEPS" # list of names of multi-valued arguments (output variables are lists)
        ${ARGN} # arguments of the function to parse, here we take the all original ones
    )

    foreach(src ${PARSED_ARGS_SRCS})
        # get the base name
        string(REPLACE "." ";" src_list ${src})
        list(GET src_list 0 src_base)

        add_executable(${src_base} ${src})

        include_directories(${src_base} ${GTEST_INCLUDE_DIR})
        target_link_libraries(${src_base}
            PRIVATE
            ${PARSED_ARGS_DEPS}
            ${GTEST_LIBRARIES})

        add_test(NAME "${src_base}" COMMAND ${src_base})
    endforeach(src)

endfunction()
