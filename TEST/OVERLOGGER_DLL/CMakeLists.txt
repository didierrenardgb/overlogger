cmake_minimum_required(VERSION 3.10)

set(EXECUTABLE_NAME "TEST_OVERLOGGER_DLL")

set(CMAKE_CXX_STANDARD 17)

set(dll_include_dirs "../../OVERLOGGER_DLL/include")
set(dll_source_dirs "../../OVERLOGGER_DLL/src")

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)

file(GLOB_RECURSE header_files "${dll_include_dirs}/*.h" "${dll_source_dirs}/*.h")
file(GLOB_RECURSE src_files "${dll_source_dirs}/*.cpp")
include("../../utils/excludeOtherOsCodeFiles.txt")

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

file(GLOB_RECURSE test_src_files "tests/*.cpp")

add_executable(
    ${EXECUTABLE_NAME}
    ${test_src_files}
    ${header_files}
    ${src_files}
)
include_directories(${dll_include_dirs})

target_link_libraries(
    ${EXECUTABLE_NAME}
    GTest::gtest_main
)

if(WIN32)
    # Call stack retrieving library
    target_link_libraries(
        ${EXECUTABLE_NAME}
        dbghelp.lib
    )
endif()

include(GoogleTest)
gtest_discover_tests(${EXECUTABLE_NAME})