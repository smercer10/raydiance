#pragma once
#include "out.h"
#include "vec3.h"

// The Camera uses a right-handed coordinate system
namespace camera {
    inline constexpr auto viewportHeight = 2.0;
    inline constexpr auto viewportWidth = viewportHeight * (static_cast<double>(out::imgWidth) / out::imgHeight);
    inline constexpr auto focalLength = 1.0;
    inline const point3 center = point3{0.0, 0.0, 0.0};

    // Vector from left to right of the viewport
    inline const vec3 viewportU = vec3{viewportWidth, 0.0, 0.0};

    // Vector from top to bottom of the viewport
    inline const vec3 viewportV = vec3{0.0, -viewportHeight, 0.0};

    // Horizontal pixel spacing
    inline const vec3 pixelDeltaU = viewportU / out::imgWidth;

    // Vertical pixel spacing
    inline const vec3 pixelDeltaV = viewportV / out::imgHeight;

    inline const point3 viewportTopLeft = center - (viewportU / 2) - (viewportV / 2) - vec3{0.0, 0.0, focalLength};

    // Location of pixel (0, 0) in the image
    inline const point3 zerothPixel = viewportTopLeft + (pixelDeltaU / 2) + (pixelDeltaV / 2);
}// namespace camera