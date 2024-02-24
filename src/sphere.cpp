#include "raydiance/sphere.h"
#include <cmath>

[[nodiscard]] bool sphere::isHit(const ray &r, interval tRange, hitRecord &rec) const {
    vec3 oc{r.origin() - center};
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

    rec.t = root;
    rec.p = r.at(rec.t);
    vec3 outwardNormal{(rec.p - center) / radius};
    rec.setFaceNormal(r, outwardNormal);

    return true;
}