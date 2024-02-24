#pragma once
#include "raydiance/ray.h"
#include "raydiance/vec3.h"

class sphere {
public:
    sphere() = default;
    sphere(point3 cen, double r) : center(cen), radius(r){};

    [[nodiscard]] bool isHit(const ray &r) const;

private:
    point3 center;
    double radius{};
};