#include "raydiance/scene.h"

bool scene::isHit(const ray &r, interval tRange, intersection &i) const {
    intersection tempI;
    bool hitAnything = false;
    auto closestSoFar = tRange.max;

    for (const auto &object: objects) {
        if (object->isHit(r, interval(tRange.min, closestSoFar), tempI)) {
            hitAnything = true;
            closestSoFar = tempI.t;
            i = tempI;
        }
    }

    return hitAnything;
}