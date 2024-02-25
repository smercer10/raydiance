#include "raydiance/camera.h"
#include "raydiance/file.h"
#include "raydiance/scene.h"
#include "raydiance/sphere.h"
#include <fstream>
#include <iostream>
#include <memory>

int main() {
    std::ofstream imgOut{file::openOutStream("img")};

    if (!imgOut.is_open()) {
        std::cerr << "Failed to open file file.\n";
        return 1;
    }

    scene world;

    auto m = std::make_shared<lambertian>(colour{0.0, 0.0, 0.0});
    world.add(std::make_shared<sphere>(point3{0, 0, -1}, 0.5, m));
    world.add(std::make_shared<sphere>(point3{0, -100.5, -1}, 100, m));

    camera cam;

    cam.render(imgOut, world);

    imgOut.close();

    return 0;
}