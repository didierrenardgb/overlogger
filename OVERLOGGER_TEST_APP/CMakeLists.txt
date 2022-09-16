cmake_minimum_required(VERSION 3.10)

project(OVERLOGGER_TEST_APP)

set(CMAKE_CXX_STANDARD 17)

get_filename_component(abs_include_dir "include/" REALPATH)
set(include_dirs ${abs_include_dir})
    
include("../utils/grabThisOsCodeFiles.txt")

string(TOLOWER ${CMAKE_GENERATOR} GENERATOR_NAME)
string(REPLACE " " "_" GENERATOR_NAME ${GENERATOR_NAME})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY bin/${GENERATOR_NAME}/)

# add_subdirectory("../OVERLOGGER_LIB/" "build/")
get_filename_component(abs_include_dir "../OVERLOGGER_LIB/include/" REALPATH)
list(APPEND include_dirs ${abs_include_dir})
get_filename_component(abs_include_dir "../OVERLOGGER_DLL/include/" REALPATH)
list(APPEND include_dirs ${abs_include_dir})
list(APPEND link_libs OVERLOGGER_LIB)

include_directories(${include_dirs})
link_libraries(${link_libs})

add_executable(${PROJECT_NAME} ${src_files} ${header_files})
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "olg_test_app")
add_dependencies(${PROJECT_NAME} ${link_libs})
