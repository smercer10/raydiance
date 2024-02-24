#include "raydiance/hlist.h"

bool hlist::isHit(const ray &r, double tMin, double tMax, hitRecord &rec) const {
    hitRecord tempRec;
    bool hitAnything = false;
    auto closestSoFar = tMax;

    for (const auto &object: objects) {
        if (object->isHit(r, tMin, closestSoFar, tempRec)) {
            hitAnything = true;
            closestSoFar = tempRec.t;
            rec = tempRec;
        }
    }

    return hitAnything;
}