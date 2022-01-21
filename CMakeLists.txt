cmake_minimum_required(VERSION 3.17)

project(OverLogger)

get_filename_component(abs_include_dir "../include/" REALPATH)
set(include_dirs ${abs_include_dir})
    
include_directories(${include_dirs})
    
file(GLOB_RECURSE header_files "../include/*.h")
file(GLOB_RECURSE src_files "../src/*.cpp")

string(TOLOWER ${CMAKE_GENERATOR} GENERATOR_NAME)
string(REPLACE " " "_" GENERATOR_NAME ${GENERATOR_NAME})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../bin/${GENERATOR_NAME}/)

add_executable(${PROJECT_NAME} ${src_files} ${header_files})

