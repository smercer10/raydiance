#include "raydiance/utils.h"
#include <gtest/gtest.h>

TEST(UtilsTest, degreesToRadians) {
    EXPECT_DOUBLE_EQ(degreesToRadians(0.0), 0.0);
    EXPECT_DOUBLE_EQ(degreesToRadians(90.0), pi / 2.0);
    EXPECT_DOUBLE_EQ(degreesToRadians(180.0), pi);
    EXPECT_DOUBLE_EQ(degreesToRadians(270.0), 3.0 * pi / 2.0);
    EXPECT_DOUBLE_EQ(degreesToRadians(360.0), 2.0 * pi);
}