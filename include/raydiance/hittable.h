#pragma once
#include "interval.h"
#include "ray.h"
#include <cassert>

class hitRecord {
public:
    point3 p;
    vec3 normal;
    double t{};
    bool frontFace{};

    void setFaceNormal(const ray &r, const vec3 &outwardNormal) {
        frontFace = dot(r.direction(), outwardNormal) < 0;
        normal = frontFace ? outwardNormal : -outwardNormal;
    }
};

class hittable {
public:
    virtual ~hittable() = default;

    virtual bool isHit(const ray &r, interval tRange, hitRecord &rec) const = 0;
};
