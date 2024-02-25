#pragma once
#include "interval.h"
#include "object.h"
#include <memory>
#include <utility>
#include <vector>

class scene : public object {
public:
    std::vector<std::shared_ptr<object>> objects;

    scene() = default;
    explicit scene(const std::shared_ptr<object> &object) { add(object); }

    void clear() { objects.clear(); }
    void add(const std::shared_ptr<object> &object) { objects.emplace_back(object); }
    [[nodiscard]] bool isHit(const ray &r, interval tRange, intersection &i) const override;
};