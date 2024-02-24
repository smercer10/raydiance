#pragma once
#include "raydiance/vec3.h"

// Vectors and colours should be treated as different types
class colour : private vec3 {
public:
    using vec3::vec3;

    // Makes more sense to access the colour components this way
    [[nodiscard]] double r() const { return e[0]; }
    [[nodiscard]] double g() const { return e[1]; }
    [[nodiscard]] double b() const { return e[2]; }

    colour &operator+(const colour &c) {
        e[0] += c.e[0];
        e[1] += c.e[1];
        e[2] += c.e[2];

        return *this;
    }

    void write(std::ostream &out) const {
        out << static_cast<int>(255.999 * r()) << ' '
            << static_cast<int>(255.999 * g()) << ' '
            << static_cast<int>(255.999 * b()) << '\n';
    }
};
