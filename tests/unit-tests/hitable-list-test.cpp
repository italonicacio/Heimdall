#include <gtest/gtest.h>

#include "hitable-list.hpp"
#include "sphere.hpp"


TEST(HitableListTest, Constructor) {
	HitableListType list;
	list.push_back(std::make_shared<Sphere>(Vec3({ 3.0, 0.0, 0.0 }), 5.0));
	EXPECT_NO_THROW(HitableList(list));
}

TEST(HitableListTest, HitTheSphere) {
	HitableListType list;
	list.push_back(std::make_shared<Sphere>(Vec3({ 10.0, 0.0, 0.0 }), 5.0));

	Ray r(
		Vec3({ 0.0f, 0.0f, 0.0f }),
		Vec3({ 1.0f, 0.0f, 0.0f })
	);

	Vec3 norm({ -1.0f, 0.0f, 0.0f });
	Vec3 hit_point({ 5.0f, 0.0f, 0.0f });

	HitRecord record;

	HitableList SUT(list);
	bool hit_anything = SUT.Hit(r, 0.0, MAXFLOAT, record);

	EXPECT_TRUE(hit_anything);
	for(std::size_t i = 0; i < 3; ++i) {
		EXPECT_FLOAT_EQ(record.normal[i], norm[i]);
		EXPECT_FLOAT_EQ(record.p[i], hit_point[i]);
	}
	EXPECT_FLOAT_EQ(record.t, 5.0f);
}


TEST(HitableListTest, HitNothing) {
	HitableListType list;
	list.push_back(std::make_shared<Sphere>(Vec3({ 10.0f, 0.0f, 0.0f }), 5.0f));

	Ray r(
		Vec3({ 0.0f, 0.0f, 0.0f }),
		Vec3({ -1.0f, 0.0f, 0.0f })
	);


	HitRecord record;

	HitableList SUT(list);
	bool hit_anything = SUT.Hit(r, 0.0, MAXFLOAT, record);

	EXPECT_FALSE(hit_anything);

}
