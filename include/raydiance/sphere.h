#pragma once
#include "object.h"
#include "ray.h"
#include "vec3.h"
#include <memory>

class sphere : public object {
public:
    sphere(point3 centre, double radius, const std::shared_ptr<material> &material) : centre(centre), radius(radius), mat(material){};

    [[nodiscard]] bool isHit(const ray &r, interval tRange, intersection &i) const override;

private:
    point3 centre;
    double radius{};
    std::shared_ptr<material> mat;
};