cmake_minimum_required(VERSION 3.17)

project(OVERLOGGER_TEST_APP)

get_filename_component(abs_include_dir "include/" REALPATH)
set(include_dirs ${abs_include_dir})
    
include_directories(${include_dirs})
    
file(GLOB_RECURSE header_files "include/*.h")
file(GLOB_RECURSE src_files "src/*.cpp")

string(TOLOWER ${CMAKE_GENERATOR} GENERATOR_NAME)
string(REPLACE " " "_" GENERATOR_NAME ${GENERATOR_NAME})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY bin/${GENERATOR_NAME}/)

add_subdirectory("../OVERLOGGER_LIB/" "build/")
get_filename_component(abs_include_dir "../OVERLOGGER_LIB/include/" REALPATH)
list(APPEND include_dirs ${abs_include_dir})
list(APPEND link_libs OVERLOGGER_LIB)

include_directories(${include_dirs})
link_libraries()

add_executable(${PROJECT_NAME} ${src_files} ${header_files})
add_dependencies(${PROJECT_NAME} ${link_libs})
