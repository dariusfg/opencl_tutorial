cmake_minimum_required(VERSION 3.15)
project(opencl_print_version)

include(${CMAKE_BINARY_DIR}/conan_toolchain.cmake)

find_package(OpenCL REQUIRED)

include_directories(include)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(opencl_print_version ${SOURCES})
target_link_libraries(opencl_print_version OpenCL::OpenCL)
