#pragma once
#include "raydiance/hittable.h"
#include "raydiance/ray.h"
#include "raydiance/vec3.h"

class sphere : public hittable {
public:
    sphere(point3 cen, double r) : center(cen), radius(r){};

    [[nodiscard]] bool isHit(const ray &r, double tMin, double tMax, hitRecord &rec) const override;

private:
    point3 center;
    double radius{};
};