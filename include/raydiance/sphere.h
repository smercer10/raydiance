#pragma once
#include "object.h"
#include "ray.h"
#include "vec3.h"

class sphere : public object {
public:
    sphere(point3 centre, double radius) : centre(centre), radius(radius){};

    [[nodiscard]] bool isHit(const ray &r, interval tRange, intersection &i) const override;

private:
    point3 centre;
    double radius{};
};