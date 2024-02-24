#include "raydiance/ray.h"
#include "raydiance/sphere.h"

// WIP
colour ray::getColour() {
    sphere s(point3(0, 0, -1), 0.5);

    if (s.isHit(*this)) {
        return {1, 0, 0};
    }

    auto unitDir = unitVector(dir);
    auto a = 0.5 * (unitDir.y() + 1.0);

    return (1.0 - a) * colour(1.0, 1.0, 1.0) + a * colour(0.5, 0.7, 1.0);// Linear interpolation
}