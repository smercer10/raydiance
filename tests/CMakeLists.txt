FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.14.0
)

FetchContent_MakeAvailable(googletest)

add_executable(raydiance_test vec3_test.cpp colour_test.cpp ray_test.cpp globals_test.cpp object_test.cpp interval_test.cpp sphere_test.cpp)

target_link_libraries(raydiance_test raydiance_lib GTest::gtest_main)

include(GoogleTest)

gtest_discover_tests(raydiance_test)