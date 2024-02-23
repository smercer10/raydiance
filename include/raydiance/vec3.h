#pragma once

namespace vec3 {
    class vec3 {
    public:
        double e[3];

        vec3() : e{0, 0, 0} {}
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

        [[nodiscard]] double x() const;
        [[nodiscard]] double y() const;
        [[nodiscard]] double z() const;

        vec3 operator-() const;         // Unary minus
        double operator[](int i) const; // Read-only access
        double &operator[](int i);      // Read-write access
        vec3 &operator+=(const vec3 &v);// Vector addition
        vec3 &operator*=(double t);     // Scalar multiplication
        vec3 &operator/=(double t);     // Scalar division

        [[nodiscard]] double length() const;
        [[nodiscard]] double lengthSquared() const;
    };
}// namespace vec3