#include "raydiance/camera.h"
#include "raydiance/colour.h"
#include "raydiance/ray.h"
#include <fstream>
#include <iostream>

int main() {
    std::ofstream imgOut{out::openOutFile("img")};

    if (!imgOut.is_open()) {
        std::cerr << "Failed to open out file.\n";
        return 1;
    }

    imgOut << "P3\n"
           << out::imgWidth << ' ' << out::imgHeight << "\n255\n";

    for (auto y{0}; y < out::imgHeight; ++y) {
        std::cout << "Scan lines remaining: " << out::imgHeight - y << '\n';

        for (auto x{0}; x < out::imgWidth; ++x) {
            auto pixelCenter = camera::zerothPixel + (x * camera::pixelDeltaU) + (y * camera::pixelDeltaV);
            auto rayDir = pixelCenter - camera::center;
            ray r{camera::center, rayDir};

            colour pixelColour = r.getColour();
            pixelColour.write(imgOut);
        }
    }

    std::cout << "Done.\n";

    imgOut.close();

    return 0;
}