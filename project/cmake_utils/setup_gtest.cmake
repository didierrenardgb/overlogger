include("cmake_utils/setup_visual_studio_filters.cmake")

function(setup_gtest project_name test_source_files extra_dependencies extra_libraries)
    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    enable_testing()

    set(test_target_name ${project_name}.tests)

    add_executable(${test_target_name} ${${test_source_files}})
    target_link_libraries(${test_target_name} GTest::gtest GTest::gtest_main GTest::gmock)

    if (TARGET ${project_name})
        target_link_libraries(${test_target_name} ${project_name})
    endif()

    if (extra_dependencies)
        add_dependencies(${test_target_name} ${extra_dependencies})
        target_link_directories(${test_target_name} PUBLIC ${CMAKE_BINARY_DIR})
        target_link_libraries(${test_target_name} ${extra_dependencies} ${extra_libraries})
    endif()

    setup_visual_studio_filters("" ${test_source_files})
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${test_target_name})

    set_target_properties(gtest PROPERTIES FOLDER "_external/gtest")
    set_target_properties(gmock PROPERTIES FOLDER "_external/gtest")
    set_target_properties(gmock_main PROPERTIES FOLDER "_external/gtest")
    set_target_properties(gtest_main PROPERTIES FOLDER "_external/gtest")

    include(GoogleTest)
    gtest_discover_tests(${test_target_name})
endfunction()
