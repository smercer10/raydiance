#pragma once
#include "object.h"
#include "vec3.h"
#include <ostream>

// The Camera uses a right-handed coordinate system
class camera {
public:
    [[maybe_unused]] void setAspectRatio(double ratio) { aspectRatio = ratio; }
    [[maybe_unused]] void setImgWidth(int width) { imgWidth = width; }
    [[maybe_unused]] void setViewportHeight(double height) { viewportHeight = height; }
    [[maybe_unused]] void setFocalLength(double len) { focalLength = len; }
    [[maybe_unused]] void setCenter(point3 loc) { center = loc; }

    void render(std::ostream &imgOut, const object &world);

private:
    double aspectRatio{16.0 / 9.0};
    int imgWidth{400};
    int imgHeight{};
    point3 center{point3{0.0, 0.0, 0.0}};
    double viewportHeight{2.0};
    double focalLength{1.0};
    vec3 horPixelSpacing;
    vec3 verPixelSpacing;
    point3 zerothPixel;

    void initialize();
    [[nodiscard]] ray createRay(int x, int y) const;
    static colour rayColour(const ray &r, const object &world);
};