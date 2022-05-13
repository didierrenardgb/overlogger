cmake_minimum_required(VERSION 3.17)

project(OVERLOGGER_LIB)

set(CMAKE_CXX_STANDARD 17)

get_filename_component(abs_include_dir "include/" REALPATH)
set(include_dirs ${abs_include_dir})
    
include_directories(${include_dirs})
    
file(GLOB_RECURSE header_files "include/*.h" "src/*.h")
file(GLOB_RECURSE src_files "src/*.cpp")

string(TOLOWER ${CMAKE_GENERATOR} GENERATOR_NAME)
string(REPLACE " " "_" GENERATOR_NAME ${GENERATOR_NAME})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY bin/${GENERATOR_NAME}/)

# add_subdirectory("../OVERLOGGER_DLL/" "build/")
get_filename_component(abs_include_dir "../OVERLOGGER_DLL/include/" REALPATH)
list(APPEND include_dirs ${abs_include_dir})

include_directories(${include_dirs})


add_library(${PROJECT_NAME} STATIC ${src_files} ${header_files})
