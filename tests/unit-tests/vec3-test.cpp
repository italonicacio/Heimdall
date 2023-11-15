#include "gtest/gtest.h"
#include "vec3.hpp"

TEST(Vec3Test, CrossProductF32) {
	// Arrange
	Vec3<float32_t> v1({ 1.0f, 0.0f, 0.0f });
	Vec3<float32_t> v2({ 0.0f, 1.0f, 0.0f });

	// Act
	Vec3<float32_t> crossProduct = v1.Cross(v2);

	// Assert
	EXPECT_FLOAT_EQ(crossProduct[0], 0.0f);
	EXPECT_FLOAT_EQ(crossProduct[1], 0.0f);
	EXPECT_FLOAT_EQ(crossProduct[2], 1.0f);
}

TEST(Vec3Test, CrossProductF64) {

	Vec3<float64_t> v1({ 1.0, 0.0, 0.0 });
	Vec3<float64_t> v2({ 0.0, 1.0, 0.0 });


	Vec3<float64_t> crossProduct = v1.Cross(v2);


	EXPECT_FLOAT_EQ(crossProduct[0], 0.0);
	EXPECT_FLOAT_EQ(crossProduct[1], 0.0);
	EXPECT_FLOAT_EQ(crossProduct[2], 1.0);
}

TEST(Vec3Test, UnitVector) {

	Vec3<float64_t> v1({ 1.0, 1.0, 1.0 });

	Vec3<float64_t> unit = UnitVector(v1);

	EXPECT_NEAR(unit[0], 0.5773, 1e-4);
	EXPECT_NEAR(unit[1], 0.5773, 1e-4);
	EXPECT_NEAR(unit[2], 0.5773, 1e-4);
}

TEST(Vec3Test, ValidatingInheritance) {

	Vec3<float64_t> v1({ 1.0, 1.0, 1.0 });
	Vec3<float64_t> v2({ 1.0, 1.0, 1.0 });


	Vec3<float64_t> sum = v1 + v2;

	EXPECT_FLOAT_EQ(sum[0], 2.0);
	EXPECT_FLOAT_EQ(sum[1], 2.0);
	EXPECT_FLOAT_EQ(sum[2], 2.0);

	Vec3<float64_t> sub = v1 - v2;

	EXPECT_FLOAT_EQ(sub[0], 0.0);
	EXPECT_FLOAT_EQ(sub[1], 0.0);
	EXPECT_FLOAT_EQ(sub[2], 0.0);

	Vec3<float64_t> multi_scalar = v1 * 2.0;

	EXPECT_FLOAT_EQ(multi_scalar[0], 2.0);
	EXPECT_FLOAT_EQ(multi_scalar[1], 2.0);
	EXPECT_FLOAT_EQ(multi_scalar[2], 2.0);

}

