#include "raydiance/colour.h"
#include <gtest/gtest.h>

TEST(ColourClassTest, ElementAccess) {
    colour c(0.5, 0.6, 0.7);
    EXPECT_DOUBLE_EQ(c.r(), 0.5);
    EXPECT_DOUBLE_EQ(c.g(), 0.6);
    EXPECT_DOUBLE_EQ(c.b(), 0.7);
}

TEST(ColourClassTest, MutatingAddition) {
    colour c1(0.001, 0.6, 0.7);
    colour c2(0.0, 0.1, 1.0);
    c1 += c2;
    EXPECT_DOUBLE_EQ(c1.r(), 0.001);
    EXPECT_DOUBLE_EQ(c1.g(), 0.7);
    EXPECT_DOUBLE_EQ(c1.b(), 1.7);
}

TEST(ColourClassTest, MutatingScalarMultiplication) {
    colour c1(0.5, 0.6, 0.7);
    colour c2{2.0 * c1};
    EXPECT_DOUBLE_EQ(c2.r(), 1.0);
    EXPECT_DOUBLE_EQ(c2.g(), 1.2);
    EXPECT_DOUBLE_EQ(c2.b(), 1.4);
}

TEST(ColourHelperTest, Addition) {
    colour c1(0.5, 0.6, 0.7);
    colour c2(0.0, 0.1, 1.0);
    colour c3{c1 + c2};
    EXPECT_DOUBLE_EQ(c3.r(), 0.5);
    EXPECT_DOUBLE_EQ(c3.g(), 0.7);
    EXPECT_DOUBLE_EQ(c3.b(), 1.7);
}

TEST(ColourHelperTest, HadamardProduct) {
    colour c1(0.5, 0.6, 0.7);
    colour c2(0.0, 0.1, 1.0);
    colour c3{c1 * c2};
    EXPECT_DOUBLE_EQ(c3.r(), 0.0);
    EXPECT_DOUBLE_EQ(c3.g(), 0.06);
    EXPECT_DOUBLE_EQ(c3.b(), 0.7);
}

TEST(ColourHelperTest, ScalarMultiplication) {
    colour c1(0.5, 0.6, 0.7);
    colour c2{2.0 * c1};
    EXPECT_DOUBLE_EQ(c2.r(), 1.0);
    EXPECT_DOUBLE_EQ(c2.g(), 1.2);
    EXPECT_DOUBLE_EQ(c2.b(), 1.4);

    colour c3{c2 * 4.0};
    EXPECT_DOUBLE_EQ(c3.r(), 4.0);
    EXPECT_DOUBLE_EQ(c3.g(), 4.8);
    EXPECT_DOUBLE_EQ(c3.b(), 5.6);
}
