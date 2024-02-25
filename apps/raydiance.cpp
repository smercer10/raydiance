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

    auto matGround{std::make_shared<lambertian>(colour{0.8, 0.8, 0.0})};
    auto matCenter{std::make_shared<lambertian>(colour{0.7, 0.3, 0.3})};
    auto matLeft{std::make_shared<dielectric>(1.5)};
    auto matRight{std::make_shared<metal>(colour{0.8, 0.6, 0.2}, 1.0)};


    world.add(std::make_shared<sphere>(point3{0, -100.5, -1}, 100, matGround));
    world.add(std::make_shared<sphere>(point3{0, 0, -1}, 0.5, matCenter));
    world.add(std::make_shared<sphere>(point3{-1, 0, -1}, 0.5, matLeft));
    world.add(std::make_shared<sphere>(point3{-1, 0, -1}, -0.45, matLeft));
    world.add(std::make_shared<sphere>(point3{1, 0, -1}, 0.5, matRight));

    camera cam;

    cam.setLookFrom(point3{-2, 2, 1});
    cam.setLookAt(point3{0, 0, -1});
    cam.setSamplesPerPixel(100);
    cam.setMaxDepth(50);
    cam.setFieldOfView(20);
    cam.setDefocusAngle(10.0);
    cam.setFocusDistance(3.4);

    cam.render(imgOut, world);

    imgOut.close();

    return 0;
}