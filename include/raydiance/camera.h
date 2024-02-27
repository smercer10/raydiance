#pragma once
#include "colour.h"
#include "object.h"
#include "vec3.h"
#include <ostream>

// The camera uses a right-handed coordinate system
class camera {
public:
    [[maybe_unused]] void setAspectRatio(double ratio) { aspectRatio = ratio; }
    [[maybe_unused]] void setImgWidth(int width) { imgWidth = width; }
    [[maybe_unused]] void setSamplesPerPixel(int samples) { samplesPerPixel = samples; }
    [[maybe_unused]] void setMaxDepth(int depth) { maxDepth = depth; }
    [[maybe_unused]] void setFieldOfView(double fov) { fieldOfView = fov; }
    [[maybe_unused]] void setLookFrom(const point3 &from) { lookFrom = from; }
    [[maybe_unused]] void setLookAt(const point3 &at) { lookAt = at; }
    [[maybe_unused]] void setCameraUp(const vec3 &up) { cameraUp = up; }
    [[maybe_unused]] void setDefocusAngle(double angle) { defocusAngle = angle; }
    [[maybe_unused]] void setFocusDistance(double distance) { focusDistance = distance; }

    // Initialize the camera and render the world
    void render(std::ostream &imgOut, const object &world);

private:
    vec3 horPixelSpacing;
    vec3 verPixelSpacing;
    point3 zerothPixel;// Pixel at (0, 0) of the image

    // Forms an orthonormal basis for the camera's coordinate system
    vec3 u;// Points to the right of the camera
    vec3 v;// Points up from the camera
    vec3 w;// Points out from the camera

    vec3 defocusDiskU;// Horizontal radius of the camera defocus disk
    vec3 defocusDiskV;// Vertical radius of the camera defocus disk

    // Camera configuration
    double aspectRatio{16.0 / 9.0};
    int imgWidth{400};
    int imgHeight{};
    int samplesPerPixel{10};
    int maxDepth{10};        // Maximum number of bounces for a ray
    double fieldOfView{45.0};// Vertical field of view in degrees
    point3 lookFrom{0.0, 0.0, 0.0};
    point3 lookAt{0.0, 0.0, 1.0};
    vec3 cameraUp{0.0, 1.0, 0.0};// Up direction of the camera
    double defocusAngle{0.0};    // Variation angle of rays through each pixel
    double focusDistance{1.0};   // Distance from lookFrom to the focal plane

    // Initialize data members
    void initialize();

    // Get a randomly sampled ray for the pixel at (x, y)
    [[nodiscard]] ray getRay(int x, int y) const;

    // Gets the colour of the object that the ray intersects
    // If the ray doesn't intersect anything, returns the background colour
    static colour getRayColour(const ray &r, int depth, const object &world);

    // Get a vector from the centre of a pixel to a random point near the centre
    [[nodiscard]] vec3 samplePixel() const;

    // Get a random point in the camera defocus disk
    [[nodiscard]] point3 sampleDefocusDisk() const;
};