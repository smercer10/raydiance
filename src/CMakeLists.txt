add_library(raydiance_lib out.cpp sphere.cpp hlist.cpp)

target_compile_features(raydiance_lib PUBLIC cxx_std_17)

target_include_directories(raydiance_lib PUBLIC ../include)