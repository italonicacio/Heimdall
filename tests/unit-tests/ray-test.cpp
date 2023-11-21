
#include <gtest/gtest.h>


#include "ray.hpp"

TEST(RayTest, Constructor) {
	Vec3 v1({ 1.0, 1.0, 1.0 });
	Vec3 v2({ 1.0, 1.0, 1.0 });

	Ray r(v1, v2);


	EXPECT_EQ(r.A.elements[0], 1.0);
	EXPECT_EQ(r.B.elements[0], 1.0);
}

TEST(RayTest, GetOrigin) {
	Vec3 v1({ 1.0, 1.0, 1.0 });
	Vec3 v2({ 2.0, 2.0, 2.0 });

	Ray r(v1, v2);
	Vec3 res = r.Origin();

	EXPECT_EQ(res[0], 1.0);
	EXPECT_EQ(res[1], 1.0);
	EXPECT_EQ(res[2], 1.0);
}

TEST(RayTest, GetDirection) {
	Vec3 v1({ 1.0, 1.0, 1.0 });
	Vec3 v2({ 2.0, 2.0, 2.0 });

	Ray r(v1, v2);
	Vec3 res = r.Direction();

	EXPECT_EQ(res[0], 2.0);
	EXPECT_EQ(res[1], 2.0);
	EXPECT_EQ(res[2], 2.0);
}

TEST(RayTest, GetPointAtParameter) {
	Vec3 v1({ 1.0, 1.0, 1.0 });
	Vec3 v2({ 2.0, 2.0, 2.0 });

	Ray r(v1, v2);
	Vec3 res = r.PointAtParameter(3.0);

	EXPECT_EQ(res[0], 7.0);
	EXPECT_EQ(res[1], 7.0);
	EXPECT_EQ(res[2], 7.0);
}

