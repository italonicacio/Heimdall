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

	Vec<int32_t, 3> i32vec3_1;
	Vec<int32_t, 3> i32vec3_2;

	Vec<int64_t, 3> i64vec1_1;
	Vec<int64_t, 3> i64vec3_2;

	Vec<float32_t, 3> f32vec3_1;
	Vec<float32_t, 3> f32vec3_2;

	Vec<float64_t, 3> f64vec3_1;
	Vec<float64_t, 3> f64vec3_2;

	Vec<int32_t, 5> i32vec5_1;
	Vec<int32_t, 5> i32vec5_2;
	Vec<int64_t, 5> i64vec5_1;
	Vec<int64_t, 5> i64vec5_2;

	Vec<float32_t, 5> f32vec5_1;
	Vec<float32_t, 5> f32vec5_2;

	Vec<float64_t, 5> f64vec5_1;
	Vec<float64_t, 5> f64vec5_2;

private:
	void SetUp() override {
		i32vec3_1 = i32vec3_2 = arr3_1;
		i64vec1_1 = i64vec3_2 = arr3_2;

		f32vec3_1 = f32vec3_2 = arr3_3;
		f64vec3_1 = f64vec3_2 = arr3_4;

		i32vec5_1 = i32vec5_2 = arr5_1;
		i64vec5_1 = i64vec5_2 = arr5_2;

		f32vec5_1 = f32vec5_2 = arr5_3;
		f64vec5_1 = f64vec5_2 = arr5_4;
	}

	void TearDown() override {

	}
};


TEST_F(VecTemplateTest, SumVectors3_int) {
	Vec<int32_t, 3> sum1 = i32vec3_1 + i32vec3_2;
	Vec<int64_t, 3> sum2 = i64vec1_1 + i64vec3_2;

	for(auto e : sum1.elements) {
		EXPECT_EQ(e, 2);
	}

	for(auto e : sum2.elements) {
		EXPECT_EQ(e, 2);
	}
}


TEST_F(VecTemplateTest, SumVectors3_float) {
	Vec<float32_t, 3> sum1 = f32vec3_1 + f32vec3_2;
	Vec<float64_t, 3> sum2 = f64vec3_1 + f64vec3_2;

	for(auto e : sum1.elements) {
		EXPECT_FLOAT_EQ(e, 2.0f);
	}

	for(auto e : sum2.elements) {
		EXPECT_FLOAT_EQ(e, 2.0);
	}
}

TEST_F(VecTemplateTest, SumVectors5_int) {
	Vec<int32_t, 5> sum1 = i32vec5_1 + i32vec5_2;
	Vec<int64_t, 5> sum2 = i64vec5_1 + i64vec5_2;

	for(auto e : sum1.elements) {
		EXPECT_EQ(e, 2);
	}
}

TEST_F(VecTemplateTest, SumVectors5_float) {
	Vec<float32_t, 5> sum1 = f32vec5_1 + f32vec5_2;
	Vec<float64_t, 5> sum2 = f64vec5_1 + f64vec5_2;

	for(auto e : sum1.elements) {
		EXPECT_FLOAT_EQ(e, 2.0f);
	}

	for(auto e : sum2.elements) {
		EXPECT_FLOAT_EQ(e, 2.0);
	}

}

TEST_F(VecTemplateTest, SubtractionVectors3_int) {
	Vec<int32_t, 3> sum1 = i32vec3_1 - i32vec3_2;
	Vec<int64_t, 3> sum2 = i64vec1_1 - i64vec3_2;

	for(auto e : sum1.elements) {
		EXPECT_EQ(e, 0);
	}

	for(auto e : sum2.elements) {
		EXPECT_EQ(e, 0);
	}

}


TEST_F(VecTemplateTest, SubtractionVectors3_float) {
	Vec<float32_t, 3> sum1 = f32vec3_1 - f32vec3_2;
	Vec<float64_t, 3> sum2 = f64vec3_1 - f64vec3_2;

	for(auto e : sum1.elements) {
		EXPECT_FLOAT_EQ(e, 0.0f);
	}

	for(auto e : sum2.elements) {
		EXPECT_FLOAT_EQ(e, 0.0);
	}

}

TEST_F(VecTemplateTest, SubtractionVectors5_int) {
	Vec<int32_t, 5> sum1 = i32vec5_1 - i32vec5_2;
	Vec<int64_t, 5> sum2 = i64vec5_1 - i64vec5_2;

	for(auto e : sum1.elements) {
		EXPECT_EQ(e, 0);
	}

	for(auto e : sum2.elements) {
		EXPECT_EQ(e, 0);
	}
}

TEST_F(VecTemplateTest, SubtractionVectors5_float) {
	Vec<float32_t, 5> sum1 = f32vec5_1 - f32vec5_2;
	Vec<float64_t, 5> sum2 = f64vec5_1 - f64vec5_2;

	for(auto e : sum1.elements) {
		EXPECT_FLOAT_EQ(e, 0.0f);
	}

	for(auto e : sum2.elements) {
		EXPECT_FLOAT_EQ(e, 0.0);
	}
}

TEST_F(VecTemplateTest, DotVectors3_int) {
	int32_t dot1 = i32vec3_1 * i32vec3_2;
	int64_t dot2 = i64vec1_1 * i64vec3_2;

	EXPECT_EQ(dot1, 3);

	EXPECT_EQ(dot2, 3);
}

TEST_F(VecTemplateTest, DotVectors3_float) {
	float32_t dot1 = f32vec3_1 * f32vec3_2;
	float64_t dot2 = f64vec3_1 * f64vec3_2;
	std::array<float64_t, 3> arr = {
		1.0, 3.0, -5.0
	};

	std::array<float64_t, 3> arr2 = {
			4.0, -2.0, -1.0
	};

	float64_t dot3 = Vec<float64_t, 3>(arr) * Vec<float64_t, 3>(arr2);

	EXPECT_FLOAT_EQ(dot1, 3.0f);

	EXPECT_FLOAT_EQ(dot2, 3.0);

	EXPECT_FLOAT_EQ(dot3, 3.0);
}

TEST_F(VecTemplateTest, DotVectors5_int) {
	int32_t dot1 = i32vec5_1 * i32vec5_2;
	int64_t dot2 = i64vec5_1 * i64vec5_2;

	EXPECT_EQ(dot1, 5);

	EXPECT_EQ(dot2, 5);
}

TEST_F(VecTemplateTest, DotVectors5_float) {
	float32_t dot1 = f32vec5_1 * f32vec5_2;
	float64_t dot2 = f64vec5_1 * f64vec5_2;

	EXPECT_FLOAT_EQ(dot1, 5.0f);

	EXPECT_FLOAT_EQ(dot2, 5.0);
}
