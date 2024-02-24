#include "raydiance/ray.h"
#include <gtest/gtest.h>

TEST(RayTest, Accessors) {
    point3 origin(0.0, 0.0, 0.0);
    vec3 direction(1.0, 0.7, -0.05);
    ray r(origin, direction);
    EXPECT_DOUBLE_EQ(r.origin().x(), 0.0);
    EXPECT_DOUBLE_EQ(r.origin().y(), 0.0);
    EXPECT_DOUBLE_EQ(r.origin().z(), 0.0);
    EXPECT_DOUBLE_EQ(r.direction().x(), 1);
    EXPECT_DOUBLE_EQ(r.direction().y(), 0.7);
    EXPECT_DOUBLE_EQ(r.direction().z(), -0.05);
}

TEST(RayTest, PointAt) {
    point3 origin(0.0, 0.0, 0.0);
    vec3 direction(0.1, 0.4, -0.8);
    ray r(origin, direction);
    point3 p = r.at(5.0);
    EXPECT_DOUBLE_EQ(p.x(), 0.5);
    EXPECT_DOUBLE_EQ(p.y(), 2.0);
    EXPECT_DOUBLE_EQ(p.z(), -4.0);
}
