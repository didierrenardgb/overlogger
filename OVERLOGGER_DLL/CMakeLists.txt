cmake_minimum_required(VERSION 3.17)

project(OVERLOGGER_DLL)

set(CMAKE_CXX_STANDARD 17)

get_filename_component(abs_include_dir "include/" REALPATH)
set(include_dirs ${abs_include_dir})
    
include_directories(${include_dirs})
    
file(GLOB_RECURSE header_files "include/*.h" "src/*.h")
file(GLOB_RECURSE src_files "src/*.cpp")

if(NOT WIN32)
    list(FILTER header_files EXCLUDE REGEX ".*Win.*")
    list(FILTER src_files EXCLUDE REGEX ".*Win.*")
endif()

if(NOT UNIX)
    list(FILTER header_files EXCLUDE REGEX ".*Linux.*")
    list(FILTER src_files EXCLUDE REGEX ".*Linux.*")
endif()

if(NOT APPLE)
    list(FILTER header_files EXCLUDE REGEX ".*Mac.*")
    list(FILTER src_files EXCLUDE REGEX ".*Mac.*")
endif()

string(TOLOWER ${CMAKE_GENERATOR} GENERATOR_NAME)
string(REPLACE " " "_" GENERATOR_NAME ${GENERATOR_NAME})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY bin/${GENERATOR_NAME}/)

if(WIN32)
    # Call stack retrieving library
    link_libraries(dbghelp.lib)
endif()

add_library(${PROJECT_NAME} SHARED ${src_files} ${header_files})
