#include "raydiance/colour.h"
#include <gtest/gtest.h>

TEST(ColourTest, ElementAccess) {
    colour c(0.5, 0.6, 0.7);
    EXPECT_DOUBLE_EQ(c.r(), 0.5);
    EXPECT_DOUBLE_EQ(c.g(), 0.6);
    EXPECT_DOUBLE_EQ(c.b(), 0.7);
}

TEST(ColourTest, Addition) {
    colour c1(0.001, 0.6, 0.7);
    colour c2(0.0, 0.1, 1.0);
    colour c3 = c1 + c2;
    EXPECT_DOUBLE_EQ(c3.r(), 0.001);
    EXPECT_DOUBLE_EQ(c3.g(), 0.7);
    EXPECT_DOUBLE_EQ(c3.b(), 1.7);
}