#include "gtest/gtest.h"
#include "vec3.hpp"


TEST(Vec3Test, ConstructorErrorWhenPassingMoreThan3Values) {
	EXPECT_ANY_THROW(Vec3({ 3.0, 0.0, 0.0, 0.0 }));
}

TEST(Vec3Test, CrossProduct) {
	// Arrange
	Vec3 v1({ 1.0, 0.0, 0.0 });
	Vec3 v2({ 0.0, 1.0, 0.0 });

	// Act
	Vec3 crossProduct = v1.Cross(v2);

	// Assert
	EXPECT_FLOAT_EQ(crossProduct[0], 0.0);
	EXPECT_FLOAT_EQ(crossProduct[1], 0.0);
	EXPECT_FLOAT_EQ(crossProduct[2], 1.0);
}

TEST(Vec3Test, UnitVector) {

	Vec3 v1({ 1.0, 1.0, 1.0 });

	Vec3 unit = UnitVector(v1);

	EXPECT_NEAR(unit[0], 0.5773, 1e-4);
	EXPECT_NEAR(unit[1], 0.5773, 1e-4);
	EXPECT_NEAR(unit[2], 0.5773, 1e-4);
}

TEST(Vec3Test, ValidatingInheritance) {

	Vec3 v1({ 1.0, 1.0, 1.0 });
	Vec3 v2({ 1.0, 1.0, 1.0 });


	Vec3 sum = v1 + v2;

	EXPECT_FLOAT_EQ(sum[0], 2.0);
	EXPECT_FLOAT_EQ(sum[1], 2.0);
	EXPECT_FLOAT_EQ(sum[2], 2.0);

	Vec3 sub = v1 - v2;

	EXPECT_FLOAT_EQ(sub[0], 0.0);
	EXPECT_FLOAT_EQ(sub[1], 0.0);
	EXPECT_FLOAT_EQ(sub[2], 0.0);

	Vec3 multi_scalar = v1 * 2.0;

	EXPECT_FLOAT_EQ(multi_scalar[0], 2.0);
	EXPECT_FLOAT_EQ(multi_scalar[1], 2.0);
	EXPECT_FLOAT_EQ(multi_scalar[2], 2.0);

}

