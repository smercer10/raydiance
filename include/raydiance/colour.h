#pragma once
#include <ostream>

// Vectors and colours should be treated as different types
class colour {
public:
    double e[3];

    colour() : e{0.0, 0.0, 0.0} {}
    colour(double r, double g, double b) : e{r, g, b} {}

    [[nodiscard]] double r() const { return e[0]; }
    [[nodiscard]] double g() const { return e[1]; }
    [[nodiscard]] double b() const { return e[2]; }

    colour &operator+=(const colour &c) {
        e[0] += c.e[0];
        e[1] += c.e[1];
        e[2] += c.e[2];

        return *this;
    }

    colour &operator*=(double a) {
        e[0] *= a;
        e[1] *= a;
        e[2] *= a;

        return *this;
    }
};

void writeColour(std::ostream &out, colour pixelColour, int samplesPerPixel);

inline colour operator+(const colour &c1, const colour &c2) {
    return {c1.r() + c2.r(), c1.g() + c2.g(), c1.b() + c2.b()};
}

inline colour operator*(double a, const colour &c) {
    return {a * c.r(), a * c.g(), a * c.b()};
}

inline colour operator*(const colour &c, double a) {
    return a * c;
}
