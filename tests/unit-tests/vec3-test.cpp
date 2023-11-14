#include "gtest/gtest.h"
#include "Vec3.hpp"

TEST(Vec3Test, CrossProductF32) {
	// Arrange
	Vec3f32 v1({ 1.0f, 0.0f, 0.0f });
	Vec3f32 v2({ 0.0f, 1.0f, 0.0f });

	// Act
	Vec3f32 crossProduct = v1.Cross(v2);

	// Assert
	EXPECT_FLOAT_EQ(crossProduct[0], 0.0f);
	EXPECT_FLOAT_EQ(crossProduct[1], 0.0f);
	EXPECT_FLOAT_EQ(crossProduct[2], 1.0f);
}

TEST(Vec3Test, CrossProductF64) {

	Vec3f64 v1({ 1.0, 0.0, 0.0 });
	Vec3f64 v2({ 0.0, 1.0, 0.0 });


	Vec3f64 crossProduct = v1.Cross(v2);


	EXPECT_FLOAT_EQ(crossProduct[0], 0.0);
	EXPECT_FLOAT_EQ(crossProduct[1], 0.0);
	EXPECT_FLOAT_EQ(crossProduct[2], 1.0);
}

TEST(Vec3Test, UnitVector) {

	Vec3f64 v1({ 1.0, 1.0, 1.0 });



	Vec3f64 unit = UnitVector(v1);
	std::cout << v1.Length() << "\n";

	EXPECT_NEAR(unit[0], 0.5773, 1e-4);
	EXPECT_NEAR(unit[1], 0.5773, 1e-4);
	EXPECT_NEAR(unit[2], 0.5773, 1e-4);
}

TEST(Vec3Test, ValidatingInheritance) {

	Vec3f64 v1({ 1.0, 1.0, 1.0 });
	Vec3f64 v2({ 1.0, 1.0, 1.0 });


	Vec3f64 sum = v1 + v2;

	EXPECT_FLOAT_EQ(sum[0], 2.0);
	EXPECT_FLOAT_EQ(sum[1], 2.0);
	EXPECT_FLOAT_EQ(sum[2], 2.0);

	Vec3f64 sub = v1 - v2;

	EXPECT_FLOAT_EQ(sub[0], 0.0);
	EXPECT_FLOAT_EQ(sub[1], 0.0);
	EXPECT_FLOAT_EQ(sub[2], 0.0);

	Vec3f64 multi_scalar = v1 * 2.0;

	EXPECT_FLOAT_EQ(multi_scalar[0], 2.0);
	EXPECT_FLOAT_EQ(multi_scalar[1], 2.0);
	EXPECT_FLOAT_EQ(multi_scalar[2], 2.0);

}

