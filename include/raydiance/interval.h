#pragma once
#include "utils.h"

class interval {
public:
    double min;
    double max;

    interval() : min(infinity), max(-infinity) {}// Default interval is empty
    interval(double min, double max) : min(min), max(max) {}

    [[nodiscard]] bool contains(double x) const { return x >= min && x <= max; }
    [[nodiscard]] bool surrounds(double x) const { return x > min && x < max; }

    [[nodiscard]] double clamp(double x) const {
        if (x < min) return min;
        if (x > max) return max;
        return x;
    }

    static const interval empty;
    static const interval universe;
};