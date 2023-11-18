#include <gtest/gtest.h>

#include "sphere.hpp"
#include "hitable-list.hpp"

TEST(HitableListTest, Constructor) {
	HitableListType<float32_t> list;
	list.push_back(std::make_shared<Sphere<float32_t>>(Vec3<float32_t>({ 3.0f, 0.0f, 0.0f }), 5.0f));
	EXPECT_NO_THROW(HitableList<float32_t>(list));
}

TEST(HitableListTest, HitTheSphere) {
	HitableListType<float32_t> list;
	list.push_back(std::make_shared<Sphere<float32_t>>(Vec3<float32_t>({ 10.0f, 0.0f, 0.0f }), 5.0f));

	Ray<float32_t> r(
		Vec3<float32_t>({ 0.0f, 0.0f, 0.0f }),
		Vec3<float32_t>({ 1.0f, 0.0f, 0.0f })
	);

	Vec3<float32_t> norm({ -1.0f, 0.0f, 0.0f });
	Vec3<float32_t> hit_point({ 5.0f, 0.0f, 0.0f });

	HitRecord<float32_t> record;

	HitableList<float32_t> SUT(list);
	bool hit_anything = SUT.Hit(r, 0.0, MAXFLOAT, record);

	EXPECT_TRUE(hit_anything);
	for(std::size_t i = 0; i < 3; ++i) {
		EXPECT_FLOAT_EQ(record.normal[i], norm[i]);
		EXPECT_FLOAT_EQ(record.p[i], hit_point[i]);
	}
	EXPECT_FLOAT_EQ(record.t, 5.0f);
}


TEST(HitableListTest, HitNothing) {
	HitableListType<float32_t> list;
	list.push_back(std::make_shared<Sphere<float32_t>>(Vec3<float32_t>({ 10.0f, 0.0f, 0.0f }), 5.0f));

	Ray<float32_t> r(
		Vec3<float32_t>({ 0.0f, 0.0f, 0.0f }),
		Vec3<float32_t>({ -1.0f, 0.0f, 0.0f })
	);


	HitRecord<float32_t> record;

	HitableList<float32_t> SUT(list);
	bool hit_anything = SUT.Hit(r, 0.0, MAXFLOAT, record);

	EXPECT_FALSE(hit_anything);

}
