#pragma once
#include "hittable.h"
#include <memory>
#include <utility>
#include <vector>

class hlist : public hittable {
public:
    std::vector<std::shared_ptr<hittable>> objects;

    hlist() = default;
    explicit hlist(const std::shared_ptr<hittable> &object) { add(object); }

    void clear() { objects.clear(); }
    void add(const std::shared_ptr<hittable> &object) { objects.emplace_back(object); }

    [[nodiscard]] bool isHit(const ray &r, double tMin, double tMax, hitRecord &rec) const override;
};