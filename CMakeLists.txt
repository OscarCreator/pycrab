cmake_minimum_required(VERSION 3.10)
project(pycrab VERSION 0.0.1)

set(CMAKE_GENERATOR "Ninja")

find_package(Python3 REQUIRED COMPONENTS Interpreter Development)

add_subdirectory(src/pycrab)
add_subdirectory(src/crab)

#get_filename_component(name src/pycrab/pycrab.pyx NAME_WE)
add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/src/pycrab/pycrab.c
    COMMAND ${Python3_EXECUTABLE} -m cython -3 ${CMAKE_CURRENT_SOURCE_DIR}/src/pycrab/pycrab.pyx
    DEPENDS src/pycrab/pycrab.pyx
)
list(APPEND PY_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/pycrab/pycrab.c)

message(STATUS "srces: ${SOURCES}, ${PY_SOURCES}, ${HEADERS_CRAB}")
add_library(pycrab SHARED 
    ${SOURCES}
    ${PY_SOURCES}
)
include_directories(src/crab)
target_link_libraries(pycrab PUBLIC Python3::Python)
# = '-fPIC'
set_target_properties(pycrab PROPERTIES POSITION_INDEPENDENT_CODE ON)
# removes 'lib' in front of shared library
set_target_properties(pycrab PROPERTIES PREFIX "")
