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

	Vec<int64_t, 3> i64vec3_1;
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
		i64vec3_1 = i64vec3_2 = arr3_2;

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

TEST_F(VecTemplateTest, GettingAnPositiveVector) {
	Vec<int32_t, 5> r1 = +i32vec5_1;
	Vec<int64_t, 5> r2 = +i64vec5_1;


	Vec<float32_t, 5> r3 = +f32vec5_1;
	Vec<float64_t, 5> r4 = +f64vec5_1;

	for(int i = 0; i < 5; ++i) {
		EXPECT_EQ(r1.elements[i], 1);
		EXPECT_EQ(r2.elements[i], 1);
		EXPECT_FLOAT_EQ(r3.elements[i], 1.0f);
		EXPECT_FLOAT_EQ(r4.elements[i], 1.0);
	}
}

TEST_F(VecTemplateTest, TurnAVectorIntoNegative) {
	Vec<int32_t, 5> r1 = -i32vec5_1;
	Vec<int64_t, 5> r2 = -i64vec5_1;


	Vec<float32_t, 5> r3 = -f32vec5_1;
	Vec<float64_t, 5> r4 = -f64vec5_1;

	for(int i = 0; i < 5; ++i) {
		EXPECT_EQ(r1.elements[i], -1);
		EXPECT_EQ(r2.elements[i], -1);
		EXPECT_FLOAT_EQ(r3.elements[i], -1.0f);
		EXPECT_FLOAT_EQ(r4.elements[i], -1.0);
	}
}

TEST_F(VecTemplateTest, GettingAValueByIndex) {
	int32_t v1 = i32vec5_1[0];
	int64_t v2 = i64vec5_1[4];


	float32_t v3 = f32vec5_1[2];
	float64_t v4 = f64vec5_1[3];


	EXPECT_EQ(v1, i32vec5_1.elements[0]);
	EXPECT_EQ(v2, i64vec5_1.elements[4]);
	EXPECT_FLOAT_EQ(v3, f32vec5_1.elements[2]);
	EXPECT_FLOAT_EQ(v4, f64vec5_1.elements[3]);
	EXPECT_ANY_THROW(f64vec5_1[5]);

}

TEST_F(VecTemplateTest, GettingAValueByIndex_Reference) {
	int32_t& v1 = i32vec5_1[0];
	int64_t& v2 = i64vec5_1[4];


	float32_t& v3 = f32vec5_1[2];
	float64_t& v4 = f64vec5_1[3];


	EXPECT_EQ(v1, i32vec5_1.elements[0]);
	EXPECT_EQ(v2, i64vec5_1.elements[4]);
	EXPECT_FLOAT_EQ(v3, f32vec5_1.elements[2]);
	EXPECT_FLOAT_EQ(v4, f64vec5_1.elements[3]);
	EXPECT_ANY_THROW(f64vec5_1[5]);

	v3 = 10.0;

	EXPECT_FLOAT_EQ(f32vec5_1.elements[2], 10.0);

}


TEST_F(VecTemplateTest, SumVectors3_int) {
	Vec<int32_t, 3> sum1 = i32vec3_1 + i32vec3_2;
	Vec<int64_t, 3> sum2 = i64vec3_1 + i64vec3_2;
	i64vec3_1 += i64vec3_2;

	for(std::size_t i = 0; i < 3; ++i) {
		EXPECT_EQ(sum1.elements[i], 2);
		EXPECT_EQ(sum2.elements[i], 2);
		EXPECT_EQ(i64vec3_1.elements[i], 2);
	}
}


TEST_F(VecTemplateTest, SumVectors3_float) {
	Vec<float32_t, 3> sum1 = f32vec3_1 + f32vec3_2;
	Vec<float64_t, 3> sum2 = f64vec3_1 + f64vec3_2;
	f64vec3_1 += f64vec3_2;

	for(std::size_t i = 0; i < 3; ++i) {
		EXPECT_FLOAT_EQ(sum1.elements[i], 2.0f);
		EXPECT_FLOAT_EQ(sum2.elements[i], 2.0);
		EXPECT_EQ(f64vec3_1.elements[i], 2);
	}
}

