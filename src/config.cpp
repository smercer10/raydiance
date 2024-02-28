#include "raydiance/config.h"
#include "raydiance/sphere.h"

#include <memory>

// TODO: Better error handling
void config::setCamera(const nlohmann::json &j, camera &cam) {
    if (j.contains("aspectRatio")) {
        cam.setAspectRatio(j["aspectRatio"]);
    }
    if (j.contains("imgWidth")) {
        cam.setImgWidth(j["imgWidth"]);
    }
    if (j.contains("samplesPerPixel")) {
        cam.setSamplesPerPixel(j["samplesPerPixel"]);
    }
    if (j.contains("maxDepth")) {
        cam.setMaxDepth(j["maxDepth"]);
    }
    if (j.contains("fieldOfView")) {
        cam.setFieldOfView(j["fieldOfView"]);
    }
    if (j.contains("lookFrom")) {
        cam.setLookFrom(point3{j["lookFrom"]["x"], j["lookFrom"]["y"], j["lookFrom"]["z"]});
    }
    if (j.contains("lookAt")) {
        cam.setLookAt(point3{j["lookAt"]["x"], j["lookAt"]["y"], j["lookAt"]["z"]});
    }
    if (j.contains("cameraUp")) {
        cam.setCameraUp(vec3{j["cameraUp"]["x"], j["cameraUp"]["y"], j["cameraUp"]["z"]});
    }
    if (j.contains("defocusAngle")) {
        cam.setDefocusAngle(j["defocusAngle"]);
    }
    if (j.contains("focusDistance")) {
        cam.setFocusDistance(j["focusDistance"]);
    }
}

// TODO: Better error handling
void config::addObjects(const nlohmann::json &j, scene &world) {
    if (j.contains("spheres")) {
        for (const auto &sphere: j["spheres"]) {
            point3 centre{sphere["centre"]["x"], sphere["centre"]["y"], sphere["centre"]["z"]};
            double radius{sphere["radius"]};
            std::shared_ptr<material> mat;

            if (sphere["material"]["type"] == "lambertian") {
                colour albedo{sphere["material"]["colour"]["r"], sphere["material"]["colour"]["g"], sphere["material"]["colour"]["b"]};
                mat = std::make_shared<lambertian>(albedo);

            } else if (sphere["material"]["type"] == "metal") {
                colour albedo{sphere["material"]["colour"]["r"], sphere["material"]["colour"]["g"], sphere["material"]["colour"]["b"]};
                double fuzz{sphere["material"]["fuzz"]};
                mat = std::make_shared<metal>(albedo, fuzz);

            } else if (sphere["material"]["type"] == "dielectric") {
                double refIdx{sphere["material"]["refIdx"]};
                mat = std::make_shared<dielectric>(refIdx);
            }

            world.add(std::make_shared<class sphere>(centre, radius, mat));
        }
    }
}
