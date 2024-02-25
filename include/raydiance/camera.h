#pragma once
#include "colour.h"
#include "object.h"
#include "vec3.h"
#include <ostream>

// The camera uses a right-handed coordinate system
class camera {
public:
    [[maybe_unused]] void setAspectRatio(double ratio) { aspectRatio = ratio; }
    [[maybe_unused]] void setImgWidth(int width) { imgWidth = width; }
    [[maybe_unused]] void setCamCentre(point3 loc) { camCentre = loc; }
    [[maybe_unused]] void setViewportHeight(double height) { viewportHeight = height; }
    [[maybe_unused]] void setFocalLength(double len) { focalLength = len; }
    [[maybe_unused]] void setSamplesPerPixel(int samples) { samplesPerPixel = samples; }

    // Initialize the camera and render the world
    void render(std::ostream &imgOut, const object &world);

private:
    double aspectRatio{16.0 / 9.0};
    int imgWidth{400};
    int imgHeight{};
    point3 camCentre{point3{0.0, 0.0, 0.0}};
    double viewportHeight{2.0};
    double focalLength{1.0};
    vec3 horPixelSpacing;
    vec3 verPixelSpacing;
    point3 zerothPixel;// Pixel at (0, 0) of the image
    int samplesPerPixel{10};
    int maxDepth{10};

    // Initialize data members
    void initialize();

    // Get a randomly sampled ray for the pixel at (x, y)
    [[nodiscard]] ray getRay(int x, int y) const;

    static colour getRayColour(const ray &r, int depth, const object &world);

    // Get a vector from the centre of a pixel to a random point near the centre
    [[nodiscard]] vec3 samplePixel() const;
};