TEST_F(VecTemplateTest, SumVectors5_int) {
	Vec<int32_t, 5> sum1 = i32vec5_1 + i32vec5_2;
	Vec<int64_t, 5> sum2 = i64vec5_1 + i64vec5_2;
	i64vec5_1 += i64vec5_2;

	for(std::size_t i = 0; i < 3; ++i) {
		EXPECT_EQ(sum1.elements[i], 2);
		EXPECT_EQ(sum2.elements[i], 2);
		EXPECT_EQ(i64vec5_1.elements[i], 2);
	}
}

TEST_F(VecTemplateTest, SumVectors5_float) {
	Vec<float32_t, 5> sum1 = f32vec5_1 + f32vec5_2;
	Vec<float64_t, 5> sum2 = f64vec5_1 + f64vec5_2;
	f64vec5_1 += f64vec5_2;

	for(std::size_t i = 0; i < 3; ++i) {
		EXPECT_FLOAT_EQ(sum1.elements[i], 2.0f);
		EXPECT_FLOAT_EQ(sum2.elements[i], 2.0);
		EXPECT_FLOAT_EQ(f64vec5_1.elements[i], 2.0);
	}
}

TEST_F(VecTemplateTest, SubtractionVectors3_int) {
	Vec<int32_t, 3> sub1 = i32vec3_1 - i32vec3_2;
	Vec<int64_t, 3> sub2 = i64vec3_1 - i64vec3_2;
	i64vec3_1 -= i64vec3_2;

	for(std::size_t i = 0; i < 3; ++i) {
		EXPECT_EQ(sub1.elements[i], 0);
		EXPECT_EQ(sub2.elements[i], 0);
		EXPECT_EQ(i64vec3_1.elements[i], 0);
	}
}


TEST_F(VecTemplateTest, SubtractionVectors3_float) {
	Vec<float32_t, 3> sub1 = f32vec3_1 - f32vec3_2;
	Vec<float64_t, 3> sub2 = f64vec3_1 - f64vec3_2;
	f64vec3_1 -= f64vec3_2;

	for(std::size_t i = 0; i < 3; ++i) {
		EXPECT_FLOAT_EQ(sub1.elements[i], 0.0f);
		EXPECT_FLOAT_EQ(sub2.elements[i], 0.0);
		EXPECT_FLOAT_EQ(f64vec3_1.elements[i], 0.0);
	}
}

TEST_F(VecTemplateTest, SubtractionVectors5_int) {
	Vec<int32_t, 5> sub1 = i32vec5_1 - i32vec5_2;
	Vec<int64_t, 5> sub2 = i64vec5_1 - i64vec5_2;
	i64vec5_1 -= i64vec5_2;

	for(std::size_t i = 0; i < 5; ++i) {
		EXPECT_EQ(sub1.elements[i], 0);
		EXPECT_EQ(sub2.elements[i], 0);
		EXPECT_EQ(i64vec5_1.elements[i], 0);
	}
}

TEST_F(VecTemplateTest, SubtractionVectors5_float) {
	Vec<float32_t, 5> sub1 = f32vec5_1 - f32vec5_2;
	Vec<float64_t, 5> sub2 = f64vec5_1 - f64vec5_2;
	f64vec5_1 -= f64vec5_2;

	for(std::size_t i = 0; i < 5; ++i) {
		EXPECT_FLOAT_EQ(sub1.elements[i], 0.0f);
		EXPECT_FLOAT_EQ(sub2.elements[i], 0.0);
		EXPECT_FLOAT_EQ(f64vec5_1.elements[i], 0.0);
	}
}

TEST_F(VecTemplateTest, DotVectors3_int) {
	int32_t dot1 = i32vec3_1.Dot(i32vec3_2);
	int64_t dot2 = i64vec3_1.Dot(i64vec3_2);

	EXPECT_EQ(dot1, 3);
	EXPECT_EQ(dot2, 3);
}

