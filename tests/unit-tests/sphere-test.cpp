#include <gtest/gtest.h>

#include "sphere.hpp"

TEST(SphereTest, Constructor) {
	EXPECT_NO_THROW(Sphere(
		Vec3({ 3.0, 0.0, 0.0 }), 5.0
	));
}

TEST(SphereTest, IsItPossibleToHitTheSphere) {
	Ray r(
		Vec3({ 0.0, 0.0, 0.0 }),
		Vec3({ 1.0, 0.0, 0.0 })
	);

	Sphere s(
		Vec3({ 10.0, 0.0, 0.0 }), 5.0
	);

	HitRecord record;

	bool res = s.Hit(r, 4.9, 15.0, record);

	EXPECT_TRUE(res);
}

TEST(SphereTest, CheckCorrectValuesAfterHitTheSphere) {
	Ray r(
		Vec3({ 0.0, 0.0, 0.0 }),
		Vec3({ 1.0, 0.0, 0.0 })
	);

	Sphere s(
		Vec3({ 10.0, 0.0, 0.0 }), 5.0
	);

	Vec3 norm({ -1.0, 0.0, 0.0 });
	Vec3 hit_point({ 5.0, 0.0, 0.0 });

	HitRecord record;

	bool res = s.Hit(r, 4.9, 15.0, record);

	EXPECT_TRUE(res);

	for(std::size_t i = 0; i < 3; ++i) {
		EXPECT_FLOAT_EQ(record.normal[i], norm[i]);
		EXPECT_FLOAT_EQ(record.p[i], hit_point[i]);
	}
	EXPECT_FLOAT_EQ(record.t, 5.0);
}
