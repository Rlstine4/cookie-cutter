cmake_minimum_required(VERSION 3.26)

project({{ cookiecutter.project_slug }}
    VERSION {{ cookiecutter.version }}
    DESCRIPTION "{{ cookiecutter.description }}"
    LANGUAGES CXX
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(USE_LOCAL_PACKAGES "Use locally installed packages when available" ON)
option(OPTION_ASAN "Build with AddressSanitizer" OFF)
option(BUILD_TESTING "Build the test targets" OFF)

list(PREPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include(Dependencies)

if(OPTION_ASAN)
    add_compile_options(-fsanitize=address)
    add_link_options(-fsanitize=address)
endif()

set(LIB_TARGET {{ cookiecutter.project_slug }})
add_library(${LIB_TARGET} INTERFACE)
add_library(${LIB_TARGET}::${LIB_TARGET} ALIAS ${LIB_TARGET})

set_target_properties(${LIB_TARGET} PROPERTIES
    EXPORT_NAME ${LIB_TARGET}
)

target_compile_features(${LIB_TARGET} INTERFACE cxx_std_{{ cookiecutter.cxx_standard }})
target_include_directories(${LIB_TARGET} INTERFACE
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

if(BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()

install(TARGETS ${LIB_TARGET}
    EXPORT ${LIB_TARGET}Targets
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

set(${LIB_TARGET}_package_dir "${CMAKE_INSTALL_LIBDIR}/cmake/${LIB_TARGET}")
configure_package_config_file(
    "cmake/${LIB_TARGET}Config.cmake.in"
    "${PROJECT_BINARY_DIR}/${LIB_TARGET}Config.cmake"
    INSTALL_DESTINATION "${${LIB_TARGET}_package_dir}"
)
write_basic_package_version_file(
    "${PROJECT_BINARY_DIR}/${LIB_TARGET}ConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)
install(FILES
    "${PROJECT_BINARY_DIR}/${LIB_TARGET}Config.cmake"
    "${PROJECT_BINARY_DIR}/${LIB_TARGET}ConfigVersion.cmake"
    DESTINATION "${${LIB_TARGET}_package_dir}"
)
install(EXPORT ${LIB_TARGET}Targets
    NAMESPACE ${LIB_TARGET}::
    FILE ${LIB_TARGET}Targets.cmake
    DESTINATION "${${LIB_TARGET}_package_dir}"
)