TEST_F(VecTemplateTest, DotVectors3_float) {
	float32_t dot1 = f32vec3_1.Dot(f32vec3_2);
	float64_t dot2 = f64vec3_1.Dot(f64vec3_2);
	std::array<float64_t, 3> arr = {
		1.0, 3.0, -5.0
	};

	std::array<float64_t, 3> arr2 = {
		4.0, -2.0, -1.0
	};

	float64_t dot3 = Vec<float64_t, 3>(arr).Dot(Vec<float64_t, 3>(arr2));

	EXPECT_FLOAT_EQ(dot1, 3.0f);
	EXPECT_FLOAT_EQ(dot2, 3.0);
	EXPECT_FLOAT_EQ(dot3, 3.0);
}

TEST_F(VecTemplateTest, DotVectors5_int) {
	int32_t dot1 = i32vec5_1.Dot(i32vec5_2);
	int64_t dot2 = i64vec5_1.Dot(i64vec5_2);
	int64_t dot3 = Dot(i64vec5_1, i64vec5_2);

	EXPECT_EQ(dot1, 5);
	EXPECT_EQ(dot2, 5);
	EXPECT_EQ(dot3, 5);

}

TEST_F(VecTemplateTest, DotVectors5_float) {
	float32_t dot1 = f32vec5_1.Dot(f32vec5_2);
	float64_t dot2 = f64vec5_1.Dot(f64vec5_2);
	float64_t dot3 = Dot(f64vec5_1, f64vec5_2);


	EXPECT_FLOAT_EQ(dot1, 5.0f);
	EXPECT_FLOAT_EQ(dot2, 5.0);
	EXPECT_FLOAT_EQ(dot3, 5.0);

}

TEST_F(VecTemplateTest, ScalarDotVectors3_int) {
	Vec<int32_t, 3> r1 = i32vec3_1 * 3.1;
	Vec<int32_t, 3> r2 = 3 * i32vec3_1;

	Vec<int64_t, 3> r3 = 3.1 * i64vec3_1;
	Vec<int64_t, 3> r4 = i64vec3_1 * 3;
	i64vec3_1 *= 3.0;

	for(int i = 0; i < 3; ++i) {
		EXPECT_EQ(r1.elements[i], 3);
		EXPECT_EQ(r2.elements[i], 3);
		EXPECT_EQ(r3.elements[i], 3);
		EXPECT_EQ(r4.elements[i], 3);
		EXPECT_EQ(i64vec3_1.elements[i], 3);
	}
}

TEST_F(VecTemplateTest, ScalarDotVectors3_float) {
	Vec<float32_t, 3> r1 = f32vec3_1 * 3.1;
	Vec<float32_t, 3> r2 = 3 * f32vec3_1;

	Vec<float64_t, 3> r3 = 3.1 * f64vec3_1;
	Vec<float64_t, 3> r4 = f64vec3_1 * 3;

	f64vec3_1 *= 3.0;


	for(int i = 0; i < 3; ++i) {
		EXPECT_FLOAT_EQ(r1.elements[i], 3.1f);
		EXPECT_FLOAT_EQ(r2.elements[i], 3.0f);
		EXPECT_FLOAT_EQ(r3.elements[i], 3.1);
		EXPECT_FLOAT_EQ(r4.elements[i], 3.0);
		EXPECT_FLOAT_EQ(f64vec3_1.elements[i], 3.0);
	}
}

TEST_F(VecTemplateTest, ScalarDotVectors5_int) {
	Vec<int32_t, 5> r1 = i32vec5_1 * 3.1;
	Vec<int32_t, 5> r2 = 3 * i32vec5_1;

	Vec<int64_t, 5> r3 = i64vec5_1 * 3.1;
	Vec<int64_t, 5> r4 = 3 * i64vec5_1;

	for(int i = 0; i < 5; ++i) {
		EXPECT_EQ(r1.elements[i], 3);
		EXPECT_EQ(r2.elements[i], 3);
		EXPECT_EQ(r3.elements[i], 3);
		EXPECT_EQ(r4.elements[i], 3);

	}
}

