#include "raydiance/camera.h"
#include <iostream>

void camera::render(std::ostream &imgOut, const object &world) {
    initialize();

    // PPM header
    imgOut << "P3\n"
           << imgWidth << ' ' << imgHeight << "\n255\n";

    // Each row of pixels
    for (auto y{0}; y < imgHeight; ++y) {
        std::cout << "Scan lines remaining: " << imgHeight - y << '\n';

        // Each pixel in the row
        for (auto x{0}; x < imgWidth; ++x) {
            colour pixelColour{0.0, 0.0, 0.0};

            for (auto s{0}; s < samplesPerPixel; ++s) {
                ray r{getRay(x, y)};
                pixelColour += getRayColour(r, maxDepth, world);
            }

            writeColour(imgOut, pixelColour, samplesPerPixel);
        }
    }

    std::cout << "Done.\n";
};

void camera::initialize() {
    imgHeight = static_cast<int>(imgWidth / aspectRatio);
    imgHeight = (imgHeight < 1) ? 1 : imgHeight;// Image height must be at least 1

    auto focalLength{(lookFrom - lookAt).length()};

    // Get viewport height based on focal length and vertical field of view
    auto theta{degreesToRadians(fieldOfView)};
    auto h{tan(theta * 0.5)};
    auto viewportHeight{2.0 * h * focalLength};

    // Can't just use aspectRatio because the actual ratio of the image may be different to the ideal ratio
    auto viewportWidth{viewportHeight * (static_cast<double>(imgWidth) / imgHeight)};

    auto w{unitVector(lookFrom - lookAt)};
    auto u{unitVector(cross(viewUp, w))};
    auto v{cross(w, u)};

    // Vector across viewport horizontal edge
    vec3 viewportU{viewportWidth * u};

    // Vector down viewport vertical edge
    vec3 viewportV{viewportHeight * -v};

    horPixelSpacing = viewportU / imgWidth;
    verPixelSpacing = viewportV / imgHeight;

    point3 viewportTopLeft{lookFrom - (viewportU * 0.5) - (viewportV * 0.5) - (focalLength * w)};
    zerothPixel = viewportTopLeft + (horPixelSpacing * 0.5) + (verPixelSpacing * 0.5);
}

ray camera::getRay(int x, int y) const {
    point3 pixelCentre{zerothPixel + (x * horPixelSpacing) + (y * verPixelSpacing)};
    point3 pixelSample{pixelCentre + samplePixel()};

    point3 rayOrigin{lookFrom};
    vec3 rayDirection{pixelSample - rayOrigin};

    return ray{rayOrigin, rayDirection};
}

colour camera::getRayColour(const ray &r, int depth, const object &world) {
    intersection i;

    // If the bounce limit is exceeded, no more light is gathered
    if (depth <= 0) return colour{0.0, 0.0, 0.0};

    // If the ray hits an object, return a colour based on the normal
    if (world.isHit(r, interval{0.001, infinity}, i)) {
        ray scattered;
        colour attenuation;

        if (i.mat->scatter(r, i, attenuation, scattered)) {
            return attenuation * getRayColour(scattered, depth - 1, world);
        }

        return colour{0.0, 0.0, 0.0};
    }

    // If the ray doesn't hit any objects, return a gradient background
    vec3 unitDir{unitVector(r.direction())};
    auto a{0.5 * (unitDir.y() + 1.0)};
    return (1.0 - a) * colour{1.0, 1.0, 1.0} + a * colour{0.5, 0.7, 1.0};// Linear interpolation
}

vec3 camera::samplePixel() const {
    auto px{-0.5 + randomDouble()};
    auto py{-0.5 + randomDouble()};
    return (px * horPixelSpacing) + (py * verPixelSpacing);
}
