#pragma once
#include "raydiance/colour.h"
#include "raydiance/vec3.h"

class ray {
public:
    ray() = default;
    ray(const point3 &origin, const vec3 &direction)
        : orig(origin), dir(direction) {}

    [[nodiscard]] point3 origin() const { return orig; }
    [[nodiscard]] vec3 direction() const { return dir; }

    [[nodiscard]] point3 at(double t) const {
        return orig + t * dir;
    }

    [[nodiscard]] colour getColour() {
        auto unitDir = unitVector(dir);
        auto a = 0.5 * (unitDir.y() + 1.0);

        return (1.0 - a) * colour(1.0, 1.0, 1.0) + a * colour(0.5, 0.7, 1.0);// Linear interpolation
    }

private:
    point3 orig;
    vec3 dir;
};