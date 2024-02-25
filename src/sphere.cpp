#include "raydiance/sphere.h"
#include <cmath>

[[nodiscard]] bool sphere::isHit(const ray &r, interval tRange, intersection &i) const {
    vec3 oc{r.origin() - centre};
    auto a{r.direction().lengthSquared()};
    auto halfB{dot(oc, r.direction())};
    auto c{oc.lengthSquared() - radius * radius};

    auto discriminant{halfB * halfB - a * c};
    if (discriminant < 0) {
        return false;
    }

    // Find the nearest root that lies in the acceptable range
    auto sqrtd{std::sqrt(discriminant)};
    auto root{(-halfB - sqrtd) / a};
    if (!tRange.surrounds(root)) {
        root = (-halfB + sqrtd) / a;
        if (!tRange.surrounds(root)) {
            return false;
        }
    }

    i.t = root;
    i.p = r.at(i.t);
    vec3 outwardNormal{(i.p - centre) / radius};
    i.setFaceNormal(r, outwardNormal);
    i.mat = mat;

    return true;
}