TEST_F(VecTemplateTest, ScalarDotVectors5_float) {
	Vec<float32_t, 5> r1 = f32vec5_1 * 3.1;
	Vec<float32_t, 5> r2 = 3 * f32vec5_1;

	Vec<float64_t, 5> r3 = f64vec5_1 * 3.1;
	Vec<float64_t, 5> r4 = 3 * f64vec5_1;

	for(int i = 0; i < 5; ++i) {
		EXPECT_FLOAT_EQ(r1.elements[i], 3.1f);
		EXPECT_FLOAT_EQ(r2.elements[i], 3.0f);
		EXPECT_FLOAT_EQ(r3.elements[i], 3.1);
		EXPECT_FLOAT_EQ(r4.elements[i], 3.0);

	}
}

TEST_F(VecTemplateTest, LengthOfVectors) {
	int32_t l1 = i32vec5_1.Length();
	int64_t l2 = i64vec5_1.Length();

	float32_t l3 = f32vec5_1.Length();
	float64_t l4 = f64vec5_1.Length();

	EXPECT_EQ(l1, 2);
	EXPECT_EQ(l2, 2);
	EXPECT_NEAR(l3, 2.2360, 1e-4);
	EXPECT_NEAR(l4, 2.2360, 1e-4);
}

TEST_F(VecTemplateTest, SquaredLengthOfVectors) {
	int32_t l1 = i32vec5_1.SquaredLength();
	int64_t l2 = i64vec5_1.SquaredLength();

	float32_t l3 = f32vec5_1.SquaredLength();
	float64_t l4 = f64vec5_1.SquaredLength();

	EXPECT_EQ(l1, 5);
	EXPECT_EQ(l2, 5);
	EXPECT_FLOAT_EQ(l3, 5.0);
	EXPECT_FLOAT_EQ(l4, 5.0);
}

TEST_F(VecTemplateTest, MakeUnitVectors) {
	i32vec5_1.MakeUnit();
	i64vec5_1.MakeUnit();

	f32vec5_1.MakeUnit();
	f64vec5_1.MakeUnit();

	for(int i = 0; i < 5; ++i) {
		EXPECT_EQ(i32vec5_1.elements[i], 0);
		EXPECT_EQ(i64vec5_1.elements[i], 0);
		EXPECT_NEAR(f32vec5_1.elements[i], 0.4472, 1e-4);
		EXPECT_NEAR(f64vec5_1.elements[i], 0.4472, 1e-4);

	}
}


TEST_F(VecTemplateTest, MakeUnitVectors_function) {
	Vec<int32_t, 5> v1 = UnitVector(i32vec5_1);
	Vec<int64_t, 5> v2 = UnitVector(i64vec5_1);

	Vec<float32_t, 5> v3 = UnitVector(f32vec5_1);
	Vec<float64_t, 5> v4 = UnitVector(f64vec5_1);

	for(int i = 0; i < 5; ++i) {
		EXPECT_EQ(v1.elements[i], 0);
		EXPECT_EQ(v2.elements[i], 0);
		EXPECT_NEAR(v3.elements[i], 0.4472, 1e-4);
		EXPECT_NEAR(v4.elements[i], 0.4472, 1e-4);

	}
}

TEST_F(VecTemplateTest, StringStreamInput) {
	std::stringstream ss;
	ss << "1 2 3 4 5";

	Vec<float32_t, 5> v;

	ss >> v;

	EXPECT_EQ(v.elements[0], 1.0);
	EXPECT_EQ(v.elements[1], 2.0);
	EXPECT_EQ(v.elements[2], 3.0);
	EXPECT_EQ(v.elements[3], 4.0);
	EXPECT_EQ(v.elements[4], 5.0);

}

TEST_F(VecTemplateTest, StringStreamOutput) {
	std::stringstream ss;

	ss << i64vec3_1;

	EXPECT_STREQ(ss.str().c_str(), "1 1 1 ");
	ss.str(std::string());

	ss << f64vec3_1;

	EXPECT_STREQ(ss.str().c_str(), "1.00000 1.00000 1.00000 ");
}
