#include "raydiance/hlist.h"

bool hlist::isHit(const ray &r, interval tRange, hitRecord &rec) const {
    hitRecord tempRec;
    bool hitAnything = false;
    auto closestSoFar = tRange.max;

    for (const auto &object: objects) {
        if (object->isHit(r, interval(tRange.min, closestSoFar), tempRec)) {
            hitAnything = true;
            closestSoFar = tempRec.t;
            rec = tempRec;
        }
    }

    return hitAnything;
}