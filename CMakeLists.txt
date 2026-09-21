cmake_minimum_required(VERSION 3.26)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(_local_vcpkg_toolchain "${CMAKE_SOURCE_DIR}/lib/vcpkg/scripts/buildsystems/vcpkg.cmake")
    if(EXISTS "${_local_vcpkg_toolchain}")
        set(CMAKE_TOOLCHAIN_FILE "${_local_vcpkg_toolchain}" CACHE FILEPATH "vcpkg toolchain file")
    endif()
endif()

project(chess LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SDL3 CONFIG REQUIRED)

add_subdirectory(src)