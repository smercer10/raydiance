#pragma once
#include "raydiance/out.h"
#include "raydiance/vec3.h"

// The Camera uses a right-handed coordinate system
namespace camera {
    inline constexpr auto viewportHeight = 2.0;
    inline constexpr auto viewportWidth = viewportHeight * (static_cast<double>(out::imgWidth) / out::imgHeight);
    inline constexpr auto focalLength = 1.0;
    inline const auto center = point3{0.0, 0.0, 0.0};

    // Vector from left to right of the viewport
    inline const auto viewportU = vec3{viewportWidth, 0.0, 0.0};

    // Vector from top to bottom of the viewport
    inline const auto viewportV = vec3{0.0, -viewportHeight, 0.0};

    // Horizontal pixel spacing
    inline const auto pixelDeltaU = viewportU / out::imgWidth;

    // Vertical pixel spacing
    inline const auto pixelDeltaV = viewportV / out::imgHeight;

    inline const auto viewportTopLeft = center - (viewportU / 2) - (viewportV / 2) - vec3{0.0, 0.0, focalLength};

    // Pixel (0, 0) location
    inline const auto zerothPixel = viewportTopLeft + (pixelDeltaU / 2) + (pixelDeltaV / 2);
}// namespace camera