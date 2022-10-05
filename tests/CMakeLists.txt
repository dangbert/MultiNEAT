cmake_minimum_required(VERSION 3.3)

option(GENERATE_PYTHON_BINDINGS "for running python tests?")
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_subdirectory(xor)
add_subdirectory(serialization)
if(GENERATE_PYTHON_BINDINGS)
    message(STATUS "adding python (test) subdirectory...")
    add_subdirectory(python)
endif()
