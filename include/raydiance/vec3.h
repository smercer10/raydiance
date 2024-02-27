#pragma once
#include "utils.h"
#include <cmath>
#include <ostream>

class vec3 {
public:
    double e[3];

    vec3() : e{0.0, 0.0, 0.0} {}
    vec3(double x, double y, double z) : e{x, y, z} {}

    [[nodiscard]] double x() const { return e[0]; }
    [[nodiscard]] double y() const { return e[1]; }
    [[nodiscard]] double z() const { return e[2]; }

    vec3 operator-() const { return {-e[0], -e[1], -e[2]}; }

    // Read-only access
    double operator[](int i) const { return e[i]; }

    // Read-write access
    double &operator[](int i) { return e[i]; }

    vec3 &operator+=(const vec3 &v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];

        return *this;
    }

    vec3 &operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;

        return *this;
    }

    vec3 &operator/=(double t) { return *this *= 1.0 / t; }

    [[nodiscard]] double length() const { return std::sqrt(lengthSquared()); }

    [[nodiscard]] double lengthSquared() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
    }

    [[nodiscard]] static vec3 random(double min = 0.0, double max = 1.0) {
        return {randomDouble(min, max), randomDouble(min, max), randomDouble(min, max)};
    }

    [[nodiscard]] static vec3 randomInUnitSphere() {
        while (true) {
            vec3 v{random(-1.0, 1.0)};
            if (v.lengthSquared() >= 1.0) continue;
            return v;
        }
    }

    static vec3 randomInUnitDisk() {
        while (true) {
            vec3 v{randomDouble(-1.0, 1.0), randomDouble(-1.0, 1.0), 0.0};
            if (v.lengthSquared() >= 1.0) continue;
            return v;
        }
    }

    // Checks if the vector is near zero in all dimensions
    [[nodiscard]] bool isNearZero() const {
        const auto threshold{1e-8};
        return (std::fabs(e[0]) < threshold) && (std::fabs(e[1]) < threshold) && (std::fabs(e[2]) < threshold);
    }
};

// A point is just a vector, so we can use these interchangeably
using point3 = vec3;

// Example usage: outStream << vecObj;
inline std::ostream &operator<<(std::ostream &out, const vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return {u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]};
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return {u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]};
}

// Hadamard product
inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return {u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]};
}

inline vec3 operator*(double t, const vec3 &v) {
    return {t * v.e[0], t * v.e[1], t * v.e[2]};
}

inline vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

inline vec3 operator/(vec3 v, double t) {
    return (1.0 / t) * v;
}

inline double dot(const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
    return {u.e[1] * v.e[2] - u.e[2] * v.e[1],
            u.e[2] * v.e[0] - u.e[0] * v.e[2],
            u.e[0] * v.e[1] - u.e[1] * v.e[0]};
}

inline vec3 unitVector(vec3 v) {
    return v / v.length();
}

inline vec3 randomUnitVector() {
    return unitVector(vec3::randomInUnitSphere());
}

inline vec3 reflect(const vec3 &v, const vec3 &n) {
    return v - 2.0 * dot(v, n) * n;
}

inline vec3 refract(const vec3 &v, const vec3 &n, double indexRatio) {
    auto cosTheta{std::fmin(dot(-v, n), 1.0)};

    vec3 rayOutPerp{indexRatio * (v + cosTheta * n)};
    vec3 rayOutParallel{-std::sqrt(std::fabs(1.0 - rayOutPerp.lengthSquared())) * n};

    return rayOutPerp + rayOutParallel;
}
