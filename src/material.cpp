#include "raydiance/material.h"

bool lambertian::scatter(const ray &rIn, const intersection &i, colour &attenuation, ray &scattered) const {
    // Scatter in a random direction
    vec3 scatterDirection{i.normal + randomUnitVector()};

    // Catch degenerate scatter direction
    if (scatterDirection.isNearZero()) {
        scatterDirection = i.normal;
    }

    scattered = ray{i.p, scatterDirection};
    attenuation = albedo;

    // Always scatters
    return true;
}

bool metal::scatter(const ray &rIn, const intersection &i, colour &attenuation, ray &scattered) const {
    // Calculate reflected ray
    vec3 reflected{reflect(unitVector(rIn.direction()), i.normal)};

    // Add random fuzz to the reflected ray
    scattered = ray{i.p, reflected + fuzz * randomUnitVector()};

    attenuation = albedo;

    // Only scatters if the reflected ray is in the same hemisphere as the normal
    return dot(scattered.direction(), i.normal) > 0.0;
}

bool dielectric::scatter(const ray &rIn, const intersection &i, colour &attenuation, ray &scattered) const {
    // All colours are equally attenuated
    attenuation = colour{1.0, 1.0, 1.0};

    double refractionRatio{i.frontFace ? (1.0 / refractionIndex) : refractionIndex};

    vec3 unitDirection{unitVector(rIn.direction())};

    // Get cosine of the angle between the incident ray and the normal
    double cosTheta{std::fmin(dot(-unitDirection, i.normal), 1.0)};

    // Get sine of the same angle using trigonometric identity
    double sinTheta{std::sqrt(1.0 - cosTheta * cosTheta)};

    // If total internal reflection occurs, refraction isn't possible
    bool cannotRefract{refractionRatio * sinTheta > 1.0};

    vec3 direction;

    if (cannotRefract || reflectance(cosTheta, refractionRatio) > randomDouble()) {
        direction = reflect(unitDirection, i.normal);
    } else {
        direction = refract(unitDirection, i.normal, refractionRatio);
    }

    scattered = ray{i.p, direction};

    // Always scatters
    return true;
}

double dielectric::reflectance(double cosine, double refractionIndex) {
    // Use Schlick's approximation for reflectance
    double r0{(1.0 - refractionIndex) / (1.0 + refractionIndex)};
    r0 *= r0;

    return r0 + (1.0 - r0) * std::pow((1.0 - cosine), 5.0);
}
