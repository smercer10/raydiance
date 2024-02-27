#include "raydiance/object.h"
#include <gtest/gtest.h>

TEST(IntersectionTest, SetFaceNormal) {
    ray r1(point3{0.0, 0.0, 0.0}, vec3{0.0, 0.0, 1.0});
    vec3 on1{0.0, 0.0, -1.0};
    intersection i1;
    i1.setFaceNormal(r1, on1);
    EXPECT_TRUE(i1.frontFace);
    EXPECT_DOUBLE_EQ(i1.normal.x(), 0.0);
    EXPECT_DOUBLE_EQ(i1.normal.y(), 0.0);
    EXPECT_DOUBLE_EQ(i1.normal.z(), -1.0);

    ray r2(point3{0.0, 0.0, 0.0}, vec3{0.0, 0.0, -1.0});
    vec3 on2{0.0, 0.0, -1};
    intersection i2;
    i2.setFaceNormal(r2, on2);
    EXPECT_FALSE(i2.frontFace);
    EXPECT_DOUBLE_EQ(i2.normal.x(), 0.0);
    EXPECT_DOUBLE_EQ(i2.normal.y(), 0.0);
    EXPECT_DOUBLE_EQ(i2.normal.z(), 1.0);
}