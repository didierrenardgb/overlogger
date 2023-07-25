cmake_minimum_required(VERSION 3.18)

### cmake includes
include("cmake_utils/include_required_utils.cmake")
include("project_config.cmake")
include("cmake_utils/include_optional_utils.cmake")

### Basic project configuration
project(${project_config_name})
set(ARTIFACT_TYPE ${project_config_type})
set(CMAKE_CXX_STANDARD ${project_config_cpp_std})

### Current project's include paths
get_filename_component(abs_include_dir "../include/" REALPATH)
set(include_dirs ${abs_include_dir})
include_directories(${include_dirs})
###

set(link_libraries "")
set(test_libraries "")

configure_subprojects(${PROJECT_NAME} link_libraries)

### Gather files and put them in folders
set(file_excludes ".*\\.tests.*")
fill_platform_excludes(platform_excludes)
list(APPEND file_excludes ${platform_excludes})
gather_files(header_files ${project_config_recursive_file_gathering} "../include/${project_config_name}/*.h;../include/${project_config_name}/*.inl;../src/*.h" "${file_excludes}")
gather_files(src_files ${project_config_recursive_file_gathering} "../src/*.cpp" "${file_excludes}")

if (${project_config_use_unit_tests})
    set(file_patterns "../src/*.tests.cpp")
    if (project_config_unit_tests_extra_sources)
        list(APPEND file_patterns "${project_config_unit_tests_extra_sources}")
    endif()
    gather_files(test_files true "${file_patterns}" "${platform_excludes}")
endif()

setup_visual_studio_filters("${PROJECT_NAME}" header_files)
setup_visual_studio_filters("${PROJECT_NAME}" src_files)
###

if (test_files)
    setup_gtest(${PROJECT_NAME} test_files "${link_libraries}" "${project_config_unit_tests_extra_libraries}")
    set_target_properties(${PROJECT_NAME}.tests PROPERTIES LINKER_LANGUAGE CXX FOLDER "${PROJECT_NAME}.internal")
endif()

### Configure the target itself
if (src_files)
    if (NOT ARTIFACT_TYPE STREQUAL EXE)
        add_library(${PROJECT_NAME} ${ARTIFACT_TYPE} ${src_files} ${header_files})
    else()
        add_executable(${PROJECT_NAME} ${src_files} ${header_files})
        set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})
    endif()
    target_link_libraries(${PROJECT_NAME} PUBLIC ${link_libraries})
    set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)
endif()
###
