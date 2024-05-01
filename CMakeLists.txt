cmake_minimum_required(VERSION 3.15)
project(header_only
        VERSION 1.0.0
        LANGUAGES CXX)

include(GNUInstallDirs)

message(STATUS "CMake install directory: " ${CMAKE_INSTALL_INCLUDEDIR})

add_library(header_only INTERFACE)
add_library(header_only::header ALIAS header_only)

target_include_directories(
        header_only INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

#set_target_properties(header_only PROPERTIES PUBLIC_HEADER "include/header_only.h")
#install(TARGETS header_only)

install(
        TARGETS header_only
        EXPORT HeaderOnly_Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        "HeaderOnlyConfigVersion.cmake"
        VERSION ${PROJECT_VERSION}
        COMPATIBILITY SameMajorVersion)

#configure_package_config_file(
#        "${PROJECT_SOURCE_DIR}/cmake/HeaderOnlyConfig.cmake.in"
#        "${PROJECT_BINARY_DIR}/HeaderOnlyConfig.cmake"
#        INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/SI/cmake)

install(
        EXPORT HeaderOnly_Targets
        FILE HeaderOnlyTargets.cmake
        NAMESPACE header_only::
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/header_only/cmake)

#install(FILES "${PROJECT_BINARY_DIR}/HeaderOnlyConfig.cmake"
#        "${PROJECT_BINARY_DIR}/HeaderOnlyConfigVersion.cmake"
#        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/header_only/cmake)

message(STATUS "CMAKE_INSTALL_INCLUDEDIR: " ${CMAKE_INSTALL_INCLUDEDIR})
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})