cmake_minimum_required(VERSION 3.10)

set(EXECUTABLE_NAME "TEST_OVERLOGGER_DLL")

set(CMAKE_CXX_STANDARD 17)

set(dll_include_dirs "../../OVERLOGGER_DLL/include")
set(dll_source_dirs "../../OVERLOGGER_DLL/src")

include("../../utils/testMacro.txt")


file(GLOB_RECURSE header_files "${dll_include_dirs}/*.h" "${dll_source_dirs}/*.h")
file(GLOB_RECURSE src_files "${dll_source_dirs}/*.cpp")
include("../../utils/excludeOtherOsCodeFiles.txt")

enableGoogleTest(header_files src_files)

if(WIN32)
    # Call stack retrieving library
    target_link_libraries(
        ${EXECUTABLE_NAME}
        dbghelp.lib
    )
endif()
