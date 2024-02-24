#pragma once
#include <cmath>
#include <ostream>

class vec3 {
public:
    double e[3];

    vec3() : e{0.0, 0.0, 0.0} {}
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

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

    vec3 &operator*=(double s) {
        e[0] *= s;
        e[1] *= s;
        e[2] *= s;

        return *this;
    }

    vec3 &operator/=(double s) { return *this *= 1 / s; }

    [[nodiscard]] double length() const { return std::sqrt(lengthSquared()); }

    [[nodiscard]] double lengthSquared() const {
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
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

inline vec3 operator*(double s, const vec3 &v) {
    return {s * v.e[0], s * v.e[1], s * v.e[2]};
}

inline vec3 operator*(const vec3 &v, double s) {
    return s * v;
}

inline vec3 operator/(vec3 v, double s) {
    return (1 / s) * v;
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