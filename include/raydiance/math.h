#pragma once
#include <limits>

namespace math {
    constexpr double infinity = std::numeric_limits<double>::infinity();
    constexpr double pi = 3.1415926535897932385;

    inline double degreesToRadians(double degrees) {
        return degrees * pi / 180;
    }
}// namespace math