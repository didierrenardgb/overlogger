cmake_minimum_required(VERSION 3.10)

project(OVERLOGGER_LIB)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS " -g")
get_filename_component(abs_include_dir "include/" REALPATH)
set(include_dirs ${abs_include_dir})
set(header_root ${abs_include_dir}) 
get_filename_component(source_root "src/" REALPATH)
include_directories(${include_dirs})
include("../utils/grabThisOsCodeFiles.txt")
include("../utils/filtersMacro.txt")

setupVsFilters()

string(TOLOWER ${CMAKE_GENERATOR} GENERATOR_NAME)
string(REPLACE " " "_" GENERATOR_NAME ${GENERATOR_NAME})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY bin/${GENERATOR_NAME}/)

if(UNIX)
    link_libraries(dl)
endif()

# add_subdirectory("../OVERLOGGER_DLL/" "build/")
get_filename_component(abs_include_dir "../OVERLOGGER_DLL/include/" REALPATH)
list(APPEND include_dirs ${abs_include_dir})

include_directories(${include_dirs})


add_library(${PROJECT_NAME} STATIC ${src_files} ${header_files})
