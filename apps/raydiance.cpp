#include "raydiance/camera.h"
#include "raydiance/config.h"
#include "raydiance/file.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <unistd.h>

int main(int argc, char *argv[]) {
    std::string sceneConfigPath;
    std::string imgOutName;

    // Get file paths from command line arguments
    int opt;
    while ((opt = getopt(argc, argv, "s:o:")) != -1) {
        switch (opt) {
            case 's':
                sceneConfigPath = optarg;
                break;
            case 'o':
                imgOutName = optarg;
                break;
            default:
                std::cerr << "Invalid option.\n\n"
                          << "Usage: raydiance -s <scene config file path> [-o <output image name>]\n";
                return 1;
        }
    }

    if (sceneConfigPath.empty()) {
        std::cerr << "Scene config file is required.\n\n"
                  << "Usage: vb2c -s <scene config file path> [-o <output image name>]\n";
        return 1;
    }

    // The default output image name is "img"
    if (imgOutName.empty()) {
        imgOutName = "img";
    }

    std::ofstream imgOut{file::openOutStream(imgOutName)};

    std::ifstream sceneConfigFile{sceneConfigPath};

    if (!imgOut.is_open()) {
        std::cerr << "Failed to open file for writing.\n";
        return 1;
    }

    if (!sceneConfigFile.is_open()) {
        std::cerr << "Failed to open scene config file.\n";
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