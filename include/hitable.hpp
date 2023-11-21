#pragma once

#include "ray.hpp"


struct HitRecord {
	Scalar t;
	Vec3 p;
	Vec3 normal;
};


class Hitable {
public:
	virtual bool Hit(const Ray& r, Scalar t_min, Scalar t_max, HitRecord& record) const = 0;
};
