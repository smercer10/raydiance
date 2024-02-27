FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)

FetchContent_MakeAvailable(json)

add_library(raydiance_lib file.cpp sphere.cpp scene.cpp interval.cpp camera.cpp colour.cpp material.cpp config.cpp)

target_compile_features(raydiance_lib PUBLIC cxx_std_17)

target_include_directories(raydiance_lib PUBLIC ../include)

target_link_libraries(raydiance_lib PUBLIC nlohmann_json::nlohmann_json)