set(project_config_name "overlogger")
set(project_config_type STATIC) # STATIC, SHARED, EXE
set(project_config_cpp_std 20)
set(project_config_use_unit_tests true)
set(project_config_recursive_file_gathering false) # When set to false, it'll create sub-projects for nested folders in include/${project_config_name} folders

set(project_config_dll_type SHARED) # Change a specific subproject to STATIC[default], SHARED, EXE
set(project_config_test_app_type EXE)
set(project_config_test_app_dependencies "dll" "lib") # Set other targets as dependencies for a specific subproject

set(dll_link_libraries "lib")
if(WIN32)
    # Call stack retrieving library
    list(APPEND dll_link_libraries "dbghelp")
endif()
set(project_config_dll_link_libraries "${dll_link_libraries}") # Add libraries to be linked with for a specific subproject

set(project_config_test_app_link_libraries "lib")

set(project_config_unit_tests_extra_sources "../src/dll/*.cpp") # Extra sources that need to be compiled as part of a tests project
set(project_config_unit_tests_extra_libraries "dbghelp") # Extra libraries that need to be linked as part of a tests project
