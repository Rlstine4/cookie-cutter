# One binary per test file; add new tests here
set(TEST_SOURCES
    test_{{ cookiecutter.project_slug }}.cpp
)

# Catch2 v3 helper for test discovery (provides catch_discover_tests)
if(Catch2_SOURCE_DIR)
    list(APPEND CMAKE_MODULE_PATH "${Catch2_SOURCE_DIR}/extras")
endif()
include(Catch)

foreach(test_source ${TEST_SOURCES})
    get_filename_component(test_name ${test_source} NAME_WE)

    add_executable(${test_name} ${test_source})
    target_link_libraries(${test_name} PRIVATE ${LIB_TARGET}::${LIB_TARGET} Catch2::Catch2WithMain)
    # Inside the project, headers can be included bare (e.g. "foo.hpp")
    target_include_directories(${test_name} PRIVATE ${PROJECT_SOURCE_DIR}/include/${LIB_TARGET})
    target_compile_options(${test_name} PRIVATE
        $<$<CXX_COMPILER_ID:GNU,Clang,AppleClang>:-Wall -Wextra -Wpedantic -Wshadow -Wconversion>
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
    )

    catch_discover_tests(${test_name})
endforeach()
