#include <gtest/gtest.h>

#include "sphere.hpp"

TEST(SphereTest, Constructor) {
	EXPECT_NO_THROW(Sphere<float32_t>(
		Vec3<float32_t>({ 3.0f, 0.0f, 0.0f }), 5.0f
	));
}

TEST(SphereTest, IsItPossibleToHitTheSphere) {
	Ray<float32_t> r(
		Vec3<float32_t>({ 0.0f, 0.0f, 0.0f }),
		Vec3<float32_t>({ 1.0f, 0.0f, 0.0f })
	);

	Sphere<float32_t> s(
		Vec3<float32_t>({ 10.0f, 0.0f, 0.0f }), 5.0f
	);

	HitRecord<float32_t> record;

	bool res = s.Hit(r, 4.9f, 15.0f, record);

	EXPECT_TRUE(res);
}

TEST(SphereTest, CheckCorrectValuesAfterHitTheSphere) {
	Ray<float32_t> r(
		Vec3<float32_t>({ 0.0f, 0.0f, 0.0f }),
		Vec3<float32_t>({ 1.0f, 0.0f, 0.0f })
	);

	Sphere<float32_t> s(
		Vec3<float32_t>({ 10.0f, 0.0f, 0.0f }), 5.0f
	);

	Vec3<float32_t> norm({ -1.0f, 0.0f, 0.0f });
	Vec3<float32_t> hit_point({ 5.0f, 0.0f, 0.0f });

	HitRecord<float32_t> record;

	bool res = s.Hit(r, 4.9f, 15.0f, record);

	EXPECT_TRUE(res);

	for(std::size_t i = 0; i < 3; ++i) {
		EXPECT_FLOAT_EQ(record.normal[i], norm[i]);
		EXPECT_FLOAT_EQ(record.p[i], hit_point[i]);
	}
	EXPECT_FLOAT_EQ(record.t, 5.0f);
}
