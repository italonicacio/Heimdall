#include <gtest/gtest.h>
#include <cstdint>

#include "float-types.hpp"
#include "vec-template.hpp"


class VecTemplateTest : public ::testing::Test
{
public:
	std::array<int32_t, 3> arr3_1 = { 1, 1, 1 };
	std::array<int64_t, 3> arr3_2 = { 1, 1, 1 };
	std::array<float32_t, 3> arr3_3 = { 1.0f, 1.0f, 1.0f };
	std::array<float64_t, 3> arr3_4 = { 1.0, 1.0, 1.0 };

	std::array<int32_t, 5> arr5_1 = { 1, 1, 1, 1, 1 };
	std::array<int64_t, 5> arr5_2 = { 1, 1, 1, 1, 1 };
	std::array<float32_t, 5> arr5_3 = { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f };
	std::array<float64_t, 5> arr5_4 = { 1.0, 1.0, 1.0, 1.0, 1.0 };

	Vec<int32_t, 3> ivec3_1;
	Vec<int32_t, 3> ivec3_2;
	Vec<int64_t, 3> ivec3_3;
	Vec<int64_t, 3> ivec3_4;

	Vec<float32_t, 3> fvec3_1;
	Vec<float32_t, 3> fvec3_2;
	Vec<float64_t, 3> fvec3_3;
	Vec<float64_t, 3> fvec3_4;

	Vec<int32_t, 5> ivec5_1;
	Vec<int32_t, 5> ivec5_2;
	Vec<int64_t, 5> ivec5_3;
	Vec<int64_t, 5> ivec5_4;

	Vec<float32_t, 5> fvec5_1;
	Vec<float32_t, 5> fvec5_2;
	Vec<float64_t, 5> fvec5_3;
	Vec<float64_t, 5> fvec5_4;

private:
	void SetUp() override {
		ivec3_1 = ivec3_2 = arr3_1;
		ivec3_3 = ivec3_4 = arr3_2;

		fvec3_1 = fvec3_2 = arr3_3;
		fvec3_3 = fvec3_4 = arr3_4;

		ivec5_1 = ivec5_2 = arr5_1;
		ivec5_3 = ivec5_4 = arr5_2;

		fvec5_1 = fvec5_2 = arr5_3;
		fvec5_3 = fvec5_4 = arr5_4;
	}

	void TearDown() override {

	}
};


TEST_F(VecTemplateTest, SumVectors3_int) {
	Vec<int32_t, 3> sum1 = ivec3_1 + ivec3_2;
	Vec<int64_t, 3> sum2 = ivec3_3 + ivec3_4;

	for(auto e : sum1.elements) {
		EXPECT_EQ(e, 2);
	}

	for(auto e : sum2.elements) {
		EXPECT_EQ(e, 2);
	}

}


TEST_F(VecTemplateTest, SumVectors3_float) {
	Vec<float32_t, 3> sum1 = fvec3_1 + fvec3_2;
	Vec<float64_t, 3> sum2 = fvec3_3 + fvec3_4;

	for(auto e : sum1.elements) {
		EXPECT_FLOAT_EQ(e, 2.0f);
	}

	for(auto e : sum2.elements) {
		EXPECT_FLOAT_EQ(e, 2.0);
	}

}

TEST_F(VecTemplateTest, SumVectors5_int) {
	Vec<int32_t, 5> sum1 = ivec5_1 + ivec5_2;
	Vec<int64_t, 5> sum2 = ivec5_3 + ivec5_4;


	for(auto e : sum1.elements) {
		EXPECT_EQ(e, 2);
	}
}

TEST_F(VecTemplateTest, SumVectors5_float) {
	Vec<float32_t, 5> sum1 = fvec5_1 + fvec5_2;
	Vec<float64_t, 5> sum2 = fvec5_3 + fvec5_4;

	for(auto e : sum1.elements) {
		EXPECT_FLOAT_EQ(e, 2.0f);
	}

	for(auto e : sum2.elements) {
		EXPECT_FLOAT_EQ(e, 2.0);
	}

}
