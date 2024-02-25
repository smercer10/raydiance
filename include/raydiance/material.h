#pragma once
#include "colour.h"
#include "object.h"
#include "ray.h"

class intersection;

class material {
public:
    virtual ~material() = default;

    // Returns true if the ray is scattered, false otherwise
    virtual bool scatter(const ray &rIn, const intersection &i, colour &attenuation, ray &scattered) const = 0;
};

class lambertian : public material {
public:
    explicit lambertian(const colour &a) : albedo(a) {}

    // Always scatters
    bool scatter(const ray &rIn, const intersection &i, colour &attenuation, ray &scattered) const override;

private:
    colour albedo;
};

class metal : public material {
public:
    metal(const colour &a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}

    bool scatter(const ray &rIn, const intersection &i, colour &attenuation, ray &scattered) const override;

private:
    colour albedo;
    double fuzz;
};