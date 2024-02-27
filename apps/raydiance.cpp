#include "raydiance/camera.h"
#include "raydiance/config.h"
#include "raydiance/file.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

int main() {
    std::ofstream imgOut{file::openOutStream("img")};

    if (!imgOut.is_open()) {
        std::cerr << "Failed to open image file.\n";
        return 1;
    }

    std::ifstream sceneConfigFile{"scene.json"};

    if (!sceneConfigFile.is_open()) {
        std::cerr << "Failed to open scene file.\n";
        return 1;
    }

    nlohmann::json sceneConfig = nlohmann::json::parse(sceneConfigFile);

    scene world;
    config::addObjects(sceneConfig, world);

    camera cam;
    config::setCamera(sceneConfig, cam);

    cam.render(imgOut, world);

    imgOut.close();

    return 0;
}