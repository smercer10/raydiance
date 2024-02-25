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

// Aka matte
class lambertian : public material {
public:
    explicit lambertian(const colour &a) : albedo(a) {}

    bool scatter(const ray &rIn, const intersection &i, colour &attenuation, ray &scattered) const override;

private:
    colour albedo;
};

class metal : public material {
public:
    metal(const colour &a, double f) : albedo(a), fuzz(f < 1.0 ? f : 1.0) {}

    bool scatter(const ray &rIn, const intersection &i, colour &attenuation, ray &scattered) const override;

private:
    colour albedo;
    double fuzz;// 0.0 = no fuzz, 1.0 = maximum fuzz
};

// E.g. glass, diamond, water
class dielectric : public material {
public:
    explicit dielectric(double ri) : refractionIndex(ri) {}

    bool scatter(const ray &rIn, const intersection &i, colour &attenuation, ray &scattered) const override;

private:
    double refractionIndex;

    static double reflectance(double cosine, double refractionIndex);
};