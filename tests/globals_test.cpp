#include "raydiance/globals.h"
#include <gtest/gtest.h>

TEST(GlobalsTest, degreesToRadians) {
    EXPECT_DOUBLE_EQ(degreesToRadians(0.0), 0);
    EXPECT_DOUBLE_EQ(degreesToRadians(90.0), pi / 2);
    EXPECT_DOUBLE_EQ(degreesToRadians(180.0), pi);
    EXPECT_DOUBLE_EQ(degreesToRadians(270.0), 3 * pi / 2);
    EXPECT_DOUBLE_EQ(degreesToRadians(360.0), 2 * pi);
}