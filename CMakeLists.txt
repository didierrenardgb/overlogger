cmake_minimum_required(VERSION 3.10)

project(OverLogger)

set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(OVERLOGGER_DLL OVERLOGGER_ALL/DLL)
add_subdirectory(OVERLOGGER_LIB OVERLOGGER_ALL/LIB)
add_subdirectory(OVERLOGGER_TEST_APP OVERLOGGER_ALL/TEST_APP)
add_subdirectory(TEST/OVERLOGGER_DLL  OVERLOGGER_ALL/TEST/OVERLOGGER_DLL)
add_subdirectory(TEST/OVERLOGGER_LIB  OVERLOGGER_ALL/TEST/OVERLOGGER_LIB)
