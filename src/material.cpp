#include "raydiance/material.h"

bool lambertian::scatter(const ray &rIn, const intersection &i, colour &attenuation, ray &scattered) const {
    vec3 scatterDirection{i.normal + randomUnitVector()};

    // Catch degenerate scatter direction
    if (scatterDirection.isNearZero()) {
        scatterDirection = i.normal;
    }

    scattered = ray{i.p, scatterDirection};
    attenuation = albedo;
    return true;
}
bool metal::scatter(const ray &rIn, const intersection &i, colour &attenuation, ray &scattered) const {
    vec3 reflected{reflect(unitVector(rIn.direction()), i.normal)};
    scattered = ray{i.p, reflected + fuzz * randomUnitVector()};
    attenuation = albedo;

    return dot(scattered.direction(), i.normal) > 0;
}
