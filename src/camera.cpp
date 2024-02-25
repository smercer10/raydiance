#include "raydiance/camera.h"
#include <iostream>

void camera::render(std::ostream &imgOut, const object &world) {
    initialize();

    imgOut << "P3\n"
           << imgWidth << ' ' << imgHeight << "\n255\n";

    for (auto y{0}; y < imgHeight; ++y) {
        std::cout << "Scan lines remaining: " << imgHeight - y << '\n';

        for (auto x{0}; x < imgWidth; ++x) {
            ray r = createRay(x, y);

            colour pixel = rayColour(r, world);
            pixel.write(imgOut);
        }
    }

    std::cout << "Done.\n";
};

void camera::initialize() {
    imgHeight = static_cast<int>(imgWidth / aspectRatio);
    imgHeight = (imgHeight < 1) ? 1 : imgHeight;// Image height must be at least 1

    auto viewportWidth = viewportHeight * (static_cast<double>(imgWidth) / imgHeight);

    vec3 viewportLeftToRight = vec3{viewportWidth, 0.0, 0.0};
    vec3 viewportTopToBottom = vec3{0.0, -viewportHeight, 0.0};

    horPixelSpacing = viewportLeftToRight / imgWidth;
    verPixelSpacing = viewportTopToBottom / imgHeight;

    point3 viewportTopLeft = center - (viewportLeftToRight * 0.5) - (viewportTopToBottom * 0.5) - vec3{0.0, 0.0, focalLength};
    zerothPixel = viewportTopLeft + (horPixelSpacing * 0.5) + (verPixelSpacing * 0.5);
}

ray camera::createRay(int x, int y) const {
    point3 pixelCenter = zerothPixel + (x * horPixelSpacing) + (y * verPixelSpacing);
    vec3 rayDir = pixelCenter - center;
    return ray{center, rayDir};
}

colour camera::rayColour(const ray &r, const object &world) {
    intersection i;

    if (world.isHit(r, interval{0.0, infinity}, i)) {
        return 0.5 * colour{i.normal.x() + 1, i.normal.y() + 1, i.normal.z() + 1};
    }

    vec3 unitDir = unitVector(r.direction());
    auto a = 0.5 * (unitDir.y() + 1.0);
    return (1.0 - a) * colour{1.0, 1.0, 1.0} + a * colour{0.5, 0.7, 1.0};// Linear interpolation
}