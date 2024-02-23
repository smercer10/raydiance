cmake_minimum_required(VERSION 3.14...3.29)

project(
        raydiance
        VERSION 1.0
        DESCRIPTION "A software-based path tracer."
        LANGUAGES CXX)

include(FetchContent)

enable_testing()

add_subdirectory(apps)

add_subdirectory(src)

add_subdirectory(tests)