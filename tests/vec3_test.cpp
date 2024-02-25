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

TEST(Vec3ClassTest, IsNearZero) {
    vec3 v1(0.0, 0.0, 0.0);
    EXPECT_TRUE(v1.isNearZero());

    vec3 v2(1e-9, 1e-9, 1e-9);
    EXPECT_TRUE(v2.isNearZero());

    vec3 v3(0.0, 1e-5, 0);
    EXPECT_FALSE(v3.isNearZero());

    vec3 v4(1e-8, 1e-8, 1e-8);
    EXPECT_FALSE(v4.isNearZero());
}

TEST(Vec3HelperTest, Addition) {
    vec3 v1(0.5, -0.6, 0.7);
    vec3 v2(0.11, 0.0, 0.3);
    vec3 v3 = v1 + v2;
    EXPECT_DOUBLE_EQ(v3.x(), 0.61);
    EXPECT_DOUBLE_EQ(v3.y(), -0.6);
    EXPECT_DOUBLE_EQ(v3.z(), 1.0);
}

TEST(Vec3HelperTest, Subtraction) {
    vec3 v1(0.8, 0.6, 0.3);
    vec3 v2(0.01, 0.2, 0.7);
    vec3 v3 = v1 - v2;
    EXPECT_DOUBLE_EQ(v3.x(), 0.79);
    EXPECT_DOUBLE_EQ(v3.y(), 0.4);
    EXPECT_DOUBLE_EQ(v3.z(), -0.4);
}

TEST(Vec3HelperTest, HadamardProduct) {
    vec3 v1(0.5, 0.6, 0.7);
    vec3 v2(0.1, -0.2, 0.0);
    vec3 v3 = v1 * v2;
    EXPECT_DOUBLE_EQ(v3.x(), 0.05);
    EXPECT_DOUBLE_EQ(v3.y(), -0.12);
    EXPECT_DOUBLE_EQ(v3.z(), 0.0);
}

TEST(Vec3HelperTest, ScalarMultiplication) {
    vec3 v1(0.5, 0.6, -0.7);
    vec3 v2 = v1 * 2;
    EXPECT_DOUBLE_EQ(v2.x(), 1.0);
    EXPECT_DOUBLE_EQ(v2.y(), 1.2);
    EXPECT_DOUBLE_EQ(v2.z(), -1.4);

    vec3 v3 = 3 * v2;
    EXPECT_DOUBLE_EQ(v3.x(), 3.0);
    EXPECT_DOUBLE_EQ(v3.y(), 3.6);
    EXPECT_DOUBLE_EQ(v3.z(), -4.2);
}

TEST(Vec3HelperTest, ScalarDivision) {
    vec3 v1(0.5, 0.6, -0.7);
    vec3 v2 = v1 / 2;
    EXPECT_DOUBLE_EQ(v2.x(), 0.25);
    EXPECT_DOUBLE_EQ(v2.y(), 0.3);
    EXPECT_DOUBLE_EQ(v2.z(), -0.35);
}

TEST(Vec3HelperTest, DotProduct) {
    vec3 v1(0.5, 0.6, 0.7);
    vec3 v2(0.1, -0.2, 0.0);
    EXPECT_DOUBLE_EQ(dot(v1, v2), -0.07);
}

TEST(Vec3HelperTest, CrossProduct) {
    vec3 v1(0.5, 0.6, 0.7);
    vec3 v2(0.1, -0.2, 0.0);
    vec3 v3 = cross(v1, v2);
    EXPECT_DOUBLE_EQ(v3.x(), 0.14);
    EXPECT_DOUBLE_EQ(v3.y(), 0.07);
    EXPECT_DOUBLE_EQ(v3.z(), -0.16);

    vec3 v4 = cross(v2, v1);
    EXPECT_DOUBLE_EQ(v4.x(), -0.14);
    EXPECT_DOUBLE_EQ(v4.y(), -0.07);
    EXPECT_DOUBLE_EQ(v4.z(), 0.16);
}

TEST(Vec3HelperTest, UnitVector) {
    vec3 v1(0.5, 0.6, 0.7);
    vec3 v2 = unitVector(v1);
    EXPECT_DOUBLE_EQ(v2.length(), 1.0);
    EXPECT_DOUBLE_EQ(v2.x(), 0.476731294622796);
    EXPECT_DOUBLE_EQ(v2.y(), 0.572077553547355);
    EXPECT_DOUBLE_EQ(v2.z(), 0.667423812471915);
}

TEST(Vec3HelperTest, Reflect) {
    vec3 v1(0.5, 0.6, 0.7);
    vec3 n1(0.1, -0.2, 0.5);
    vec3 r1 = reflect(v1, n1);
    EXPECT_DOUBLE_EQ(r1.x(), 0.44400000000000001);
    EXPECT_DOUBLE_EQ(r1.y(), 0.71199999999999997);
    EXPECT_DOUBLE_EQ(r1.z(), 0.41999999999999998);

    vec3 v2(0.5, 0.6, 0.7);
    vec3 n2(0.0, 0.0, 0.0);
    vec3 r2 = reflect(v2, n2);
    EXPECT_DOUBLE_EQ(r2.x(), 0.5);
    EXPECT_DOUBLE_EQ(r2.y(), 0.6);
    EXPECT_DOUBLE_EQ(r2.z(), 0.7);
}