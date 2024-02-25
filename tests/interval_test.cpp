#include "raydiance/interval.h"
#include <gtest/gtest.h>

TEST(IntervalTest, Contains) {
    interval i(0, 1);
    EXPECT_TRUE(i.contains(0));
    EXPECT_TRUE(i.contains(1));
    EXPECT_TRUE(i.contains(0.5));
    EXPECT_FALSE(i.contains(-0.1));
    EXPECT_FALSE(i.contains(2));
}

TEST(IntervalTest, Surrounds) {
    interval i(0, 1);
    EXPECT_TRUE(i.surrounds(0.1));
    EXPECT_TRUE(i.surrounds(0.95));
    EXPECT_FALSE(i.surrounds(0));
    EXPECT_FALSE(i.surrounds(1));
}

TEST(IntervalTest, Empty) {
    interval i{interval::empty};
    EXPECT_FALSE(i.contains(0));
    EXPECT_FALSE(i.contains(-50));
    EXPECT_FALSE(i.surrounds(100));
}

TEST(IntervalTest, Universe) {
    interval i{interval::universe};
    EXPECT_TRUE(i.contains(-20));
    EXPECT_TRUE(i.contains(5));
    EXPECT_TRUE(i.contains(infinity));
    EXPECT_FALSE(i.surrounds(infinity));
    EXPECT_TRUE(i.contains(-infinity));
    EXPECT_FALSE(i.surrounds(-infinity));
}

TEST(IntervalTest, Clamp) {
    interval i(0.0, 1.0);
    EXPECT_DOUBLE_EQ(i.clamp(0.5), 0.5);
    EXPECT_DOUBLE_EQ(i.clamp(0.0), 0.0);
    EXPECT_DOUBLE_EQ(i.clamp(1.0), 1.0);
    EXPECT_DOUBLE_EQ(i.clamp(-0.5), 0.0);
    EXPECT_DOUBLE_EQ(i.clamp(1.5), 1.0);
}
