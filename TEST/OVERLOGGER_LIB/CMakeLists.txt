cmake_minimum_required(VERSION 3.10)

set(EXECUTABLE_NAME "TEST_OVERLOGGER_LIB")

set(CMAKE_CXX_STANDARD 17)

set(lib_include_dirs "../../OVERLOGGER_LIB/include")
set(dll_include_dirs "../../OVERLOGGER_DLL/include")
include("../../utils/testMacro.txt")

include_directories(${lib_include_dirs} ${dll_include_dirs})
list(APPEND link_libs OVERLOGGER_LIB)
link_libraries(${link_libs})

enableGoogleTest(header_files src_files)

if(WIN32)
    # Call stack retrieving library
    target_link_libraries(
        ${EXECUTABLE_NAME}
        dbghelp.lib
    )
endif()
