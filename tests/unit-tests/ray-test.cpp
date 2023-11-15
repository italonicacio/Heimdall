
#include <gtest/gtest.h>


#include "ray.hpp"

TEST(RayTest, Constructor) {
	Vec3<float32_t> v1({ 1.0f, 1.0f, 1.0f });
	Vec3<float32_t> v2({ 1.0f, 1.0f, 1.0f });

	Ray<float32_t> r(v1, v2);


	EXPECT_EQ(r.A.elements[0], 1.0f);
	EXPECT_EQ(r.B.elements[0], 1.0f);
}

TEST(RayTest, GetOrigin) {
	Vec3<float32_t> v1({ 1.0f, 1.0f, 1.0f });
	Vec3<float32_t> v2({ 2.0f, 2.0f, 2.0f });

	Ray<float32_t> r(v1, v2);
	Vec3 res = r.Origin();

	EXPECT_EQ(res[0], 1.0f);
	EXPECT_EQ(res[1], 1.0f);
	EXPECT_EQ(res[2], 1.0f);
}

TEST(RayTest, GetDirection) {
	Vec3<float32_t> v1({ 1.0f, 1.0f, 1.0f });
	Vec3<float32_t> v2({ 2.0f, 2.0f, 2.0f });

	Ray<float32_t> r(v1, v2);
	Vec3 res = r.Direction();

	EXPECT_EQ(res[0], 2.0);
	EXPECT_EQ(res[1], 2.0);
	EXPECT_EQ(res[2], 2.0);
}

TEST(RayTest, GetPointAtParameter) {
	Vec3<float32_t> v1({ 1.0f, 1.0f, 1.0f });
	Vec3<float32_t> v2({ 2.0f, 2.0f, 2.0f });

	Ray<float32_t> r(v1, v2);
	Vec3 res = r.PointAtParameter(3.0f);

	EXPECT_EQ(res[0], 7.0f);
	EXPECT_EQ(res[1], 7.0f);
	EXPECT_EQ(res[2], 7.0f);
}

