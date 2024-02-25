#include "raydiance/scene.h"
#include "raydiance/sphere.h"
#include <gtest/gtest.h>

TEST(SceneTest, Add) {
    auto m = std::make_shared<lambertian>(colour{0.0, 0.0, 0.0});
    auto o = std::make_shared<sphere>(point3{0, 0, -1}, 0.5, m);

    scene s(o);
    EXPECT_EQ(s.objects.size(), 1);

    s.add(o);
    s.add(o);
    EXPECT_EQ(s.objects.size(), 3);
}

TEST(SceneTest, Clear) {
    auto m = std::make_shared<lambertian>(colour{0.0, 0.0, 0.0});
    auto o = std::make_shared<sphere>(point3{0, 0, -1}, 0.5, m);

    scene s;
    s.add(o);
    s.add(o);
    s.add(o);
    EXPECT_EQ(s.objects.size(), 3);

    s.clear();
    EXPECT_EQ(s.objects.size(), 0);
}

TEST(SceneTest, IsHit) {
    ray r{point3{0, 0, 0}, vec3{0, 0, -1}};
    interval tRange{0.0, infinity};
    intersection i;
    scene s;
    EXPECT_FALSE(s.isHit(r, tRange, i));

    auto m = std::make_shared<lambertian>(colour{0.0, 0.0, 0.0});

    s.add(std::make_shared<sphere>(point3{0, 0, 1}, 0.5, m));
    EXPECT_FALSE(s.isHit(r, tRange, i));

    s.add(std::make_shared<sphere>(point3{0, 0, -1}, 0.5, m));
    s.add(std::make_shared<sphere>(point3{0, 0, -0.5}, 100, m));
    s.add(std::make_shared<sphere>(point3{0, 0, -3}, 1, m));
    EXPECT_TRUE(s.isHit(r, tRange, i));
    EXPECT_DOUBLE_EQ(i.t, 0.5);
    EXPECT_DOUBLE_EQ(i.p.x(), 0);
    EXPECT_DOUBLE_EQ(i.p.y(), 0);
    EXPECT_DOUBLE_EQ(i.p.z(), -0.5);
}