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

    auto matGround = std::make_shared<lambertian>(colour(0.8, 0.8, 0.0));
    auto matCentre = std::make_shared<lambertian>(colour(0.7, 0.3, 0.3));
    auto matLeft = std::make_shared<metal>(colour(0.8, 0.8, 0.8), 0.3);
    auto matRight = std::make_shared<metal>(colour(0.8, 0.6, 0.2), 1.0);

    world.add(std::make_shared<sphere>(point3(0.0, -100.5, -1.0), 100.0, matGround));
    world.add(std::make_shared<sphere>(point3(0.0, 0.0, -1.0), 0.5, matCentre));
    world.add(std::make_shared<sphere>(point3(-1.0, 0.0, -1.0), 0.5, matLeft));
    world.add(std::make_shared<sphere>(point3(1.0, 0.0, -1.0), 0.5, matRight));

    camera cam;

    cam.render(imgOut, world);

    imgOut.close();

    return 0;
}