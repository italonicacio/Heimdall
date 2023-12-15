#include <gtest/gtest.h>


#include "utils.hpp"


TEST(UtilsTest, ToLower) {
	std::string upper_string("UPper StrINg");
	std::string lower_string = Utils::ToLower(upper_string);
	EXPECT_STREQ(lower_string.data(), "upper string");
}


TEST(UtilsTest, HasWhiteSpaces) {
	std::string has_white_spaces("has white space");
	std::string has_no_white_spaces("has_no_white_spaces");
	std::string HasNoWhiteSpaces("HasNoWhiteSpaces");

	EXPECT_TRUE(Utils::HasWhiteSpaces(has_white_spaces));
	EXPECT_FALSE(Utils::HasWhiteSpaces(has_no_white_spaces));
	EXPECT_FALSE(Utils::HasWhiteSpaces(HasNoWhiteSpaces));

}

TEST(UtilsMathTest, RandomInUnitSphere) {
	Vec3 v = Utils::Math::RandomInUnitSphere();

	EXPECT_LE(v.SquaredLength(), 1.0);
}

TEST(UtilsMathTest, Rand64) {
	float64_t v1 = Utils::Math::Rand64();
	float64_t v2 = Utils::Math::Rand64();

	EXPECT_NE(v1, v2);
}

TEST(UtilsMathTest, Rand32) {
	float32_t v1 = Utils::Math::Rand32();
	float32_t v2 = Utils::Math::Rand32();

	EXPECT_NE(v1, v2);
}

TEST(UtilsMathTest, AutoRand) {
	Scalar v1 = Utils::Math::AutoRand();
	Scalar v2 = Utils::Math::AutoRand();

	EXPECT_NE(v1, v2);
}

