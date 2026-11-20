include(CPM)

set(CPM_USE_LOCAL_PACKAGES ${USE_LOCAL_PACKAGES})

# Only needed for tests
if(BUILD_TESTING)
    CPMAddPackage(
        NAME Catch2
        VERSION 3.7.1
        GITHUB_REPOSITORY catchorg/Catch2
        OPTIONS
            "CATCH_INSTALL_DOCS OFF"
            "CATCH_INSTALL_EXTRAS OFF"
    )
endif()

# Add library dependencies here, e.g.:
# CPMAddPackage(
#     NAME expected
#     GITHUB_REPOSITORY TartanLlama/expected
#     GIT_TAG v1.3.1
#     OPTIONS "EXPECTED_BUILD_TESTS OFF" "EXPECTED_BUILD_PACKAGE OFF"
# )
# ...then add `target_link_libraries(${LIB_TARGET} INTERFACE tl::expected)`
# in CMakeLists.txt and `find_dependency(...)` in the Config.cmake.in file.
