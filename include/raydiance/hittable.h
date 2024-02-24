#pragma once
#include "raydiance/ray.h"
#include <cassert>

class hitRecord {
public:
    point3 p;
    vec3 normal;
    double t{};
    bool frontFace{};

    void setFaceNormal(const ray &r, const vec3 &outwardNormal) {
        assert(outwardNormal.length() == 1.0);

        frontFace = dot(r.direction(), outwardNormal) < 0;
        normal = frontFace ? outwardNormal : -outwardNormal;
    }
};

class hittable {
public:
    virtual ~hittable() = default;

    virtual bool isHit(const ray &r, double tMin, double tMax, hitRecord &rec) const = 0;
};
