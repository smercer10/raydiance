#pragma once
#include "camera.h"
#include "scene.h"
#include <nlohmann/json.hpp>

namespace config {
    void setCamera(const nlohmann::json &j, camera &cam);
    void addObjects(const nlohmann::json &j, scene &world);
}// namespace config