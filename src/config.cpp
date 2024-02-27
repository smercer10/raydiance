#include "raydiance/config.h"
#include "raydiance/sphere.h"
#include <iostream>
#include <memory>

// TODO: Better error handling
void config::setCamera(const nlohmann::json &j, camera &cam) {
    if (j.contains("camera")) {
        auto cameraConfig{j["camera"]};

        if (cameraConfig.contains("aspectRatio")) {
            cam.setAspectRatio(cameraConfig["aspectRatio"]);
        }
        if (cameraConfig.contains("imgWidth")) {
            cam.setImgWidth(cameraConfig["imgWidth"]);
        }
        if (cameraConfig.contains("samplesPerPixel")) {
            cam.setSamplesPerPixel(cameraConfig["samplesPerPixel"]);
        }
        if (cameraConfig.contains("maxDepth")) {
            cam.setMaxDepth(cameraConfig["maxDepth"]);
        }
        if (cameraConfig.contains("fieldOfView")) {
            cam.setFieldOfView(cameraConfig["fieldOfView"]);
        }
        if (cameraConfig.contains("lookFrom")) {
            cam.setLookFrom(point3{cameraConfig["lookFrom"]["x"], cameraConfig["lookFrom"]["y"], cameraConfig["lookFrom"]["z"]});
        }
        if (cameraConfig.contains("lookAt")) {
            cam.setLookAt(point3{cameraConfig["lookAt"]["x"], cameraConfig["lookAt"]["y"], cameraConfig["lookAt"]["z"]});
        }
        if (cameraConfig.contains("cameraUp")) {
            cam.setCameraUp(vec3{cameraConfig["cameraUp"]["x"], cameraConfig["cameraUp"]["y"], cameraConfig["cameraUp"]["z"]});
        }
        if (cameraConfig.contains("defocusAngle")) {
            cam.setDefocusAngle(cameraConfig["defocusAngle"]);
        }
        if (cameraConfig.contains("focusDistance")) {
            cam.setFocusDistance(cameraConfig["focusDistance"]);
        }
    } else {
        std::cout << "No camera configuration found, using default values.\n";
    }
}

// TODO: Better error handling
void config::addObjects(const nlohmann::json &j, scene &world) {
    if (j.contains("spheres")) {
        for (const auto &sphere: j["spheres"]) {
            point3 center{sphere["center"]["x"], sphere["center"]["y"], sphere["center"]["z"]};
            double radius{sphere["radius"]};
            std::shared_ptr<material> mat;

            if (sphere["material"]["type"] == "lambertian") {
                colour albedo{sphere["material"]["albedo"]["x"], sphere["material"]["albedo"]["y"], sphere["material"]["albedo"]["z"]};
                mat = std::make_shared<lambertian>(albedo);

            } else if (sphere["material"]["type"] == "metal") {
                colour albedo{sphere["material"]["albedo"]["x"], sphere["material"]["albedo"]["y"], sphere["material"]["albedo"]["z"]};
                double fuzz{sphere["material"]["fuzz"]};
                mat = std::make_shared<metal>(albedo, fuzz);

            } else if (sphere["material"]["type"] == "dielectric") {
                double refIdx{sphere["material"]["refIdx"]};
                mat = std::make_shared<dielectric>(refIdx);
            }

            world.add(std::make_shared<class sphere>(center, radius, mat));
        }
    } else {
        std::cout << "No spheres found in the configuration file. Was this intended?\n";
    }
}
