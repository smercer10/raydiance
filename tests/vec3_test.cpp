#include "raydiance/vec3.h"
#include <gtest/gtest.h>

TEST(Vec3ClassTest, ElementAccess) {
    vec3 v1;
    EXPECT_DOUBLE_EQ(v1.x(), 0.0);
    EXPECT_DOUBLE_EQ(v1.y(), 0.0);
    EXPECT_DOUBLE_EQ(v1.z(), 0.0);

    vec3 v2(0.5, 0.6, 0.7);
    EXPECT_DOUBLE_EQ(v2.x(), 0.5);
    EXPECT_DOUBLE_EQ(v2.y(), 0.6);
    EXPECT_DOUBLE_EQ(v2.z(), 0.7);
}

TEST(Vec3ClassTest, Negation) {
    vec3 v1(0.5, 0.6, 0.7);
    vec3 v2 = -v1;
    EXPECT_DOUBLE_EQ(v2.x(), -0.5);
    EXPECT_DOUBLE_EQ(v2.y(), -0.6);
    EXPECT_DOUBLE_EQ(v2.z(), -0.7);

    vec3 v3 = -v2;
    EXPECT_DOUBLE_EQ(v3.x(), 0.5);
    EXPECT_DOUBLE_EQ(v3.y(), 0.6);
    EXPECT_DOUBLE_EQ(v3.z(), 0.7);
}

TEST(Vec3ClassTest, ReadWriteAccess) {
    vec3 v(0.5, 0.6, 0.7);
    EXPECT_DOUBLE_EQ(v[0], 0.5);
    EXPECT_DOUBLE_EQ(v[1], 0.6);
    EXPECT_DOUBLE_EQ(v[2], 0.7);

    v[0] = 0.1;
    v[1] = 0.2;
    v[2] = 0.3;
    EXPECT_DOUBLE_EQ(v[0], 0.1);
    EXPECT_DOUBLE_EQ(v[1], 0.2);
    EXPECT_DOUBLE_EQ(v[2], 0.3);
}

TEST(Vec3ClassTest, MutatingAddition) {
    vec3 v1(0.5, 0.6, 0.7);
    vec3 v2(0.1, 0.2, 0.3);
    v1 += v2;
    EXPECT_DOUBLE_EQ(v1.x(), 0.6);
    EXPECT_DOUBLE_EQ(v1.y(), 0.8);
    EXPECT_DOUBLE_EQ(v1.z(), 1.0);

    v1 += v1;
    EXPECT_DOUBLE_EQ(v1.x(), 1.2);
    EXPECT_DOUBLE_EQ(v1.y(), 1.6);
    EXPECT_DOUBLE_EQ(v1.z(), 2.0);
}

TEST(Vec3ClassTest, MutatingScalarMultiplication) {
    vec3 v(0.5, 0.6, 0.7);
    v *= 2;
    EXPECT_DOUBLE_EQ(v.x(), 1.0);
    EXPECT_DOUBLE_EQ(v.y(), 1.2);
    EXPECT_DOUBLE_EQ(v.z(), 1.4);

    v *= 0;
    EXPECT_DOUBLE_EQ(v.x(), 0.0);
    EXPECT_DOUBLE_EQ(v.y(), 0.0);
    EXPECT_DOUBLE_EQ(v.z(), 0.0);
}

TEST(Vec3ClassTest, MutatingScalarDivision) {
    vec3 v(0.5, 0.6, 0.7);
    v /= 2;
    EXPECT_DOUBLE_EQ(v.x(), 0.25);
    EXPECT_DOUBLE_EQ(v.y(), 0.3);
    EXPECT_DOUBLE_EQ(v.z(), 0.35);

    v /= 0.1;
    EXPECT_DOUBLE_EQ(v.x(), 2.5);
    EXPECT_DOUBLE_EQ(v.y(), 3.0);
    EXPECT_DOUBLE_EQ(v.z(), 3.5);
}

TEST(Vec3ClassTest, Length) {
    vec3 v1(0.5, -0.6, 0.7);
    EXPECT_DOUBLE_EQ(v1.length(), 1.0488088481701514);

    vec3 v2(0.0, 0.0, 0.0);
    EXPECT_DOUBLE_EQ(v2.length(), 0.0);
}

TEST(Vec3ClassTest, LengthSquared) {
    vec3 v1(-0.5, 0.6, -0.7);
    EXPECT_DOUBLE_EQ(v1.lengthSquared(), 1.1);

    vec3 v2(0.0, 0.0, 0.0);
    EXPECT_DOUBLE_EQ(v2.lengthSquared(), 0.0);
}