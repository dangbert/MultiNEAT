# Copyright 2020, 2021 Peter Dimov
# Distributed under the Boost Software License, Version 1.0.
# https://www.boost.org/LICENSE_1_0.txt

cmake_minimum_required(VERSION 3.14...3.20)

project(boost_python VERSION "${BOOST_SUPERPROJECT_VERSION}" LANGUAGES CXX)


if (DEFINED PYTHON_VERSION)
    set(PYTHON_VERSION "${PYTHON_VERSION}" "EXACT")
endif()

find_package(Python
        ${PYTHON_VERSION}
        REQUIRED
        COMPONENTS Development OPTIONAL_COMPONENTS NumPy)
find_package(Boost REQUIRED)

if(Python_NumPy_FOUND)
    message(STATUS "Boost.Python: using Python ${Python_VERSION} with NumPy at ${Python_NumPy_INCLUDE_DIRS}")
else()
    message(STATUS "Boost.Python: using Python ${Python_VERSION} without NumPy")
endif()

# boost_pythonXY

set(_pyver ${Python_VERSION_MAJOR}${Python_VERSION_MINOR})
set(_boost_python boost_python${_pyver})

add_library(${_boost_python}
        boost-python/src/dict.cpp
        boost-python/src/errors.cpp
        boost-python/src/exec.cpp
        boost-python/src/import.cpp
        boost-python/src/list.cpp
        boost-python/src/long.cpp
        boost-python/src/module.cpp
        boost-python/src/object_operators.cpp
        boost-python/src/object_protocol.cpp
        boost-python/src/slice.cpp
        boost-python/src/str.cpp
        boost-python/src/tuple.cpp
        boost-python/src/wrapper.cpp
        boost-python/src/converter/from_python.cpp
        boost-python/src/converter/registry.cpp
        boost-python/src/converter/type_id.cpp
        boost-python/src/converter/builtin_converters.cpp
        boost-python/src/converter/arg_to_python_base.cpp
        boost-python/src/object/enum.cpp
        boost-python/src/object/class.cpp
        boost-python/src/object/function.cpp
        boost-python/src/object/inheritance.cpp
        boost-python/src/object/life_support.cpp
        boost-python/src/object/pickle_support.cpp
        boost-python/src/object/iterator.cpp
        boost-python/src/object/stl_iterator.cpp
        boost-python/src/object_protocol.cpp
        boost-python/src/object_operators.cpp
        boost-python/src/object/function_doc_signature.cpp
        )

add_library(Boost::python${_pyver} ALIAS ${_boost_python})

target_include_directories(${_boost_python} PUBLIC boost-python/include)

target_link_libraries(${_boost_python}
        PUBLIC
        Boost::boost

        Python::Module
        )

target_compile_definitions(${_boost_python}
        PUBLIC BOOST_PYTHON_NO_LIB
        PRIVATE BOOST_PYTHON_SOURCE
        )

if(BUILD_SHARED_LIBS)
    target_compile_definitions(${_boost_python} PUBLIC BOOST_PYTHON_DYN_LINK)
else()
    set_property(TARGET ${_boost_python} PROPERTY POSITION_INDEPENDENT_CODE ON)
    target_compile_definitions(${_boost_python} PUBLIC BOOST_PYTHON_STATIC_LINK BOOST_PYTHON_STATIC_LIB)
endif()

# Boost::python alias

add_library(boost_python INTERFACE)
#add_library(Boost::python ALIAS boost_python)
target_link_libraries(boost_python INTERFACE Boost::python${_pyver})

# Installation

if(BOOST_SUPERPROJECT_VERSION AND NOT CMAKE_VERSION VERSION_LESS 3.13)
    boost_install(TARGETS ${_boost_python} boost_python VERSION ${BOOST_SUPERPROJECT_VERSION} HEADER_DIRECTORY boost-python/include)
endif()

if(Python_NumPy_FOUND)

    # boost_numpyXY

    set(_boost_numpy boost_numpy${_pyver})

    add_library(${_boost_numpy}
            boost-python/src/numpy/dtype.cpp
            boost-python/src/numpy/matrix.cpp
            boost-python/src/numpy/ndarray.cpp
            boost-python/src/numpy/numpy.cpp
            boost-python/src/numpy/scalars.cpp
            boost-python/src/numpy/ufunc.cpp
            )

    add_library(Boost::numpy${_pyver} ALIAS ${_boost_numpy})

    target_include_directories(${_boost_numpy} PUBLIC boost-python/include)

    target_link_libraries(${_boost_numpy}
            PUBLIC
            Boost::boost
            ${_boost_python}

            Python::NumPy
            )

    target_compile_definitions(${_boost_numpy}
            PUBLIC BOOST_NUMPY_NO_LIB
            PRIVATE BOOST_NUMPY_SOURCE
            )

    if(BUILD_SHARED_LIBS)
        target_compile_definitions(${_boost_numpy} PUBLIC BOOST_NUMPY_DYN_LINK)
    else()
        set_property(TARGET ${_boost_numpy} PROPERTY POSITION_INDEPENDENT_CODE ON)
        target_compile_definitions(${_boost_numpy} PUBLIC BOOST_NUMPY_STATIC_LINK BOOST_NUMPY_STATIC_LIB)
    endif()

    # Boost::numpy alias

    add_library(boost_numpy INTERFACE)
#    add_library(Boost::numpy ALIAS boost_numpy)
    target_link_libraries(boost_numpy INTERFACE Boost::numpy${_pyver})

    # Installation

    if(BOOST_SUPERPROJECT_VERSION AND NOT CMAKE_VERSION VERSION_LESS 3.13)
        boost_install(TARGETS ${_boost_numpy} boost_numpy VERSION ${BOOST_SUPERPROJECT_VERSION})
    endif()

endif()

unset(_pyver)
unset(_boost_python)
unset(_boost_numpy)

# Testing

if(BUILD_TESTING AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test/CMakeLists.txt")

    add_subdirectory(test)

endif()
