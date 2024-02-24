#include "raydiance/camera.h"
#include "raydiance/colour.h"
#include "raydiance/hlist.h"
#include "raydiance/math.h"
#include "raydiance/sphere.h"
#include <fstream>
#include <iostream>
#include <memory>

colour rayColour(const ray &r, const hittable &world) {
    hitRecord rec;
    if (world.isHit(r, 0, math::infinity, rec)) {
        return 0.5 * colour{rec.normal.x() + 1, rec.normal.y() + 1, rec.normal.z() + 1};
    }

    vec3 unitDir = unitVector(r.direction());
    auto t = 0.5 * (unitDir.y() + 1.0);
    return (1.0 - t) * colour{1.0, 1.0, 1.0} + t * colour{0.5, 0.7, 1.0};
}
int main() {
    std::ofstream imgOut{out::openOutFile("img")};

    if (!imgOut.is_open()) {
        std::cerr << "Failed to open out file.\n";
        return 1;
    }

    imgOut << "P3\n"
           << out::imgWidth << ' ' << out::imgHeight << "\n255\n";

    hlist world;
    world.add(std::make_shared<sphere>(point3{0.0, 0.0, -1}, 0.5));
    world.add(std::make_shared<sphere>(point3{0.0, -100.5, -1}, 100));

    for (auto y{0}; y < out::imgHeight; ++y) {
        std::cout << "Scan lines remaining: " << out::imgHeight - y << '\n';

        for (auto x{0}; x < out::imgWidth; ++x) {
            point3 pixelCenter = camera::zerothPixel + (x * camera::pixelDeltaU) + (y * camera::pixelDeltaV);
            vec3 rayDir = pixelCenter - camera::center;
            ray r{camera::center, rayDir};

            colour pixelColour = rayColour(r, world);
            pixelColour.write(imgOut);
        }
    }

    std::cout << "Done.\n";

    imgOut.close();

    return 0;
}