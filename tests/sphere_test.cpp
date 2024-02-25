#include "raydiance/sphere.h"
#include <gtest/gtest.h>

TEST(SphereTest, IsHit) {
    sphere s1{point3{0.0, 0.0, -4.0}, 1.0};
    sphere s2{point3{2.0, 0.0, 2.0}, 2.0};
    sphere s3{point3{0.0, 0.0, 5.0}, 2.0};

    ray r{point3{0.0, 0.0, 0.0}, vec3{0.0, 0.0, 1.0}};
    intersection i;

    EXPECT_FALSE(s1.isHit(r, interval{0.0, infinity}, i));

    EXPECT_TRUE(s2.isHit(r, interval{0.0, infinity}, i));
    EXPECT_DOUBLE_EQ(i.t, 2.0);
    EXPECT_DOUBLE_EQ(i.p.x(), 0.0);
    EXPECT_DOUBLE_EQ(i.p.y(), 0.0);
    EXPECT_DOUBLE_EQ(i.p.z(), 2.0);
    EXPECT_DOUBLE_EQ(i.normal.x(), 1.0);
    EXPECT_DOUBLE_EQ(i.normal.y(), 0.0);
    EXPECT_DOUBLE_EQ(i.normal.z(), 0.0);
    EXPECT_FALSE(i.frontFace);

    EXPECT_TRUE(s3.isHit(r, interval{0.0, infinity}, i));
    EXPECT_DOUBLE_EQ(i.t, 3.0);
    EXPECT_DOUBLE_EQ(i.p.x(), 0.0);
    EXPECT_DOUBLE_EQ(i.p.y(), 0.0);
    EXPECT_DOUBLE_EQ(i.p.z(), 3.0);
    EXPECT_DOUBLE_EQ(i.normal.x(), 0.0);
    EXPECT_DOUBLE_EQ(i.normal.y(), 0.0);
    EXPECT_DOUBLE_EQ(i.normal.z(), -1.0);
    EXPECT_TRUE(i.frontFace);
}