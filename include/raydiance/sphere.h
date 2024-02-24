#pragma once
#include "hittable.h"
#include "ray.h"
#include "vec3.h"

class sphere : public hittable {
public:
    sphere(point3 cen, double r) : center(cen), radius(r){};

    [[nodiscard]] bool isHit(const ray &r, interval tRange, hitRecord &rec) const override;

private:
    point3 center;
    double radius{};
};