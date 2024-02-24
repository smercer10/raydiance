#pragma once
#include "interval.h"
#include "ray.h"
#include <cassert>

class intersection {
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

class object {
public:
    virtual ~object() = default;

    virtual bool isHit(const ray &r, interval tRange, intersection &rec) const = 0;
};
