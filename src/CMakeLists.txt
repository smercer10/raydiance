add_library(raydiance_lib file.cpp sphere.cpp scene.cpp interval.cpp camera.cpp colour.cpp material.cpp)

target_compile_features(raydiance_lib PUBLIC cxx_std_17)

target_include_directories(raydiance_lib PUBLIC ../include)